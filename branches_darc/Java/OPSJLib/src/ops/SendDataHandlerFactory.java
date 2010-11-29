/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

import java.io.IOException;

/**
 *
 * @author Anton Gravestam
 */
class SendDataHandlerFactory
{

    SendDataHandler getSendDataHandler(Topic t, Participant participant) throws CommException
    {
        if(t.getTransport().equals(Topic.TRANSPORT_MC))
        {
            try
            {
                return new McSendDataHandler(t, participant.getDomain().getLocalInterface());
            } catch (IOException ex)
            {
                throw new CommException("Error creating SendDataHndler. IOException -->" + ex.getMessage());
            }
        }
        throw new CommException("No such Transport " + t.getTransport());
    }

}
