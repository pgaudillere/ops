//Auto generated OPS-code. !DO NOT MODIFY!

package chat;

import ops.CommException;
import ops.Publisher;
import ops.OPSObject;
import ops.Topic;
import ops.AckData;


public class UserDataPublisher extends Publisher 
{
    public UserDataPublisher(Topic<UserData> t) throws ops.CommException
    {
        super(t);
    }
    public void write(UserData o) 
    {
        super.write(o);
    }    
}