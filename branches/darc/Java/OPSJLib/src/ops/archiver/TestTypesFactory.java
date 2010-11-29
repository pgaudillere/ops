/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops.archiver;

import configlib.Serializable;
import configlib.SerializableFactory;

/**
 *
 * @author angr
 */
public class TestTypesFactory implements  SerializableFactory
{
    public Serializable create(String type)
    {
        if(type.equals("ops.archiver.BaseTestData"))
        {
            return new ops.archiver.BaseTestData();
        }
        if(type.equals("ops.archiver.ChildTestData"))
        {
            return new ops.archiver.ChildTestData();
        }
        return null;
    }
}
