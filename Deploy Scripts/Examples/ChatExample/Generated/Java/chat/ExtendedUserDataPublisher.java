//Auto generated OPS-code. !DO NOT MODIFY!

package chat;

import ops.CommException;
import ops.Publisher;
import ops.OPSObject;
import ops.Topic;
import ops.AckData;


public class ExtendedUserDataPublisher extends Publisher 
{
    public ExtendedUserDataPublisher(Topic<ExtendedUserData> t) throws ops.CommException
    {
        super(t);
    }
    public void write(ExtendedUserData o) 
    {
        super.write(o);
    }    
}