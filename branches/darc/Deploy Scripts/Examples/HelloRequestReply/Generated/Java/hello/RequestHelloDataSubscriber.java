//Auto generated OPS-code. !DO NOT MODIFY!

package hello;

import java.io.IOException;
import ops.Subscriber;
import ops.OPSObject;
import ops.Topic;
import ops.OPSTopicTypeMissmatchException;

public class RequestHelloDataSubscriber extends Subscriber 
{
    public RequestHelloDataSubscriber(Topic<RequestHelloData> t) //throws ops.OPSTopicTypeMissmatchException
    {
        super(t);
        
    }

    public RequestHelloData getData()
    {
        return (RequestHelloData)super.getData();
    }
}