//Auto generated OPS-code. DO NOT MODIFY!
#ifndef opstestByteArrayDataHelperH
#define opstestByteArrayDataHelperH

#include "OPSObject.h"
#include "OPSObjectHelper.h"
#include "ByteBuffer.h"
#include <string>
#include <vector>
#include "ByteArrayDataHelper.h"
#include "ByteArrayData.h"


namespace opstest
{
class ByteArrayDataHelper :
	public ops::OPSObjectHelper
{
public:
	

    ByteArrayDataHelper()
    {
        

    }
    std::string GetTypeID()
    {
        return "opstest.ByteArrayData";
    }
    int getSize(ops::OPSObject* o)
    {
        //Not used yet
        int i = 0;
			ByteArrayData* oByteArrayData = (ByteArrayData*)o;i += GetOPSObjectFieldsSize(oByteArrayData);
			i += 8;
			i += (int)oByteArrayData->bytes.size() + 4;
			return i;
		
    }

    ~ByteArrayDataHelper(void)
    {
    }

    void serialize(ops::OPSObject* o, char* b)
    {
        ops::ByteBuffer buf(b);
        ByteArrayData* oByteArrayData = (ByteArrayData*)o;
        buf.WriteOPSObjectFields(o);
        buf.WriteLong(oByteArrayData->timestamp);
        buf.WriteBytes(oByteArrayData->bytes);
        
    }
    ops::OPSObject* deserialize(char* b)
    {
        ops::ByteBuffer buf(b);
        ByteArrayData* o = new ByteArrayData();
        buf.ReadOPSObjectFields(o);
        o->timestamp = buf.ReadLong();
        buf.ReadBytes(o->bytes);
        return o;
    }

};
}

#endif