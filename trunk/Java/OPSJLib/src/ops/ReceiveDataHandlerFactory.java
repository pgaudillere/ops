/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

import java.util.HashMap;

/**
 *
 * @author Anton Gravestam
 */
class ReceiveDataHandlerFactory
{
    private HashMap<String, ReceiveDataHandler> multicastReceiveDataHandlers = new HashMap<String, ReceiveDataHandler>();

    ReceiveDataHandler getReceiveDataHandler(Topic top, Participant participant)
    {
        if(top.getTransport().equals(Topic.TRANSPORT_MC))
        {
            if (!multicastReceiveDataHandlers.containsKey(top.getName()))
            {
                multicastReceiveDataHandlers.put(top.getName(), new ReceiveDataHandler(top, participant, ReceiverFactory.createReceiver(top, participant.getDomain().getLocalInterface())));

            }
        }
        return multicastReceiveDataHandlers.get(top.getName());
    }

}
