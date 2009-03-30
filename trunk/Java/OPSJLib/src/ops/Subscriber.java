
package ops;

import ops.protocol.DataHeader;
import java.io.IOException;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.Observable;
import java.util.UUID;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.ReentrantLock;
import java.util.logging.Level;
import java.util.logging.Logger;
import ops.archiver.OPSArchiverIn;
import ops.protocol.OPSMessage;

/**
 *
 * @author Anton Gravestam
 */
public class Subscriber extends Observable implements Runnable
{
    private Topic topic;
    private String identity = "";
    
    private ArrayList<FilterQoSPolicy> filterQoSPolicies = new ArrayList<FilterQoSPolicy>();
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
    private Transport transport;
    private Thread thread;
    private DataHeader dataHeader = new DataHeader();
    private TopicHandler topicHandler;
    private OPSMessage currentMessage;
    //private DataHeaderHelper dataHeaderHelper = new DataHeaderHelper();



    public Subscriber(Topic t)
    {
        this.topic = t;
        //newDataLock.lock();
        transport = new MulticastTransport(t.getDomainAddress(), t.getPort());
        thread = new Thread(this);
        topicHandler = TopicHandler.getTopicHandler(t);
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
//        try
//        {
            lastDeadlineTime = System.currentTimeMillis();
            timeLastDataForTimeBase = System.currentTimeMillis();

            topicHandler.addSubscriber(this);


//            if(threadPolicy == SHARED)
//            {
//                subscriberHandler = SubscriberHandler.getDefaultSubscriberHandler(topic, objectHelper);
//            }
//            else if(threadPolicy == EXCLUSIVE)
//            {
//                subscriberHandler = SubscriberHandler.getExclusiveSubscriberHandler(topic, objectHelper);
//            }
//
//            subscriberHandler.addSubscriber(this);
//            subscriberHandler.updateReliableIdentities();
            //thread.start();



//        }
//
//        catch (SocketException ex)
//        {
//            Logger.getLogger(Subscriber.class.getName()).log(Level.SEVERE, null, ex);
//        }
//        catch (UnknownHostException ex)
//        {
//            Logger.getLogger(Subscriber.class.getName()).log(Level.SEVERE, null, ex);
//        }
        
    }

   public boolean stop()
   {
       return topicHandler.removeSubscriber(this);
   }
   

    protected void checkDeadline()
    {
        if(System.currentTimeMillis() - lastDeadlineTime > deadlineTimeout)
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
        if(applyFilterQoSPolicies(o))
        {
            if(System.currentTimeMillis() - timeLastDataForTimeBase > timeBaseMinSeparationTime || timeBaseMinSeparationTime == 0)
            {
                lastDeadlineTime = System.currentTimeMillis();
                timeLastDataForTimeBase = System.currentTimeMillis();
                setChanged();
                data = o;//(OPSObject) o.clone();
                notifyObservers(data);
                //newDataLock.unlock();
                //newDataLock.lock();
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
        currentMessage = message;
        notifyNewOPSObject(message.getData());
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

    public OPSObject getData()
    {
        return data;
    }

    public void run()
    {
//        while(true)
//        {
//            try
//            {
//                byte[] bytes = transport.receive();
//                if(bytes != null)
//                {
//                    OPSArchiverIn archiverIn = new OPSArchiverIn(bytes);
//                    OPSMessage message = null;
//                    message = (OPSMessage) archiverIn.inout("message", message);
//                    notifyNewOPSObject(message.getData());
//                }
//            }
//            catch (IOException ex)
//            {
//                Logger.getLogger(Subscriber.class.getName()).log(Level.SEVERE, null, ex);
//                ex.printStackTrace();
//            }
//            catch (ReceiveTimedOutException ex)
//            {
//                //Silent shout!
//                ex.printStackTrace();
//            }
//        }
    }
    
    
    
    
}
