/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package opsdebugger2.topicdebuggers;

import java.util.ArrayList;
import java.util.Vector;
import ops.FilterQoSPolicy;
import ops.OPSObject;

/**
 *
 * @author angr
 */
class PublisherFilterQoSPolicy implements FilterQoSPolicy
{
    private Vector<String> pubs = new Vector<String>();
    

    public boolean applyFilter(OPSObject o)
    {
//        for (String string : pubs)
//        {
//            if(o.getPublisherName().equals(string))
//            {
//                return true;
//            }
//
//        }
//        return false;
        return true;
    }

    void setKeys(Vector<String> publishers)
    {
        pubs = publishers;
    }
}
