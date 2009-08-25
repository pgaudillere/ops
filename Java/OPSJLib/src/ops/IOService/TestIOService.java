/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops.IOService;

import java.io.IOException;
import java.nio.channels.DatagramChannel;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author angr
 */
public class TestIOService
{

    public static void main(String[] args)
    {
        try
        {
            IOService ioService = new IOService("Test IO Service");

            DatagramChannel channel = DatagramChannel.open();
            //channel.



        } catch (IOException ex)
        {
            Logger.getLogger(TestIOService.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

}
