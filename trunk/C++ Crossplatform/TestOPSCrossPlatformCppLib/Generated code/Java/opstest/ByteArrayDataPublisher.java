//Auto generated OPS-code. !DO NOT MODIFY!

package opstest;

import ops.CommException;
import ops.Publisher;
import ops.OPSObject;
import ops.Topic;
import ops.AckData;


public class ByteArrayDataPublisher extends Publisher 
{
    

    public ByteArrayDataPublisher(Topic<ByteArrayData> t) 
    {
        super(t);
        setObjectHelper(new ByteArrayDataHelper());

    }
    public void write(ByteArrayData o) 
    {
        super.write(o);
    }
    public AckData writeReliable(ByteArrayData o, String destinationIdentity) throws CommException 
    {
        return super.writeReliable(o, destinationIdentity);
    }

    
}