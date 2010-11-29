//Auto generated OPS-code. DO NOT MODIFY!

package chat;

import ops.OPSObject;
import configlib.ArchiverInOut;
import java.io.IOException;

public class MessageData extends OPSObject
{
	public String message = "";
	public long timeStamp;


    public MessageData()
    {
        super();
        appendType("chat.MessageData");

    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
		message = archive.inout("message", message);
		timeStamp = archive.inout("timeStamp", timeStamp);

    }
}