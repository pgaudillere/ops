/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops;

import java.io.IOException;
import java.net.MulticastSocket;
import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author Anton
 */
class MulticastSocketCreator
{
    private static Map<Integer, MulticastSocket> sockets = new HashMap<Integer, MulticastSocket>();
    static synchronized MulticastSocket getMulticastSocket(int port) throws IOException
    {
        if(sockets.containsKey(port))
        {
            return sockets.get(port);
        }
        MulticastSocket newSocket = new MulticastSocket(port);
        //newSocket.setLoopbackMode(true);
        
        sockets.put(port, newSocket);
        return newSocket;
    }
}
