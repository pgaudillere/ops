/**
* 
* Copyright (C) 2006-2009 Anton Gravestam.
*
* This notice apply to all source files, *.cpp, *.h, *.java, and *.cs in this directory 
* and all its subdirectories if nothing else is explicitly stated within the source file itself.
*
* This file is part of OPS (Open Publish Subscribe).
*
* OPS (Open Publish Subscribe) is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* OPS (Open Publish Subscribe) is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with OPS (Open Publish Subscribe).  If not, see <http://www.gnu.org/licenses/>.
*/

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