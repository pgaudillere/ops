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