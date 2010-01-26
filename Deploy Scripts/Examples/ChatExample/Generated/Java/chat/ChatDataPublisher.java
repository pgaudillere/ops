//Auto generated OPS-code. !DO NOT MODIFY!

package chat;

import ops.CommException;
import ops.Publisher;
import ops.OPSObject;
import ops.Topic;
import ops.AckData;


public class ChatDataPublisher extends Publisher 
{
    public ChatDataPublisher(Topic<ChatData> t) throws ops.CommException
    {
        super(t);
    }
    public void write(ChatData o) 
    {
        super.write(o);
    }    
}