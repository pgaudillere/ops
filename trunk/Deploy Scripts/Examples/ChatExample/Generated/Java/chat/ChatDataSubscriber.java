//Auto generated OPS-code. !DO NOT MODIFY!

package chat;

import java.io.IOException;
import ops.Subscriber;
import ops.OPSObject;
import ops.Topic;
import ops.OPSTopicTypeMissmatchException;

public class ChatDataSubscriber extends Subscriber 
{
    public ChatDataSubscriber(Topic<ChatData> t) //throws ops.OPSTopicTypeMissmatchException
    {
        super(t);
        
    }

    public ChatData getData()
    {
        return (ChatData)super.getData();
    }
}