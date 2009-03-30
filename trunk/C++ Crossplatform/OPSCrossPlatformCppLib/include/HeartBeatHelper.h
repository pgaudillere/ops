//Auto generated OPS-code. DO NOT MODIFY!
#ifndef opsHeartBeatHelperH
#define opsHeartBeatHelperH

#include "OPSObject.h"
#include "OPSObjectHelper.h"
#include "ByteBuffer.h"
#include <string>
#include <vector>
#include "Manager.h"
#include "HeartBeatHelper.h"
#include "HeartBeat.h"


namespace ops
{
class HeartBeatHelper :
	public ops::OPSObjectHelper
{
public:
	

    HeartBeatHelper()
    {
        

    }
    std::string GetTypeID()
    {
        return "ops.HeartBeat";
    }
    int getSize(ops::OPSObject* o)
    {
        //Not used yet
        int i = 0;
			HeartBeat* oHeartBeat = (HeartBeat*)o;i += GetOPSObjectFieldsSize(oHeartBeat);
			i += 1;
			i += 1;
			i += 4;
			i += 4;
			i += 8;
			i += 8;
			i += (int)oHeartBeat->subscriberID.size() + 4;
			i += (int)oHeartBeat->topicName.size() + 4;
			i += (int)oHeartBeat->topLevelKey.size() + 4;
			i += (int)oHeartBeat->address.size() + 4;
			return i;
		
    }

    ~HeartBeatHelper(void)
    {
    }

    void serialize(ops::OPSObject* o, char* b)
    {
        ops::ByteBuffer buf(b);
        HeartBeat* oHeartBeat = (HeartBeat*)o;
        buf.WriteOPSObjectFields(o);
        buf.WriteChar(oHeartBeat->messageType);
        buf.WriteChar(oHeartBeat->endianness);
        buf.WriteInt(oHeartBeat->highestSegment);
        buf.WriteInt(oHeartBeat->port);
        buf.WriteLong(oHeartBeat->qosMask);
        buf.WriteLong(oHeartBeat->highestPublicationID);
        buf.WriteString(oHeartBeat->subscriberID);
        buf.WriteString(oHeartBeat->topicName);
        buf.WriteString(oHeartBeat->topLevelKey);
        buf.WriteString(oHeartBeat->address);
        
    }
    ops::OPSObject* deserialize(char* b)
    {
        ops::ByteBuffer buf(b);
        HeartBeat* o = new HeartBeat();
        buf.ReadOPSObjectFields(o);
        o->messageType = buf.ReadChar();
        o->endianness = buf.ReadChar();
        o->highestSegment = buf.ReadInt();
        o->port = buf.ReadInt();
        o->qosMask = buf.ReadLong();
        o->highestPublicationID = buf.ReadLong();
        o->subscriberID = buf.ReadString();
        o->topicName = buf.ReadString();
        o->topLevelKey = buf.ReadString();
        o->address = buf.ReadString();
        return o;
    }

};
}

#endif