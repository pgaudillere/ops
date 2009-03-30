/*
 * DeadlineMissedFilterQoSPolicy.java
 *
 * Created on den 10 oktober 2007, 15:19
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;

import java.util.Observable;
import java.util.Observer;
import java.util.Timer;
import java.util.TimerTask;

/**
 *
 * @author angr
 */
public class DeadlineMissedFilterQoSPolicy extends Observable implements FilterQoSPolicy, Runnable
{
    
    long maxSeparation;

    private boolean stopped = false;
    boolean newUpdate = false;
    
    /** Creates a new instance of DeadlineMissedFilterQoSPolicy */
    public DeadlineMissedFilterQoSPolicy(long maxSeparation)
    {
        this.maxSeparation = maxSeparation;
        
        Thread t = new Thread(this);
        t.start();
        
        
        
    }
    
    public boolean applyFilter(OPSObject o)
    {
        newUpdate = true;
        return true;
    }
    public void stop()
    {
        stopped = true;
    }

    public void run()
    {
        try
        {
            while(!stopped)
            {
                Thread.sleep(maxSeparation);
                if(!newUpdate)
                {
                    setChanged();
                    notifyObservers();   
                }
                newUpdate = false;
                
            }
        } 
        catch (InterruptedException ex)
        {
            ex.printStackTrace();
            
        }
    }
    

    
    
    
    
}

