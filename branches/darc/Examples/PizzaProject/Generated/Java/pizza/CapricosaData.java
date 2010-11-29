//Auto generated OPS-code. DO NOT MODIFY!

package pizza;

import ops.OPSObject;
import configlib.ArchiverInOut;
import java.io.IOException;

public class CapricosaData extends VessuvioData
{
	public String mushrooms = "";


    public CapricosaData()
    {
        super();
        appendType("pizza.CapricosaData");

    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
		mushrooms = archive.inout("mushrooms", mushrooms);

    }
}