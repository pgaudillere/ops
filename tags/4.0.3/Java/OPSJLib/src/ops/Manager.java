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

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.UnknownHostException;
import java.util.TreeMap;
import java.util.Vector;
import ops.*;

/**
 *
 * @author Anton
 */
public class Manager implements Runnable
{
    private static Manager theManager;
    
    
    public static int MAX_SIZE = 65000;
    public static int MANAGER_PORT = 14000;
    public static int TOPIC_BASE_PORT = 14001;
    public static String handShake =":-) ";
    
    
    private MulticastSocket multicastSocket;
    
    private Vector<Topic> topics = new Vector<Topic>();
    
    private byte[] readBytes;
    
    private Thread thread;
    
    /** Creates a new instance of Manager */
    private Manager()
    {
        try
        {
            multicastSocket = new MulticastSocket(MANAGER_PORT);
            multicastSocket.joinGroup(InetAddress.getByName("235.5.5.5"));
            sendHandShake();
        }
        catch (UnknownHostException ex)
        {
            ex.printStackTrace();
        }
        catch (IOException ex)
        {
            ex.printStackTrace();
        }
        
        thread = new Thread(this);
        thread.start();
        try
        {
            System.out.println("Handshaking...");
            Thread.sleep(1000);
            System.out.println("Handshaking done.");
        }
        catch (InterruptedException ex)
        {
            ex.printStackTrace();
        }
        
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
    
    //By singelton pattern
    public static Manager getManager()
    {
        if(theManager == null)
            theManager = new Manager();
        
        return theManager;
    }
    
    public void run()
    {
        while(true)
        {
            
            readBytes = new byte[Manager.MAX_SIZE];
            
            DatagramPacket p = new DatagramPacket(readBytes, Manager.MAX_SIZE);
            try
            {
                multicastSocket.receive(p);
                
                String s = new String(p.getData());
                String[] sArray = s.split(" ");
                
                if(sArray[0].equals(":-)"))
                {
                    sendTopics();
                }
                else if(sArray[0].equals("&"))
                {
                    
                    
                    if(getTopicPort(sArray[1]) == -1)
                    {
                        //topics.add(new Topic(sArray[1], Integer.parseInt(sArray[2])));
                        System.out.println("Topic " + sArray[1] + " updated at port " + getTopicPort(sArray[1]));
                        
                    }
                    
                }
                else
                {
                    
                    if(getTopicPort(sArray[0]) != -1)
                    {
                        System.out.println("Topic " + sArray[0] + " found at port " + getTopicPort(sArray[0]));
                    }
                    else
                    {
                        //topics.add(new Topic(sArray[0], TOPIC_BASE_PORT + topics.size()));
                        System.out.println("Topic " + sArray[0] + " registered at port " + (TOPIC_BASE_PORT + topics.size()-1));
                    }
                }
                
            }
            catch (IOException ex)
            {
                ex.printStackTrace();
            }
            catch (ArrayIndexOutOfBoundsException e)
            {
                System.out.println("Topic refused");
                e.printStackTrace();
                
            }
        }
    }
    
    private void sendHandShake()
    {
        
        try
        {
            multicastSocket.send(new DatagramPacket(handShake.getBytes(), handShake.length(),InetAddress.getByName("235.5.5.5"),Manager.MANAGER_PORT));
        }
        catch (IOException ex)
        {
            ex.printStackTrace();
        }
    }
    private void sendTopics()
    {
        for(Topic t : topics)
        {
            String message = "& " + t.getName() + " " + t.getPort() + " ";
            
            try
            {
                multicastSocket.send(new DatagramPacket(message.getBytes(), message.length(),InetAddress.getByName("235.5.5.5"),Manager.MANAGER_PORT));
            }
            catch (IOException ex)
            {
                ex.printStackTrace();
            }
        }
        
    }
    
    public void registerSubscriber(String topic)
    {
        if(getTopicPort(topic) == -1)
        {
            registerTopic(topic);
        }
    }
    public void registerPublisher(String topic)
    {
        if(getTopicPort(topic) == -1)
        {
            registerTopic(topic);
        }
    }
    
    
    private void registerTopic(String topic)
    {
        try
            {
                multicastSocket = new MulticastSocket(Manager.MANAGER_PORT);
                multicastSocket.joinGroup(InetAddress.getByName("235.5.5.5"));
            }
            catch (UnknownHostException ex)
            {
                ex.printStackTrace();
            }
            catch (IOException ex)
            {
                ex.printStackTrace();
            }
            
            String managerString = topic + " " + "TestClass" + " ";//data.getClass().getName();
            try
            {
                multicastSocket.send(new DatagramPacket(managerString.getBytes(), managerString.length(),InetAddress.getByName("235.5.5.5"),Manager.MANAGER_PORT));
            }
            catch (IOException ex)
            {
                ex.printStackTrace();
            }
    }
    
}
