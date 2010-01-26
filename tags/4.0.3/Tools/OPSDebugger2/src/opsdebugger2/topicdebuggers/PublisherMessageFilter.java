/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package opsdebugger2.topicdebuggers;

import java.util.Vector;
import ops.MessageFilter;
import ops.OPSObject;
import ops.protocol.OPSMessage;

/**
 *
 * @author angr
 */
class PublisherMessageFilter implements MessageFilter
{
    private Vector<String> pubs = new Vector<String>();
    


    void setKeys(Vector<String> publishers)
    {
        pubs = publishers;
    }

    public boolean applyFilter(OPSMessage m)
    {
        for (String string : pubs)
        {
            if(!m.getPublisherName().equals(string))
            {
                return false;
            }
        }
        return true;
    }
}
