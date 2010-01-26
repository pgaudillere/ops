//Auto generated OPS-code. DO NOT MODIFY!

package chat;

import ops.OPSObject;
import configlib.ArchiverInOut;
import java.io.IOException;

public class ExtendedChatData extends ChatData
{
	public java.util.Vector<String> attachments = new java.util.Vector<String>();


    public ExtendedChatData()
    {
        super();
        appendType("chat.ExtendedChatData");

    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
		attachments = (java.util.Vector<String>) archive.inoutStringList("attachments", attachments);

    }
}