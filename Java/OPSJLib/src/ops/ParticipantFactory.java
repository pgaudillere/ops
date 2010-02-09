/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

import java.io.File;
import java.util.HashMap;

/**
 *
 * @author Anton Gravestam
 */
class ParticipantFactory
{
    private HashMap<String, Participant> instances = new HashMap<String, Participant>();

    Participant getParticipant(String domainID, String participantID)
    {
        return getParticipant(domainID, participantID, null);
    }

    Participant getParticipant(String domainID, String participantID, File file)
    {
        if (!instances.containsKey(participantID))
        {
            Participant newInst = new Participant(domainID, participantID, file);
            Domain tDomain = newInst.getDomain();

            if (tDomain != null)
            {
                instances.put(participantID, newInst);
            } else
            {
                return null;
            }
        }
        return instances.get(participantID);
    }

}
