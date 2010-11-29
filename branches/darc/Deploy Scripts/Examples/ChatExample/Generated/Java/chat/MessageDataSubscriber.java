//Auto generated OPS-code. !DO NOT MODIFY!

package chat;

import java.io.IOException;
import ops.Subscriber;
import ops.OPSObject;
import ops.Topic;
import ops.OPSTopicTypeMissmatchException;

public class MessageDataSubscriber extends Subscriber 
{
    public MessageDataSubscriber(Topic<MessageData> t) //throws ops.OPSTopicTypeMissmatchException
    {
        super(t);
        
    }

    public MessageData getData()
    {
        return (MessageData)super.getData();
    }
}