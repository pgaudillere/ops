//Auto generated OPS-code. DO NOT MODIFY!

package hello;

import ops.OPSObject;
import configlib.ArchiverInOut;
import java.io.IOException;

public class HelloData extends ops.Reply
{
	public String helloString = "";


    public HelloData()
    {
        super();
        appendType("hello.HelloData");

    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
		helloString = archive.inout("helloString", helloString);

    }
}