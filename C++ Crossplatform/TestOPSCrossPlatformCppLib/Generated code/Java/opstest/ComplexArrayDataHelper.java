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

//Auto generated helper class for ComplexArrayData
public class ComplexArrayDataHelper extends OPSObjectHelper
{

    public ComplexArrayDataHelper()
    { }

    //Auto generated serialization code for a ComplexArrayData
    public byte[] serialize(OPSObject o) throws IOException
    {
 		WriteByteBuffer buf = new WriteByteBuffer();
		ComplexArrayData oNarr = (ComplexArrayData)o;
		buf.write(oNarr.timestamp);
		buf.writeOPSArr(oNarr.values, new ComplexDataHelper());
		return buf.getBytes();

    }

    //Auto generated deserialization code for a ComplexArrayData
    public OPSObject deserialize(byte[] __b) throws IOException
    {
		ReadByteBuffer buf = new ReadByteBuffer(new DataInputStream(new ByteArrayInputStream(__b)));
		ComplexArrayData o = new ComplexArrayData();
		o.timestamp = buf.readlong();
		buf.readOPSObjectArr(o.values, new ComplexDataHelper());
		return o;

    }

    //Auto generated code for getting the current size of a ComplexArrayData
    public int getSize(OPSObject o)
    {
		int i = 0;
		ComplexArrayData oNarr = (ComplexArrayData)o;
		i += 4;
		for(int j = 0; j < oNarr.values.size(); j++ )
			i += 4 + new ComplexDataHelper().getSize(oNarr.values.get(j));

		i += 8;
		return i;

    }

    //Auto generated code for getting the typeID of a ComplexArrayData
    public String getTypeID()
    {
        return "opstest.ComplexArrayData";
    }

    public static ComplexArrayData copy(ComplexArrayData o)
    {
        try
        {
            ComplexArrayDataHelper helper = new ComplexArrayDataHelper();
            byte[] bytes = helper.serialize(o);
            ComplexArrayData c = (ComplexArrayData)helper.deserialize(bytes);
            return c;
        }
        catch(IOException e)
        {
            return null;
        }
    }
}