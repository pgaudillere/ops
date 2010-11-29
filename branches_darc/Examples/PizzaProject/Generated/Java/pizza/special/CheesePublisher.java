//Auto generated OPS-code. !DO NOT MODIFY!

package pizza.special;

import ops.CommException;
import ops.Publisher;
import ops.OPSObject;
import ops.Topic;
import ops.AckData;


public class CheesePublisher extends Publisher 
{
    public CheesePublisher(Topic<Cheese> t) 
    {
        super(t);
    }
    public void write(Cheese o) 
    {
        super.write(o);
    }    
}