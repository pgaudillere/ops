//Auto generated OPS-code. DO NOT MODIFY!


using OPS;

namespace opstest
{

    //Auto generated helper class for ComplexData
    public class ComplexDataHelper 
        : OPSObjectHelper 
    {

        public ComplexDataHelper()
        {


        }

        //Auto generated serialization code for a ComplexData
        public override byte[] serialize(OPSObject o)
        {
     OPS.WriteByteBuffer buf = new OPS.WriteByteBuffer(GetSize(o));
        ComplexData oComplexData = (ComplexData)o;
        buf.WriteOPSObjectFields(o);
        buf.Write(oComplexData.real);
        buf.Write(oComplexData.imag);
        return buf.GetBytes();
        
        }

        //Auto generated deserialization code for a ComplexData
        public override OPSObject deserialize(byte[] b) 
        {
    OPS.ReadByteBuffer buf = new OPS.ReadByteBuffer(b);
        ComplexData oComplexData = new ComplexData();
        buf.ReadOPSObjectFields(oComplexData);
        oComplexData.real = buf.ReadDouble();
        oComplexData.imag = buf.ReadDouble();
        return oComplexData;
        }

        //Auto generated code for getting the current size of a ComplexData
        public override int GetSize(OPSObject o)
        {
    int i = 0;
		ComplexData oComplexData = (ComplexData)o;i += GetOPSObjectFieldsSize(oComplexData);
	i += 8;
	i += 8;
	return i;
;

        }

        //Auto generated code for getting the typeID of a ComplexData
        public override string getTypeID()
        {
            return "opstest.ComplexData";
        }

    }
}