/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package configlib;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Vector;

/**
 *
 * @author angr
 */
public class TestClass2 implements Serializable
{  
    TestClass1 class1 = new TestClass1();
    ArrayList<TestClass1> classes = new ArrayList<TestClass1>();

    public TestClass2()
    {
        for (int i = 0; i < 10; i++)
        {
            classes.add(new TestClass1());
        }

    }
    public TestClass2(boolean noInit)
    {
        

    }

    public void serialize(ArchiverInOut archive) throws IOException
    {
        class1 = (TestClass1) archive.inout("class1", class1);
//        classes = archive.inoutSerializableList("classes", classes);
    }

  

    
}
