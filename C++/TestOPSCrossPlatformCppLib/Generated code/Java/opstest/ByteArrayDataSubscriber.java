//Auto generated OPS-code. !DO NOT MODIFY!

package opstest;

import java.io.IOException;
import ops.Subscriber;
import ops.OPSObject;
import ops.Topic;
import ops.OPSTopicTypeMissmatchException;

public class ByteArrayDataSubscriber extends Subscriber 
{
    

    public ByteArrayDataSubscriber(Topic<ByteArrayData> t) //throws ops.OPSTopicTypeMissmatchException
    {
        super(t);
        setObjectHelper(new ByteArrayDataHelper());
        //start();

    }
    
    

}