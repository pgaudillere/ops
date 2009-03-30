//Auto generated OPS-code. DO NOT MODIFY!


using OPS;

namespace opstest
{

    //Auto generated helper class for ByteArrayData
    public class ByteArrayDataHelper 
        : OPSObjectHelper 
    {

        public ByteArrayDataHelper()
        {


        }

        //Auto generated serialization code for a ByteArrayData
        public override byte[] serialize(OPSObject o)
        {
     OPS.WriteByteBuffer buf = new OPS.WriteByteBuffer(GetSize(o));
        ByteArrayData oByteArrayData = (ByteArrayData)o;
        buf.WriteOPSObjectFields(o);
        buf.Write(oByteArrayData.timestamp);
        buf.Write(oByteArrayData.bytes);
        return buf.GetBytes();
        
        }

        //Auto generated deserialization code for a ByteArrayData
        public override OPSObject deserialize(byte[] b) 
        {
    OPS.ReadByteBuffer buf = new OPS.ReadByteBuffer(b);
        ByteArrayData oByteArrayData = new ByteArrayData();
        buf.ReadOPSObjectFields(oByteArrayData);
        oByteArrayData.timestamp = buf.ReadLong();
        oByteArrayData.bytes = buf.ReadBytes();
        return oByteArrayData;
        }

        //Auto generated code for getting the current size of a ByteArrayData
        public override int GetSize(OPSObject o)
        {
    int i = 0;
		ByteArrayData oByteArrayData = (ByteArrayData)o;i += GetOPSObjectFieldsSize(oByteArrayData);
	i += 8;
	i += oByteArrayData.bytes.Count + 4;
	return i;
;

        }

        //Auto generated code for getting the typeID of a ByteArrayData
        public override string getTypeID()
        {
            return "opstest.ByteArrayData";
        }

    }
}