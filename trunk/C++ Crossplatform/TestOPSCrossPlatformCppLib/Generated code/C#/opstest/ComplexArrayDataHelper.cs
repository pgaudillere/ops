//Auto generated OPS-code. DO NOT MODIFY!


using OPS;

namespace opstest
{

    //Auto generated helper class for ComplexArrayData
    public class ComplexArrayDataHelper 
        : OPSObjectHelper 
    {

        public ComplexArrayDataHelper()
        {


        }

        //Auto generated serialization code for a ComplexArrayData
        public override byte[] serialize(OPSObject o)
        {
     OPS.WriteByteBuffer buf = new OPS.WriteByteBuffer(GetSize(o));
        ComplexArrayData oComplexArrayData = (ComplexArrayData)o;
        buf.WriteOPSObjectFields(o);
        buf.Write(oComplexArrayData.timestamp);
        buf.Write(oComplexArrayData.values.Count); 
	foreach(ComplexData  __idltype in oComplexArrayData.values)
	{
		buf.Write(__idltype, new ComplexDataHelper());
        }
	return buf.GetBytes();
        
        }

        //Auto generated deserialization code for a ComplexArrayData
        public override OPSObject deserialize(byte[] b) 
        {
    OPS.ReadByteBuffer buf = new OPS.ReadByteBuffer(b);
        ComplexArrayData oComplexArrayData = new ComplexArrayData();
        buf.ReadOPSObjectFields(oComplexArrayData);
        oComplexArrayData.timestamp = buf.ReadLong();
        int sizevalues = buf.ReadInt();
	for(int __i = 0 ; __i < sizevalues; __i++)
		{
		oComplexArrayData.values.Add((ComplexData)buf.ReadOPSObject(new ComplexDataHelper()));
        }
	return oComplexArrayData;
        }

        //Auto generated code for getting the current size of a ComplexArrayData
        public override int GetSize(OPSObject o)
        {
    int i = 0;
		ComplexArrayData oComplexArrayData = (ComplexArrayData)o;i += GetOPSObjectFieldsSize(oComplexArrayData);
	i += 8;
	i += 4;
	ComplexDataHelper valuesHelper = new ComplexDataHelper();
		foreach(ComplexData idltype in oComplexArrayData.values)
	{
		i += valuesHelper.GetSize(idltype) + 4; 
		}
	return i;
;

        }

        //Auto generated code for getting the typeID of a ComplexArrayData
        public override string getTypeID()
        {
            return "opstest.ComplexArrayData";
        }

    }
}