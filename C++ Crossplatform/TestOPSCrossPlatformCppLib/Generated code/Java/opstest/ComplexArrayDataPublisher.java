//Auto generated OPS-code. !DO NOT MODIFY!

package opstest;

import ops.CommException;
import ops.Publisher;
import ops.OPSObject;
import ops.Topic;
import ops.AckData;


public class ComplexArrayDataPublisher extends Publisher 
{
    

    public ComplexArrayDataPublisher(Topic<ComplexArrayData> t) 
    {
        super(t);
        setObjectHelper(new ComplexArrayDataHelper());

    }
    public void write(ComplexArrayData o) 
    {
        super.write(o);
    }
    public AckData writeReliable(ComplexArrayData o, String destinationIdentity) throws CommException 
    {
        return super.writeReliable(o, destinationIdentity);
    }

    
}