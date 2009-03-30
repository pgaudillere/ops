//Auto generated OPS-code. DO NOT MODIFY!
#ifndef opsTopicInterfaceDataHelperH
#define opsTopicInterfaceDataHelperH

#include "OPSObject.h"
#include "OPSObjectHelper.h"
#include "ByteBuffer.h"
#include <string>
#include <vector>
#include "TopicInterfaceDataHelper.h"
#include "TopicInterfaceData.h"


namespace ops
{
class TopicInterfaceDataHelper :
	public ops::OPSObjectHelper
{
public:
	

    TopicInterfaceDataHelper()
    {
        

    }
    std::string GetTypeID()
    {
        return "ops.TopicInterfaceData";
    }
    int getSize(ops::OPSObject* o)
    {
        //Not used yet
        int i = 0;
			TopicInterfaceData* oTopicInterfaceData = (TopicInterfaceData*)o;i += GetOPSObjectFieldsSize(oTopicInterfaceData);
			i += 1;
			i += 4;
			i += 4;
			i += (int)oTopicInterfaceData->address.size() + 4;
			i += (int)oTopicInterfaceData->topicName.size() + 4;
			i += (int)oTopicInterfaceData->participantName.size() + 4;
			i += 4;
			for(unsigned int j = 0; j < oTopicInterfaceData->keys.size(); j++)
			{
				i += (int)oTopicInterfaceData->keys.at(j).size() + 4; 
			}
			i += 4;
			for(unsigned int j = 0; j < oTopicInterfaceData->reliableIdentities.size(); j++)
			{
				i += (int)oTopicInterfaceData->reliableIdentities.at(j).size() + 4; 
			}
			return i;
		
    }

    ~TopicInterfaceDataHelper(void)
    {
    }

    char* serialize(ops::OPSObject* o)
    {
        char* b = new char[getSize(o)];
        ops::ByteBuffer buf(b);
        TopicInterfaceData* oTopicInterfaceData = (TopicInterfaceData*)o;
        buf.WriteOPSObjectFields(o);
        buf.WriteChar((char)(oTopicInterfaceData->hasReliableSubscribers? 1 : 0));
        buf.WriteInt(oTopicInterfaceData->port);
        buf.WriteInt(oTopicInterfaceData->timebaseSeparation);
        buf.WriteString(oTopicInterfaceData->address);
        buf.WriteString(oTopicInterfaceData->topicName);
        buf.WriteString(oTopicInterfaceData->participantName);
        buf.WriteInt((int)oTopicInterfaceData->keys.size()); 
        for(unsigned int __i = 0 ; __i < oTopicInterfaceData->keys.size(); __i++)
        {
            buf.WriteString(oTopicInterfaceData->keys.at(__i));
        }

        buf.WriteInt((int)oTopicInterfaceData->reliableIdentities.size()); 
        for(unsigned int __i = 0 ; __i < oTopicInterfaceData->reliableIdentities.size(); __i++)
        {
            buf.WriteString(oTopicInterfaceData->reliableIdentities.at(__i));
        }

        return b;
        
    }
    ops::OPSObject* deserialize(char* b)
    {
        ops::ByteBuffer buf(b);
        TopicInterfaceData* o = new TopicInterfaceData();
        buf.ReadOPSObjectFields(o);
        o->hasReliableSubscribers = buf.ReadChar() > 0;
        o->port = buf.ReadInt();
        o->timebaseSeparation = buf.ReadInt();
        o->address = buf.ReadString();
        o->topicName = buf.ReadString();
        o->participantName = buf.ReadString();
        int sizekeys = buf.ReadInt();
        for(int __i = 0 ; __i < sizekeys; __i++)
            o->keys.push_back(buf.ReadString());

        int sizereliableIdentities = buf.ReadInt();
        for(int __i = 0 ; __i < sizereliableIdentities; __i++)
            o->reliableIdentities.push_back(buf.ReadString());

        return o;
    }

};
}

#endif