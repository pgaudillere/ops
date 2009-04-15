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

//Auto generated helper class for ByteArrayData
public class ByteArrayDataHelper extends OPSObjectHelper
{

    public ByteArrayDataHelper()
    { }

    //Auto generated serialization code for a ByteArrayData
    public byte[] serialize(OPSObject o) throws IOException
    {
 		WriteByteBuffer buf = new WriteByteBuffer();
		ByteArrayData oNarr = (ByteArrayData)o;
		buf.write(oNarr.timestamp);
		buf.writebyteArr(oNarr.bytes);
		return buf.getBytes();

    }

    //Auto generated deserialization code for a ByteArrayData
    public OPSObject deserialize(byte[] __b) throws IOException
    {
		ReadByteBuffer buf = new ReadByteBuffer(new DataInputStream(new ByteArrayInputStream(__b)));
		ByteArrayData o = new ByteArrayData();
		o.timestamp = buf.readlong();
		o.bytes = buf.readbyteArr();
		return o;

    }

    //Auto generated code for getting the current size of a ByteArrayData
    public int getSize(OPSObject o)
    {
		int i = 0;
		ByteArrayData oNarr = (ByteArrayData)o;
		i += 4 + oNarr.bytes.size() * 1;
		i += 8;
		return i;

    }

    //Auto generated code for getting the typeID of a ByteArrayData
    public String getTypeID()
    {
        return "opstest.ByteArrayData";
    }

    public static ByteArrayData copy(ByteArrayData o)
    {
        try
        {
            ByteArrayDataHelper helper = new ByteArrayDataHelper();
            byte[] bytes = helper.serialize(o);
            ByteArrayData c = (ByteArrayData)helper.deserialize(bytes);
            return c;
        }
        catch(IOException e)
        {
            return null;
        }
    }
}