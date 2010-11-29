/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.IOService;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.net.DatagramSocketImpl;
import java.net.NetworkInterface;
import java.net.SocketAddress;
import java.nio.channels.DatagramChannel;

/**
 *
 * @author angr
 */
public class MulticastEnableDatagramChannel
{

    boolean enableMulticast(DatagramChannel channel, SocketAddress socketAddress, NetworkInterface networkInterface)
    {
        // UGLY UGLY HACK: multicast support for NIO
        // create a temporary instanceof PlainDatagramSocket, set its fd and configure it
        try
        {
            Constructor<? extends DatagramSocketImpl> c =
                    (Constructor<? extends DatagramSocketImpl>) Class.forName("java.net.PlainDatagramSocketImpl").getDeclaredConstructor();
            c.setAccessible(true);
            DatagramSocketImpl socketImpl = c.newInstance();

            Field channelFd = Class.forName("sun.nio.ch.DatagramChannelImpl").getDeclaredField("fd");
            channelFd.setAccessible(true);

            Field socketFd = DatagramSocketImpl.class.getDeclaredField("fd");
            socketFd.setAccessible(true);
            socketFd.set(socketImpl, channelFd.get(channel));

            try
            {
                Method m = DatagramSocketImpl.class.getDeclaredMethod("joinGroup", SocketAddress.class, NetworkInterface.class);
                m.setAccessible(true);
                m.invoke(socketImpl, socketAddress, networkInterface);
                return true;
            } finally
            {
                // important, otherwise the fake socket's finalizer will nuke the fd
                socketFd.set(socketImpl, null);
            }
        } catch (ClassNotFoundException classNotFoundException)
        {
        } catch (NoSuchMethodException noSuchMethodException)
        {
        } catch (SecurityException securityException)
        {
        } catch (InstantiationException instantiationException)
        {
        } catch (IllegalAccessException illegalAccessException)
        {
        } catch (IllegalArgumentException illegalArgumentException)
        {
        } catch (InvocationTargetException invocationTargetException)
        {
        } catch (NoSuchFieldException noSuchFieldException)
        {
        }

        return false;
    }
}
