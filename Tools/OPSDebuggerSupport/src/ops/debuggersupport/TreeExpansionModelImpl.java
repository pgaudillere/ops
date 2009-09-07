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

    public boolean isExpanded(Object arg0) throws UnknownTypeException
    {
        return true;
    }

    public void nodeExpanded(Object arg0)
    {
        
    }

    public void nodeCollapsed(Object arg0)
    {
        
    }
}
