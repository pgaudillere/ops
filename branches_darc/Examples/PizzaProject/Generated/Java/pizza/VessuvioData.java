//Auto generated OPS-code. DO NOT MODIFY!

package pizza;

import ops.OPSObject;
import configlib.ArchiverInOut;
import java.io.IOException;

public class VessuvioData extends PizzaData
{
	public String ham = "";


    public VessuvioData()
    {
        super();
        appendType("pizza.VessuvioData");

    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
		ham = archive.inout("ham", ham);

    }
}