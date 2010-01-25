//Auto generated OPS-code. !DO NOT MODIFY!

package hello;

import ops.CommException;
import ops.Publisher;
import ops.OPSObject;
import ops.Topic;
import ops.AckData;


public class HelloDataPublisher extends Publisher 
{
    public HelloDataPublisher(Topic<HelloData> t) throws ops.CommException
    {
        super(t);
    }
    public void write(HelloData o) 
    {
        super.write(o);
    }    
}