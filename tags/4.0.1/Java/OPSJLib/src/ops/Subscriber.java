/**
*
* Copyright (C) 2006-2009 Anton Gravestam.
*
* This file is part of OPS (Open Publish Subscribe).
*
* OPS (Open Publish Subscribe) is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* OPS (Open Publish Subscribe) is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with OPS (Open Publish Subscribe).  If not, see <http://www.gnu.org/licenses/>.
*/
package ops;

import com.sun.org.apache.bcel.internal.generic.IFEQ;
import java.util.ArrayList;
import java.util.Observable;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.ReentrantLock;
import ops.protocol.OPSMessage;

/**
 *
 * @author Anton Gravestam
 */
public class Subscriber extends Observable 
{

    private Topic topic;
    private String identity = "";
    private ArrayList<FilterQoSPolicy> filterQoSPolicies = new ArrayList<FilterQoSPolicy>();
    private MessageFilterSet messageFilters = new MessageFilterSet();
    private ReentrantLock newDataLock = new ReentrantLock(true);
    private OPSObject data;
    private long deadlineTimeout;
    private long lastDeadlineTime;
    public Event deadlineEvent = new Event();
    private long timeLastDataForTimeBase;
    private long timeBaseMinSeparationTime;
    public static final int SHARED = 0;
    public static final int EXCLUSIVE = 1;
    private int threadPolicy = SHARED;
    private boolean reliable;
    private DataValidator dataValitator = new DefaultDataValidator();
    private TopicHandler topicHandler;
    private Participant participant;
    private OPSMessage message;

    public Subscriber(Topic t)
    {
        this.topic = t;
        this.participant = Participant.getInstance(topic.getDomainID(), topic.getParticipantID());
        topicHandler = participant.getTopicHandler(t);
    }

    public void setDeadlineQoS(long timeout)
    {
        deadlineTimeout = timeout;
    }

    public void setTimeBasedFilterQoS(long minSeparationTime)
    {
        timeBaseMinSeparationTime = minSeparationTime;
    }

    public void start()
    {

        lastDeadlineTime = System.currentTimeMillis();
        timeLastDataForTimeBase = System.currentTimeMillis();

        topicHandler.addSubscriber(this);

    }

    public boolean stop()
    {
        return topicHandler.removeSubscriber(this);
    }

    protected void checkDeadline()
    {
        if (System.currentTimeMillis() - lastDeadlineTime > deadlineTimeout)
        {
            deadlineEvent.fireEvent();
            lastDeadlineTime = System.currentTimeMillis();
        }

    }

    public boolean isReliable()
    {
        return reliable;
    }

    public String getIdentity()
    {
        return identity;
    }

//    public void setIdentity(String identity)
//    {
//        this.identity = identity;
//        if (subscriberHandler != null)
//        {
//            subscriberHandler.updateReliableIdentities();
//        }
//    }
    protected void notifyNewOPSObject(OPSObject o)
    {

        if (applyFilterQoSPolicies(o))
        {
            if (System.currentTimeMillis() - timeLastDataForTimeBase > timeBaseMinSeparationTime || timeBaseMinSeparationTime == 0)
            {
                lastDeadlineTime = System.currentTimeMillis();
                timeLastDataForTimeBase = System.currentTimeMillis();
                setChanged();
                data = o;//(OPSObject) o.clone();
                notifyObservers(data);

            }
        }
    }

    public OPSObject waitForNextData(long millis)
    {
        try
        {
            newDataLock.tryLock(millis, TimeUnit.MILLISECONDS);
            return data;
        }
        catch (InterruptedException ex)
        {
            return null;
        }
        finally
        {
            newDataLock.unlock();
        }
    }

    public void addFilterQoSPolicy(FilterQoSPolicy qosPolicy)
    {
        synchronized (this)
        {
            getFilterQoSPolicies().add(qosPolicy);
        }
    }

    public void removeFilterQoSPolicy(FilterQoSPolicy qosPolicy)
    {
        synchronized (this)
        {
            getFilterQoSPolicies().remove(qosPolicy);
        }
    }

    void notifyNewOPSMessage(OPSMessage message)
    {
        if(messageFilters.applyFilter(message))
        {
            this.message = message;
            notifyNewOPSObject(message.getData());
        }
    }

    private boolean applyFilterQoSPolicies(OPSObject o)
    {
        //throw new UnsupportedOperationException("Not yet implemented");
        for (FilterQoSPolicy filter : filterQoSPolicies)
        {
            if (!filter.applyFilter(o))
            {
                //Indicates that this data sample NOT should be delivered to the application.
                return false;
            }

        }
        return true;
    }

    public ArrayList<FilterQoSPolicy> getFilterQoSPolicies()
    {
        return filterQoSPolicies;
    }

    public int getThreadPolicy()
    {
        return threadPolicy;
    }

    public void setThreadPolicy(int threadPolicy)
    {
        this.threadPolicy = threadPolicy;
    }

    public DataValidator getDataValitator()
    {
        return dataValitator;
    }

    public void setDataValitator(DataValidator dataValitator)
    {
        this.dataValitator = dataValitator;
    }

    public OPSMessage getMessage()
    {
        return message;
    }
    

    public OPSObject getData()
    {
        return data;
    }

    public void removeFilter(MessageFilter filter)
    {
        messageFilters.removeFilter(filter);
    }

    public void addFilter(MessageFilter filter)
    {
        messageFilters.addFilter(filter);
    }

    public MessageFilterSet getMessageFilters()
    {
        return messageFilters;
    }





}
