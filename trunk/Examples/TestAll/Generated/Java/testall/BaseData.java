//Auto generated OPS-code. DO NOT MODIFY!

package testall;

import ops.OPSObject;
import configlib.ArchiverInOut;
import java.io.IOException;

public class BaseData extends OPSObject
{
	public String baseText = "";


    public BaseData()
    {
        super();
        appendType("testall.BaseData");

    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
		baseText = archive.inout("baseText", baseText);

    }
}