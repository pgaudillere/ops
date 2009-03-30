/*
 * StaticManager.java
 *
 * Created on den 3 februari 2007, 11:44
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;

import java.io.IOException;
import java.util.Vector;
import org.xml.sax.SAXException;

/**
 *
 * @author Owe
 */
public class StaticManager
{
    public static final int MAX_SIZE = 65000;

    static void handleMulticastSendError()
    {
        System.out.println("Possible loss of IP-address");
    }
    private Vector<Topic> topics;
    private static StaticManager theManager;
    protected static String BASE_ADDRESS;
    public static int DEFAULT_DISOVERY_PORT = 39000;
    /** Creates a new instance of StaticManager */
    public StaticManager(String fileName)
    {
        XMLConfigLoader loader = null;
        try
        {
            loader = new XMLConfigLoader(fileName);
            topics = loader.getTopics();
            BASE_ADDRESS = loader.getBaseAddress();
        } 
        catch (SAXException ex)
        {
            ex.printStackTrace();
        } 
        catch (IOException ex)
        {
            ex.printStackTrace();
        }
        
    }
    public static StaticManager initializeManager(String fileName)
    {
        //Ice.Communicator communicator = Ice.Util.initialize();
        if(theManager == null)
            theManager = new StaticManager(fileName);
        
        return theManager;
    }
    public static StaticManager reInitializeManager(String fileName)
    {
        //Ice.Communicator communicator = Ice.Util.initialize();
        
        theManager = new StaticManager(fileName);
        
        return theManager;
    }
    
    public static StaticManager getManager()
    {
        if(theManager == null)
            return null;
        
        return theManager;
    }

    public Vector<Topic> getTopics()
    {
        return topics;
    }

    public int getTopicPort(String topicKey)
    {
        for (Topic t : topics)
        {
            if(t.getName().equals(topicKey))
                return t.getPort();
            
        }
        return -1;
    }

    public Topic getTopic(String string)
    {
        for(Topic t : topics)
        {
            if(t.getName().equals(string))
                return t;
        }
        return null;
    }
    
    
    
}
