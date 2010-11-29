//Auto generated OPS-code. DO NOT MODIFY!

package pizza.special;

import ops.OPSObject;
import configlib.ArchiverInOut;
import java.io.IOException;

public class LHCData extends pizza.CapricosaData
{
	public String bearnaise = "";
	public String beef = "";
	public java.util.Vector<pizza.PizzaData> p = new java.util.Vector<pizza.PizzaData>();


    public LHCData()
    {
        super();
        appendType("pizza.special.LHCData");

    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
		bearnaise = archive.inout("bearnaise", bearnaise);
		beef = archive.inout("beef", beef);
		p = (java.util.Vector<pizza.PizzaData>) archive.inoutSerializableList("p", p);

    }
}