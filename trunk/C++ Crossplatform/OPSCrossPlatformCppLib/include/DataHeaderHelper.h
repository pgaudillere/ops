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