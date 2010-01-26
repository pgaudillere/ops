/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.debuggersupport;

import org.netbeans.spi.viewmodel.ColumnModel;

/**
 *
 * @author Admin
 */
class ValueColumnModel extends ColumnModel
{

    @Override
    public String getID()
    {
        return "valueID";
    }

    @Override
    public String getDisplayName()
    {
        return "Value";
    }

    @Override
    public Class getType()
    {
        return String.class;
    }
}
