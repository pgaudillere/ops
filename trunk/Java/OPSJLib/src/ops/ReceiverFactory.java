/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Anton Gravestam
 */
class ReceiverFactory
{
    static Receiver createReceiver(Topic topic, String localInterface)
    {
        try
        {
            if (topic.getTransport().equals(Topic.TRANSPORT_MC))
            {
                return new MulticastReceiver(topic.getDomainAddress(), topic.getPort(), localInterface, topic.getInSocketBufferSize());
            }
            else if (topic.getTransport().equals(Topic.TRANSPORT_TCP))
            {
                return new TcpClient(topic.getDomainAddress(), topic.getPort(), topic.getInSocketBufferSize());
            }

        }
        catch (IOException ex)
        {
            Logger.getLogger(ReceiverFactory.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }
}
