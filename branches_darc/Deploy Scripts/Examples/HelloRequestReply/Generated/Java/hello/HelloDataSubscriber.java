//Auto generated OPS-code. !DO NOT MODIFY!

package hello;

import java.io.IOException;
import ops.Subscriber;
import ops.OPSObject;
import ops.Topic;
import ops.OPSTopicTypeMissmatchException;

public class HelloDataSubscriber extends Subscriber 
{
    public HelloDataSubscriber(Topic<HelloData> t) //throws ops.OPSTopicTypeMissmatchException
    {
        super(t);
        
    }

    public HelloData getData()
    {
        return (HelloData)super.getData();
    }
}