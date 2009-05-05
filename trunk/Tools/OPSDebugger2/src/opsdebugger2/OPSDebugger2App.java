/*
 * OPSDebugger2App.java
 */
package opsdebugger2;

import configlib.exception.FormatException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.HashMap;
import java.util.Timer;
import java.util.TimerTask;
import java.util.logging.Level;
import java.util.logging.Logger;
import opsdebugger2.proxy.TopicSubscriberProxy;
import opsreflection.OPSFactory;
import org.jdesktop.application.Application;
import org.jdesktop.application.SingleFrameApplication;

/**
 * The main class of the application.
 */
public class OPSDebugger2App extends SingleFrameApplication
{
    private static TopicSubscriberProxy activeSub;
    private static OPSFactory opsFactory;
    private static HashMap<String,OPSFactory> opsFactoryInstances = new HashMap<String, OPSFactory>();

    public static void setActiveSubscriberProxy(TopicSubscriberProxy prx)
    {
        activeSub = prx;
    }
    public static String domain = "";
    public static OPSFactory getOPSFactory()
    {
        if(!opsFactoryInstances.containsKey(domain))
        {
            try
            {
                try
                {
                    opsFactoryInstances.put(domain, new OPSFactory(new File("OPSReflectionConfig.xml")));
                } catch (FormatException ex)
                {
                    Logger.getLogger(OPSDebugger2App.class.getName()).log(Level.SEVERE, null, ex);
                }
            } catch (FileNotFoundException ex)
            {
                Logger.getLogger(OPSDebugger2App.class.getName()).log(Level.SEVERE, null, ex);
            } catch (IOException ex)
            {
                Logger.getLogger(OPSDebugger2App.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        return opsFactoryInstances.get(domain);
    }

    /**
     * At startup create and show the main frame of the application.
     */
    @Override
    protected void startup()
    {
        activeSub = null;
        show(new OPSDebugger2View(this));
    }

    /**
     * This method is to initialize the specified window by injecting resources.
     * Windows shown in our application come fully initialized from the GUI
     * builder, so this additional configuration is not needed.
     */
    @Override
    protected void configureWindow(java.awt.Window root)
    {
    }

    /**
     * A convenient static getter for the application instance.
     * @return the instance of OPSDebugger2App
     */
    public static OPSDebugger2App getApplication()
    {
        return Application.getInstance(OPSDebugger2App.class);
    }
    
    public static TopicSubscriberProxy getActiveSubscriberProxy()
    {
        return activeSub;
        
    }

    /**
     * Main method launching the application.
     */
    public static void main(String[] args)
    {
        Timer gcTimer = new Timer();
        gcTimer.scheduleAtFixedRate(new TimerTask() {

            @Override
            public void run()
            {
                System.gc();
            }
        }, 5000, 1000);
        launch(OPSDebugger2App.class, args);
    }
}
