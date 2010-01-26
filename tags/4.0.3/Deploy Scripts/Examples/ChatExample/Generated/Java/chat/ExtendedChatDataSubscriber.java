//Auto generated OPS-code. !DO NOT MODIFY!

package chat;

import java.io.IOException;
import ops.Subscriber;
import ops.OPSObject;
import ops.Topic;
import ops.OPSTopicTypeMissmatchException;

public class ExtendedChatDataSubscriber extends Subscriber 
{
    public ExtendedChatDataSubscriber(Topic<ExtendedChatData> t) //throws ops.OPSTopicTypeMissmatchException
    {
        super(t);
        
    }

    public ExtendedChatData getData()
    {
        return (ExtendedChatData)super.getData();
    }
}