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
class TypeColumnModel extends ColumnModel
{

    @Override
    public String getID()
    {
        return "typeID";
    }

    @Override
    public String getDisplayName()
    {
        return "Data Type";
    }

    @Override
    public Class getType()
    {
        return String.class;
    }
}
