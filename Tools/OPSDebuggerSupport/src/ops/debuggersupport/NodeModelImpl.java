/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.debuggersupport;

import java.lang.reflect.Method;
import org.netbeans.spi.viewmodel.Model;
import org.netbeans.spi.viewmodel.ModelListener;
import org.netbeans.spi.viewmodel.Models;
import org.netbeans.spi.viewmodel.NodeModel;

/**
 *
 * @author Admin
 */
public class NodeModelImpl implements NodeModel
{

    public String getDisplayName(Object node)
    {
         NameValuePair nvp = (NameValuePair) node;
         return nvp.name;

    }

    public String getIconBase(Object node)
    {

        return "file";
    }

    public String getShortDescription(Object node)
    {
       
        NameValuePair nvp = (NameValuePair) node;
        return nvp.name + " : " +nvp.value.getClass().getName();
    }

    public void addModelListener(ModelListener arg0)
    {
        //throw new UnsupportedOperationException("Not supported yet.");
    }

    public void removeModelListener(ModelListener arg0)
    {
        //throw new UnsupportedOperationException("Not supported yet.");
    }
}
