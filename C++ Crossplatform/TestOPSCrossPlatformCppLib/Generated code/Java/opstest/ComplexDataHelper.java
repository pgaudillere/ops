//Auto generated OPS-code. DO NOT MODIFY!
package opstest;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import ops.OPSObject;
import ops.OPSObjectHelper;
import ops.ReadByteBuffer;
import ops.WriteByteBuffer;

//Auto generated helper class for ComplexData
public class ComplexDataHelper extends OPSObjectHelper
{

    public ComplexDataHelper()
    { }

    //Auto generated serialization code for a ComplexData
    public byte[] serialize(OPSObject o) throws IOException
    {
 		WriteByteBuffer buf = new WriteByteBuffer();
		ComplexData oNarr = (ComplexData)o;
		buf.write(oNarr.real);
		buf.write(oNarr.imag);
		return buf.getBytes();

    }

    //Auto generated deserialization code for a ComplexData
    public OPSObject deserialize(byte[] __b) throws IOException
    {
		ReadByteBuffer buf = new ReadByteBuffer(new DataInputStream(new ByteArrayInputStream(__b)));
		ComplexData o = new ComplexData();
		o.real = buf.readdouble();
		o.imag = buf.readdouble();
		return o;

    }

    //Auto generated code for getting the current size of a ComplexData
    public int getSize(OPSObject o)
    {
		int i = 0;
		ComplexData oNarr = (ComplexData)o;
		i += 16;
		return i;

    }

    //Auto generated code for getting the typeID of a ComplexData
    public String getTypeID()
    {
        return "opstest.ComplexData";
    }

    public static ComplexData copy(ComplexData o)
    {
        try
        {
            ComplexDataHelper helper = new ComplexDataHelper();
            byte[] bytes = helper.serialize(o);
            ComplexData c = (ComplexData)helper.deserialize(bytes);
            return c;
        }
        catch(IOException e)
        {
            return null;
        }
    }
}