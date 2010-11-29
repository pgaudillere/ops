//Auto generated OPS-code. DO NOT MODIFY!

package chat;

import ops.OPSObject;
import configlib.ArchiverInOut;
import java.io.IOException;

public class ChatData extends OPSObject
{
	public UserData sender = new UserData();
	public MessageData messageData = new MessageData();


    public ChatData()
    {
        super();
        appendType("chat.ChatData");

    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
		sender = (UserData) archive.inout("sender", sender);
		messageData = (MessageData) archive.inout("messageData", messageData);

    }
}