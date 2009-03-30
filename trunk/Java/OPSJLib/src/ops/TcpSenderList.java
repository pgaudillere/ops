/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops;

import java.io.IOException;
import java.net.Socket;
import java.util.Vector;

/**
 *
 * @author angr
 */
public class TcpSenderList
{
    Vector<Socket> senders = new Vector<Socket>();

    public boolean remove(Object o)
    {
        return senders.remove(o);
    }

    public boolean add(Socket e)
    {
        return senders.add(e);
    }
    
    public void sendTo(byte[] bytes, String ip, int port) throws IOException
    {
        
        for (Socket s : senders)
        {
            if(s.getInetAddress().getHostAddress().equals(ip) && s.getPort() == port)
            {
                s.getOutputStream().write(bytes);
            }
            
        }

    }

    void remove(String ip, int port) throws IOException
    {
        for (int i = 0 ; i < senders.size() ; i++)
        {
            if(senders.get(i).getInetAddress().getHostAddress().equals(ip) && senders.get(i).getPort() == port)
            {
                senders.get(i).close();
                senders.remove(i);
            }
            
        }
    }
    
    
}
