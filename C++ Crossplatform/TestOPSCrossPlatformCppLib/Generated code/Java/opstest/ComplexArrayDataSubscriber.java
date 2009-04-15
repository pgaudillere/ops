//Auto generated OPS-code. !DO NOT MODIFY!

package opstest;

import java.io.IOException;
import ops.Subscriber;
import ops.OPSObject;
import ops.Topic;
import ops.OPSTopicTypeMissmatchException;

public class ComplexArrayDataSubscriber extends Subscriber 
{
    

    public ComplexArrayDataSubscriber(Topic<ComplexArrayData> t) //throws ops.OPSTopicTypeMissmatchException
    {
        super(t);
        setObjectHelper(new ComplexArrayDataHelper());
        //start();

    }
    
    

}