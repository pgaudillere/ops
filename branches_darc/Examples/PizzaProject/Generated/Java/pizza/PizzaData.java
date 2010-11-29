//Auto generated OPS-code. DO NOT MODIFY!

package pizza;

import ops.OPSObject;
import configlib.ArchiverInOut;
import java.io.IOException;

public class PizzaData extends OPSObject
{
	public String cheese = "";
	public String tomatoSauce = "";


    public PizzaData()
    {
        super();
        appendType("pizza.PizzaData");

    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
		cheese = archive.inout("cheese", cheese);
		tomatoSauce = archive.inout("tomatoSauce", tomatoSauce);

    }
}