//Auto generated OPS-code. !DO NOT MODIFY!

package chat;

import ops.CommException;
import ops.Publisher;
import ops.OPSObject;
import ops.Topic;
import ops.AckData;


public class MessageDataPublisher extends Publisher 
{
    public MessageDataPublisher(Topic<MessageData> t) throws ops.CommException
    {
        super(t);
    }
    public void write(MessageData o) 
    {
        super.write(o);
    }    
}