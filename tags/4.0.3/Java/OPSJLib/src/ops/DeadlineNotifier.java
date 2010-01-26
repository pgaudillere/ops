/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops;

import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.naming.spi.DirStateFactory.Result;

/**
 *
 * @author Anton
 */
public class DeadlineNotifier extends Thread
{

    private static DeadlineNotifier theInstance;

    public static synchronized DeadlineNotifier getInstance()
    {
        if (theInstance == null)
        {
            theInstance = new DeadlineNotifier();
            theInstance.start();
        }
        return theInstance;
    }
    Vector<Subscriber> subscribers = new Vector<Subscriber>();
    private volatile boolean keepRunning;

    public DeadlineNotifier()
    {
    }

    public synchronized boolean remove(Subscriber o)
    {
        boolean result = subscribers.remove(o);
        if (subscribers.size() == 0)
        {
            stopRunning();
            theInstance = null;
        }
        return result;
    }

    public synchronized boolean add(Subscriber e)
    {
        return subscribers.add(e);
    }

    public void stopRunning()
    {
        keepRunning = false;
    }

    @Override
    public void run()
    {
        keepRunning = true;
        while (keepRunning)
        {
            try
            {
                synchronized (this)
                {
                    for (Subscriber subscriber : subscribers)
                    {
                        subscriber.checkDeadline();
                    }
                }
                Thread.sleep(5);
            } catch (InterruptedException ex)
            {
                Logger.getLogger(DeadlineNotifier.class.getName()).log(Level.SEVERE, null, ex);
            }

        }
    }
}
