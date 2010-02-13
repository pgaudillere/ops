//Auto generated OPS-code. !DO NOT MODIFY!

package hello;

import ops.Publisher;
import ops.OPSObject;
import ops.Topic;

public class HelloDataPublisher extends Publisher 
{
    public HelloDataPublisher(Topic<HelloData> t)
    {
        super(t);
    }
    public void write(HelloData o) 
    {
        super.write(o);
    }    
}