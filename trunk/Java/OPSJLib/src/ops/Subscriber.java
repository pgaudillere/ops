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
    public Event deadlineEvent = new Event();

    private Topic topic;
    private String identity = "";
    private ArrayList<FilterQoSPolicy> filterQoSPolicies = new ArrayList<FilterQoSPolicy>();
    private MessageFilterSet messageFilters = new MessageFilterSet();
    private final Object newDataEvent = new Object();
    private OPSObject data;
    private long deadlineTimeout;
    private long lastDeadlineTime;
    private long timeLastDataForTimeBase;
    private long timeBaseMinSeparationTime;
    private boolean reliable;
    private ReceiveDataHandler receiveDataHandler;
    protected Participant participant;
    private OPSMessage message;
    private final DeadlineNotifier deadlineNotifier;

    public Subscriber(Topic t)
    {
        this.topic = t;
        this.participant = Participant.getInstance(topic.getDomainID(), topic.getParticipantID());
        receiveDataHandler = participant.getReceiveDataHandler(t);
        deadlineNotifier = DeadlineNotifier.getInstance();
    }

    public synchronized void setDeadlineQoS(long timeout)
    {
        deadlineTimeout = timeout;
    }

    public synchronized void setTimeBasedFilterQoS(long minSeparationTime)
    {
        timeBaseMinSeparationTime = minSeparationTime;
    }

    public synchronized void start()
    {

        lastDeadlineTime = System.currentTimeMillis();
        timeLastDataForTimeBase = System.currentTimeMillis();

        deadlineNotifier.add(this);
        receiveDataHandler.addSubscriber(this);

    }

    public synchronized boolean stop()
    {
        deadlineNotifier.remove(this);
        return receiveDataHandler.removeSubscriber(this);
    }
    public synchronized boolean isDeadlineMissed()
    {
        if (System.currentTimeMillis() - lastDeadlineTime > deadlineTimeout)
        {
            return true;
        }
        return false;
    }

    protected synchronized void checkDeadline()
    {
        if (System.currentTimeMillis() - lastDeadlineTime > deadlineTimeout)
        {
            deadlineEvent.fireEvent();
            lastDeadlineTime = System.currentTimeMillis();
        }

    }

    public synchronized boolean isReliable()
    {
        return reliable;
    }

    public synchronized String getIdentity()
    {
        return identity;
    }

    protected synchronized void notifyNewOPSObject(OPSObject o)
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
                synchronized(newDataEvent)
                {
                    newDataEvent.notifyAll();
                }

            }
        }
    }

    public OPSObject waitForNextData(long millis)
    {
        try
        {
            synchronized(newDataEvent)
            {
                newDataEvent.wait(millis);
            }
            return data;
        }
        catch (InterruptedException ex)
        {
            return null;
        }
       
    }

    public synchronized void addFilterQoSPolicy(FilterQoSPolicy qosPolicy)
    {
        synchronized (this)
        {
            getFilterQoSPolicies().add(qosPolicy);
        }
    }

    public synchronized void removeFilterQoSPolicy(FilterQoSPolicy qosPolicy)
    {
        synchronized (this)
        {
            getFilterQoSPolicies().remove(qosPolicy);
        }
    }

    synchronized void notifyNewOPSMessage(OPSMessage message)
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

    public synchronized ArrayList<FilterQoSPolicy> getFilterQoSPolicies()
    {
        return filterQoSPolicies;
    }

    public synchronized OPSMessage getMessage()
    {
        return message;
    }
    

    protected synchronized OPSObject getData()
    {
        return data;
    }

    public synchronized void removeFilter(MessageFilter filter)
    {
        messageFilters.removeFilter(filter);
    }

    public synchronized void addFilter(MessageFilter filter)
    {
        messageFilters.addFilter(filter);
    }

    public synchronized MessageFilterSet getMessageFilters()
    {
        return messageFilters;
    }





}
