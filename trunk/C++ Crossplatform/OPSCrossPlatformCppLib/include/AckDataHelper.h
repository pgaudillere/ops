//Auto generated OPS-code. DO NOT MODIFY!
#ifndef opsAckDataHelperH
#define opsAckDataHelperH

#include "OPSObject.h"
#include "OPSObjectHelper.h"
#include "ByteBuffer.h"
#include <string>
#include <vector>
#include "AckDataHelper.h"
#include "AckData.h"


namespace ops
{
class AckDataHelper :
	public ops::OPSObjectHelper
{
public:
	

    AckDataHelper()
    {
        

    }
    std::string GetTypeID()
    {
        return "ops.AckData";
    }
    int getSize(ops::OPSObject* o)
    {
        //Not used yet
        int i = 0;
			AckData* oAckData = (AckData*)o;i += GetOPSObjectFieldsSize(oAckData);
			i += 1;
			i += (int)oAckData->message.size() + 4;
			i += (int)oAckData->id.size() + 4;
			return i;
		
    }

    ~AckDataHelper(void)
    {
    }

    char* serialize(ops::OPSObject* o)
    {
        char* b = new char[getSize(o)];
        ops::ByteBuffer buf(b);
        AckData* oAckData = (AckData*)o;
        buf.WriteOPSObjectFields(o);
        buf.WriteChar((char)(oAckData->dataAccepted? 1 : 0));
        buf.WriteString(oAckData->message);
        buf.WriteString(oAckData->id);
        return b;
        
    }
    ops::OPSObject* deserialize(char* b)
    {
        ops::ByteBuffer buf(b);
        AckData* o = new AckData();
        buf.ReadOPSObjectFields(o);
        o->dataAccepted = buf.ReadChar() > 0;
        o->message = buf.ReadString();
        o->id = buf.ReadString();
        return o;
    }

};
}

#endif