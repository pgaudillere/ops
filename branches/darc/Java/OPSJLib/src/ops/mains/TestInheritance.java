/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.mains;

import ops.archiver.BaseTestData;
import ops.archiver.ChildTestData;
import ops.archiver.OPSObjectFactory;
import ops.archiver.TestTypesFactory;

/**
 *
 * @author angr
 */
public class TestInheritance
{
    public static void main(String[] arg)
    {
        //Register types with OPS
        OPSObjectFactory.getInstance().add(new TestTypesFactory());

        BaseTestData baseInst = (BaseTestData) OPSObjectFactory.getInstance().create("ops.archiver.BaseTestData");
        BaseTestData childInst = (BaseTestData) OPSObjectFactory.getInstance().create("ops.archiver.ChildTestData");

        System.out.println("Hatt.");
        
        
    }
}
