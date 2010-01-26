
package configlib;

import java.io.IOException;

/**
 *
 * @author Anton Gravestam
 */
public class TestClass1 implements Serializable
{

    String name = "Arnesson";
    double d = 12.5;

    public void serialize(ArchiverInOut archive) throws IOException
    {
        name = archive.inout("name", name);
        d = archive.inout("d", d);
    }

    public Serializable create()
    {
        return new TestClass1();
    }
    

}
