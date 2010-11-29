//Auto generated OPS-code. DO NOT MODIFY!

package pizza.special;

import ops.OPSObject;
import configlib.ArchiverInOut;
import java.io.IOException;

public class Cheese extends OPSObject
{
	public String name = "";
	public double age;


    public Cheese()
    {
        super();
        appendType("pizza.special.Cheese");

    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
		name = archive.inout("name", name);
		age = archive.inout("age", age);

    }
}