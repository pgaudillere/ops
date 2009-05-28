/*
 * OPSDebugger2App.java
 */
package opsdebugger2;

import java.awt.Color;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.UIManager;
import javax.swing.UIManager.LookAndFeelInfo;
import javax.swing.UnsupportedLookAndFeelException;
import opsdebugger2.proxy.TopicSubscriberProxy;
import opsreflection.OPSFactory;
import org.jdesktop.application.Application;
import org.jdesktop.application.SingleFrameApplication;

/**
 * The main class of the application.
 */
public class OPSDebugger2App extends SingleFrameApplication
{

    private TopicSubscriberProxy activeSub;
    private OPSFactory opsFactory;
    private OPSDebugger2View mainFrame;
    //private HashMap<String,OPSFactory> opsFactoryInstances = new HashMap<String, OPSFactory>();
    private DebuggerProject activeProject;

    public DebuggerProject getActiveProject()
    {
        return activeProject;
    }

    public void setActiveProject(DebuggerProject debuggerProject)
    {
        mainFrame.getFrame().setTitle(debuggerProject.getName());

        activeProject = debuggerProject;
        mainFrame.getTreeView().updateTopics();
    }

    public void setActiveSubscriberProxy(TopicSubscriberProxy prx)
    {

        activeSub = prx;
    }

    /**
     * At startup create and show the main frame of the application.
     */
    @Override
    protected void startup()
    {
        activeSub = null;
        mainFrame = new OPSDebugger2View(this);
        show(mainFrame);
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

    public TopicSubscriberProxy getActiveSubscriberProxy()
    {
        return activeSub;

    }

    /**
     * Main method launching the application.
     */
    public static void main(String[] args)
    {
//        Timer gcTimer = new Timer();
//        gcTimer.scheduleAtFixedRate(new TimerTask() {
//
//            @Override
//            public void run()
//            {
//                System.gc();
//            }
//        }, 5000, 1000);

        UIManager.put("nimbusBase", Color.BLACK);
        UIManager.put("desktop", Color.black);
        UIManager.put("nimbusBlueGrey", Color.black);
        UIManager.put("control", Color.darkGray);
        UIManager.put("controlText", Color.white);
        UIManager.put("nimbusFocus", Color.darkGray);
        UIManager.put("text", Color.white);
        UIManager.put("textHighLightText", Color.white);
        UIManager.put("nimbusLightBackground", Color.gray);

        for (LookAndFeelInfo laf : UIManager.getInstalledLookAndFeels())
        {
            if ("Nimbus".equals(laf.getName()))
            {
                try
                {
                    UIManager.setLookAndFeel(laf.getClassName());
                } catch (ClassNotFoundException ex)
                {

                } catch (InstantiationException ex)
                {

                } catch (IllegalAccessException ex)
                {

                } catch (UnsupportedLookAndFeelException ex)
                {

                }
            }
        }

        launch(OPSDebugger2App.class, args);
    }
    
}
