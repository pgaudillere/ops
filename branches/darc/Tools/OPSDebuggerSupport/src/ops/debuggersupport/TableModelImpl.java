/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.debuggersupport;

import java.lang.reflect.Method;
import org.netbeans.spi.viewmodel.ModelListener;
import org.netbeans.spi.viewmodel.TableModel;

/**
 *
 * @author Admin
 */
public class TableModelImpl implements TableModel
{

    public Object getValueAt(Object node, String columnID)
    {
        try
        {

            if (columnID.equals("typeID"))
            {
                NameValuePair nvp = (NameValuePair) node;
                return nvp.value.getClass().getSimpleName();
                
            }
            else if (columnID.equals("valueID"))
            {

                NameValuePair nvp = (NameValuePair) node;
                return nvp.value;
            }
            else
            {
                return "";
            }
        } catch (Exception e)
        {
            //e.printStackTrace();
        }
        return "";
    }

    public boolean isReadOnly(Object node, String columnID)
    {
        return true;
    }

    public void setValueAt(Object node, String columnID, Object value)
    {
    }

    public void addModelListener(ModelListener arg0)
    {
        
    }

    public void removeModelListener(ModelListener arg0)
    {
        
    }
}
