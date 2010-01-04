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
public class McSendDataHandler implements SendDataHandler
{
    private Sender sender;
    

    public McSendDataHandler(Topic t, String localInterface) throws IOException
    {
        //TODO:
        sender = new MulticastSender(0, localInterface, 0, t.getOutSocketBufferSize());

    }


    public boolean sendData(byte[] bytes, int size, Topic t)
    {
        int nrSegmentsNeeded = (int)(size / t.getSampleMaxSize()) ;
        if(size % StaticManager.MAX_SIZE != 0)
        {
            nrSegmentsNeeded ++;
        }
        for (int i = 0; i < nrSegmentsNeeded; i++)
        {
            //If this is the last element, only send the bytes that remains, otherwise send a full package.
            int sizeToSend = (i == nrSegmentsNeeded - 1) ? size - (nrSegmentsNeeded - 1) * StaticManager.MAX_SIZE : StaticManager.MAX_SIZE;
            if(!sender.sendTo(bytes, i * StaticManager.MAX_SIZE, sizeToSend, t.getDomainAddress(), t.getPort()))
            {
                return false;
            }
        }
        return true;
       
    }

}
