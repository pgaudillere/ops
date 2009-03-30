//Auto generated OPS-code. DO NOT MODIFY!
#ifndef opsDataHeaderHelperH
#define opsDataHeaderHelperH

#include "OPSObject.h"
#include "ByteBuffer.h"
#include <string>
#include <vector>
#include "DataHeaderHelper.h"
#include "DataHeader.h"


namespace ops
{
class DataHeaderHelper :
	public ops::OPSObjectHelper
{
public:
	

    DataHeaderHelper()
    {
        

    }
    std::string GetTypeID()
    {
        return "ops.DataHeader";
    }
    int getSize(ops::OPSObject* o)
    {
        //Not used yet
        int i = 0;
			DataHeader* oDataHeader = (DataHeader*)o;i += GetOPSObjectFieldsSize(oDataHeader);
			i += 1;
			i += 1;
			i += 1;
			i += 4;
			i += 4;
			i += 4;
			i += 4;
			i += 8;
			i += 8;
			i += (int)oDataHeader->publisherID.size() + 4;
			i += (int)oDataHeader->topicName.size() + 4;
			i += (int)oDataHeader->topLevelKey.size() + 4;
			i += (int)oDataHeader->address.size() + 4;
			return i;
		
    }

    ~DataHeaderHelper(void)
    {
    }

    void serialize(ops::OPSObject* o, char* b)
    {
        ops::ByteBuffer buf(b);
        DataHeader* oDataHeader = (DataHeader*)o;
        buf.WriteOPSObjectFields(o);
        buf.WriteChar(oDataHeader->messageType);
        buf.WriteChar(oDataHeader->endianness);
        buf.WriteChar(oDataHeader->publisherPriority);
        buf.WriteInt(oDataHeader->nrOfSegments);
        buf.WriteInt(oDataHeader->segment);
        buf.WriteInt(oDataHeader->port);
        buf.WriteInt(oDataHeader->dataSize);
        buf.WriteLong(oDataHeader->qosMask);
        buf.WriteLong(oDataHeader->publicationID);
        buf.WriteString(oDataHeader->publisherID);
        buf.WriteString(oDataHeader->topicName);
        buf.WriteString(oDataHeader->topLevelKey);
        buf.WriteString(oDataHeader->address);
        
    }
    ops::OPSObject* deserialize(char* b)
    {
        ops::ByteBuffer buf(b);
        DataHeader* o = new DataHeader();
        buf.ReadOPSObjectFields(o);
        o->messageType = buf.ReadChar();
        o->endianness = buf.ReadChar();
        o->publisherPriority = buf.ReadChar();
        o->nrOfSegments = buf.ReadInt();
        o->segment = buf.ReadInt();
        o->port = buf.ReadInt();
        o->dataSize = buf.ReadInt();
        o->qosMask = buf.ReadLong();
        o->publicationID = buf.ReadLong();
        o->publisherID = buf.ReadString();
        o->topicName = buf.ReadString();
        o->topLevelKey = buf.ReadString();
        o->address = buf.ReadString();
        return o;
    }

};
}

#endif