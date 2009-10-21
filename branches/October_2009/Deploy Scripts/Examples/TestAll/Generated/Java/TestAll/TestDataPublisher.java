//Auto generated OPS-code. !DO NOT MODIFY!

package TestAll;

import ops.CommException;
import ops.Publisher;
import ops.OPSObject;
import ops.Topic;
import ops.AckData;


public class TestDataPublisher extends Publisher 
{
    public TestDataPublisher(Topic<TestData> t) 
    {
        super(t);
    }
    public void write(TestData o) 
    {
        super.write(o);
    }    
}