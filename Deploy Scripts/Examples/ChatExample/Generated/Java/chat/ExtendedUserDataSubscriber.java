//Auto generated OPS-code. !DO NOT MODIFY!

package chat;

import java.io.IOException;
import ops.Subscriber;
import ops.OPSObject;
import ops.Topic;
import ops.OPSTopicTypeMissmatchException;

public class ExtendedUserDataSubscriber extends Subscriber 
{
    public ExtendedUserDataSubscriber(Topic<ExtendedUserData> t) //throws ops.OPSTopicTypeMissmatchException
    {
        super(t);
        
    }

    public ExtendedUserData getData()
    {
        return (ExtendedUserData)super.getData();
    }
}