/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

/**
 *
 * @author Anton Gravestam
 */
class ReceiverFactory
{
    static Receiver createReceiver(Topic topic, String localInterface)
    {
        if(topic.getTransport().equals(Topic.TRANSPORT_MC))
        {
            return new MulticastReceiver(topic.getDomainAddress(), topic.getPort(), localInterface, topic.getInSocketBufferSize());
        }
        return null;
    }

}
