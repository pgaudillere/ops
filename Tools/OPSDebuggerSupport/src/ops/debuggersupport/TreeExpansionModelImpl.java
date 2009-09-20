/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.debuggersupport;

import org.netbeans.spi.viewmodel.TreeExpansionModel;
import org.netbeans.spi.viewmodel.UnknownTypeException;

/**
 *
 * @author Admin
 */
class TreeExpansionModelImpl implements TreeExpansionModel
{

    public TreeExpansionModelImpl()
    {
    }

    public boolean isExpanded(Object obj) throws UnknownTypeException
    {
        NameValuePair nvp = (NameValuePair) obj;
        return nvp.expanded;
    }

    public void nodeExpanded(Object obj)
    {
        NameValuePair nvp = (NameValuePair) obj;
        nvp.expanded = true;
        
    }

    public void nodeCollapsed(Object obj)
    {
        NameValuePair nvp = (NameValuePair) obj;
        nvp.expanded = false;
    }
}
