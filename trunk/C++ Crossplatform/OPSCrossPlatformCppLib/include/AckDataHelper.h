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