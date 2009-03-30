/*
 * MulticastTransport.java
 *
 * Created on den 11 maj 2007, 19:20
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.NoRouteToHostException;
import java.net.SocketException;
import java.net.SocketTimeoutException;

/**
 *
 * @author Anton Gravestam
 */
public class MulticastTransport implements Transport
{
    private MulticastSocket multicastSocket;
    int port;
    InetAddress ipAddress;
    private Event newBytesEvent = new Event();
    /** Creates a new instance of MulticastTransport */
    public MulticastTransport(String ip, int port)
    {
        try
        {
            ipAddress = InetAddress.getByName(ip);
            this.port = port;
            //multicastSocket = new MulticastSocket();
            multicastSocket = new MulticastSocket(port);
            try
            {
                setReceiveTimeout(100);
            } catch (CommException ex)
            {
                //Logger.getLogger(MulticastTransport.class.getName()).log(Level.SEVERE, null, ex);
            }
            
            //multicastSocket.setReuseAddress(true);
            //multicastSocket.bind(new InetSocketAddress(port));
            multicastSocket.setTimeToLive(1);
            multicastSocket.joinGroup(ipAddress);
        }
        catch (IOException ex)
        {
            ex.printStackTrace();
        }
        
    }

    public boolean receive(byte[] b) //throws ReceiveTimedOutException
    {
        //byte[] b = new byte[StaticManager.MAX_SIZE];
        DatagramPacket p = new DatagramPacket(b, b.length);
        try
        {
            multicastSocket.receive(p);
            newBytesEvent.fireEvent(b);
            return true;
        }
        catch (SocketTimeoutException ex)
        {
            return false;
        }
        catch (IOException ex)
        {
            return false;
        }
        //return false;
    }

    public void send(byte[] b)
    {
        try
        {
            
            multicastSocket.send(new DatagramPacket(b, b.length, ipAddress,this.port));
            //multicastSocket.send(new DatagramPacket("snopp".getBytes(), "snopp".getBytes().length, ipAddress,this.port));
        }
        catch(NoRouteToHostException nrte)
        {
            Participant.getParticipant().handleMulticastNotAvailableError();
        }
        catch (IOException ex)
        {
            Participant.getParticipant().handleMulticastNotAvailableError();
            //ex.printStackTrace();
        }
        
    }

    public void setReceiveTimeout(int millis) throws CommException
    {
        try
        {
            multicastSocket.setSoTimeout(millis);
        }
        catch (SocketException ex)
        {
            throw new CommException("Relayed exception from SocketException --> " + ex.getMessage());
        }
    }

    public Event getNewBytesEvent()
    {
        return newBytesEvent;
    }
    
}
