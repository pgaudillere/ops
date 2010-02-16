/**
*
* Copyright (C) 2006-2010 Anton Gravestam.
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
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Anton Gravestam
 */
public class TcpServerSender implements Sender, Runnable
{
    private final String serverIp;
    private final int serverPort;
    private volatile boolean run;
    private final ServerSocket server;
    private TcpSenderList tcpSenderList;

    public TcpServerSender(String serverIp, int serverPort) throws IOException
    {
        this.serverIp = serverIp;
        this.serverPort = serverPort;
        server = new ServerSocket(serverPort, 0, InetAddress.getByName(serverIp));
        tcpSenderList = new TcpSenderList();
        new Thread(this).start();
    }


    public boolean sendTo(byte[] bytes, String ip, int port)
    {
        return sendTo(bytes, 0, bytes.length, ip, port);
    }

    public boolean sendTo(byte[] bytes, int offset, int size, String ip, int port)
    {
        try
        {
            return sendTo(bytes, offset, size, InetAddress.getByName(ip), port);
        } catch (UnknownHostException ex)
        {
            Logger.getLogger(TcpServerSender.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }

    }

    public boolean sendTo(byte[] bytes, int offset, int size, InetAddress ipAddress, int port)
    {
        return tcpSenderList.sendTo(bytes, offset, size, ipAddress, port);
    }

    public void run()
    {
        run = true;
        while(run)
        {
            try
            {
                Socket socket = server.accept();
                tcpSenderList.add(socket);


            } catch (IOException ex)
            {
                Logger.getLogger(TcpServerSender.class.getName()).log(Level.SEVERE, null, ex);
                
            }

        }
        
    }

}
