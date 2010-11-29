//Auto generated OPS-code. DO NOT MODIFY!

package hello;

import ops.OPSObject;
import configlib.ArchiverInOut;
import java.io.IOException;

public class RequestHelloData extends ops.Request
{
	public String requestersName = "";


    public RequestHelloData()
    {
        super();
        appendType("hello.RequestHelloData");

    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
		requestersName = archive.inout("requestersName", requestersName);

    }
}