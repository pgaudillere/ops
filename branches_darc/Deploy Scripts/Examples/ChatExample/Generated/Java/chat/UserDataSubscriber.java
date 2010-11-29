//Auto generated OPS-code. !DO NOT MODIFY!

package chat;

import java.io.IOException;
import ops.Subscriber;
import ops.OPSObject;
import ops.Topic;
import ops.OPSTopicTypeMissmatchException;

public class UserDataSubscriber extends Subscriber 
{
    public UserDataSubscriber(Topic<UserData> t) //throws ops.OPSTopicTypeMissmatchException
    {
        super(t);
        
    }

    public UserData getData()
    {
        return (UserData)super.getData();
    }
}