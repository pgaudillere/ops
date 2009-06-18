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
