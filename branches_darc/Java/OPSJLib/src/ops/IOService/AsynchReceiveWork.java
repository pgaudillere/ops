/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops.IOService;

import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;

/**
 *
 * @author angr
 */
public class AsynchReceiveWork
{
    final ByteBuffer buf; //The buffer to put the bytes in
    final AsynchReceiveCallback callback; //The callback to be used when work can be performed
    final SelectionKey selectionKey;

    public AsynchReceiveWork(ByteBuffer buf, SelectionKey selectionKey, AsynchReceiveCallback callback)
    {
        this.buf = buf;
        this.callback = callback;
        this.selectionKey = selectionKey;
    }

}
