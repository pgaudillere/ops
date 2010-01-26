//Auto generated OPS-code. !DO NOT MODIFY!

package hello;

import ops.CommException;
import ops.Publisher;
import ops.OPSObject;
import ops.Topic;
import ops.AckData;


public class RequestHelloDataPublisher extends Publisher 
{
    public RequestHelloDataPublisher(Topic<RequestHelloData> t) throws ops.CommException
    {
        super(t);
    }
    public void write(RequestHelloData o) 
    {
        super.write(o);
    }    
}