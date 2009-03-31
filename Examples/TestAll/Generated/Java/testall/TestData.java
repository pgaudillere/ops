//Auto generated OPS-code. DO NOT MODIFY!

package testall;

import ops.OPSObject;
import configlib.ArchiverInOut;
import java.io.IOException;

public class TestData extends OPSObject
{
	public String text = "";
	public double value;


    public TestData()
    {
        super();
        appendType("testall.TestData");

    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
		text = archive.inout("text", text);
		value = archive.inout("value", value);

    }
}