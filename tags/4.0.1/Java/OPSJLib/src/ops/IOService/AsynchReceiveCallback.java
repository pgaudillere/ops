/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.IOService;

import java.net.DatagramPacket;
import java.nio.ByteBuffer;

/**
 *
 * @author angr
 */
public interface AsynchReceiveCallback
{
    public void handle(IOService ioService, ByteBuffer buf);
}
