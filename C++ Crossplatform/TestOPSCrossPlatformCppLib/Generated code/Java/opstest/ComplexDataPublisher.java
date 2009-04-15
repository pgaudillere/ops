//Auto generated OPS-code. !DO NOT MODIFY!

package opstest;

import ops.CommException;
import ops.Publisher;
import ops.OPSObject;
import ops.Topic;
import ops.AckData;


public class ComplexDataPublisher extends Publisher 
{
    

    public ComplexDataPublisher(Topic<ComplexData> t) 
    {
        super(t);
        setObjectHelper(new ComplexDataHelper());

    }
    public void write(ComplexData o) 
    {
        super.write(o);
    }
    public AckData writeReliable(ComplexData o, String destinationIdentity) throws CommException 
    {
        return super.writeReliable(o, destinationIdentity);
    }

    
}