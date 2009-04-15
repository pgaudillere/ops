//Auto generated OPS-code. !DO NOT MODIFY!

package opstest;

import java.io.IOException;
import ops.Subscriber;
import ops.OPSObject;
import ops.Topic;
import ops.OPSTopicTypeMissmatchException;

public class ComplexDataSubscriber extends Subscriber 
{
    

    public ComplexDataSubscriber(Topic<ComplexData> t) //throws ops.OPSTopicTypeMissmatchException
    {
        super(t);
        setObjectHelper(new ComplexDataHelper());
        //start();

    }
    
    

}