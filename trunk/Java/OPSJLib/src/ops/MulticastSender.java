/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.NetworkInterface;

/**
 *
 * @author Anton Gravestam
 */
class MulticastSender implements Sender
{

    private MulticastSocket multicastSocket;

    public MulticastSender(int port, String localInterface, int ttl, int outSocketBufferSize) throws IOException
    {
        multicastSocket = new MulticastSocket(port);


        if (!localInterface.equals("0.0.0.0"))
        {//For some reason this method throws an error if we try to set outgoing interface to ANY.
            multicastSocket.setNetworkInterface(NetworkInterface.getByInetAddress(Inet4Address.getByName(localInterface)));
        }

        if (outSocketBufferSize > 0)
        {
            multicastSocket.setSendBufferSize(outSocketBufferSize);
        }
        multicastSocket.setTimeToLive(1);


    }
    public boolean sendTo(byte[] bytes, int offset, int size, String ip, int port)
    {
        try
        {
            InetAddress ipAddress = InetAddress.getByName(ip);
            DatagramPacket datagramPacket = new DatagramPacket(bytes, offset, size, ipAddress, port);

            multicastSocket.send(datagramPacket);

            return true;
        } catch (IOException ex)
        {
            return false;
        }

    }

    public boolean sendTo(byte[] bytes, String ip, int port)
    {
        return sendTo(bytes, 0, bytes.length, ip, port);

    }
}
