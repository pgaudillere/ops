/**
* 
* Copyright (C) 2006-2009 Anton Gravestam.
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

#ifndef ops_OPSArchiverOutH
#define ops_OPSArchiverOutH

#include "ByteBuffer.h"
#include "Serializable.h"
#include "ArchiverInOut.h"
#include <vector>

namespace ops
{

class OPSArchiverOut : public ArchiverInOut
{
public:
	OPSArchiverOut(ByteBuffer* _buf) 
	{
		buf = _buf;
	}
	~OPSArchiverOut()
	{

	}
	void inout(std::string& name, bool& value)
	{
		char ch = 0;
		value ? ch = 1 : ch = 0;
		buf->WriteChar(ch);
	}
	void inout(std::string& name, char& value)
	{
		buf->WriteChar(value);
	}
    void inout(std::string& name, int& value)
	{
		buf->WriteInt(value);
	}
    void inout(std::string& name, __int16& value)
	{
		buf->WriteShort(value);
	}
    void inout(std::string& name, __int64& value)
	{
		buf->WriteLong(value);
	}
    void inout(std::string& name, float& value)
	{
		buf->WriteFloat(value);
	}
    void inout(std::string& name, double& value)
	{
		buf->WriteDouble(value);
	}
	void inout(std::string& name, std::string& value)
	{
		buf->WriteString(value);
	}
	Serializable* inout(std::string& name, Serializable* value, int element)
	{
		std::string typeS = ((OPSObject*)value)->getTypeString();
		buf->WriteString(typeS);
		value->serialize(this);
		return value;
	}
    Serializable* inout(std::string& name, Serializable* value)
	{
		std::string typeS = ((OPSObject*)value)->getTypeString();
		buf->WriteString(typeS);
		value->serialize(this);
		return value;
	}

	void inout(std::string& name, std::vector<bool>& value)
	{
		buf->WriteBooleans(value);

	}
	void inout(std::string& name, std::vector<char>& value)
	{
		buf->WriteBytes(value);

	}
    void inout(std::string& name, std::vector<int>& value)
	{
		buf->WriteInts(value);

	}
    void inout(std::string& name, std::vector<short>& value)
	{
		//Not implemented

	}
    void inout(std::string& name, std::vector<__int64>& value)
	{
		buf->WriteLongs(value);

	}
    void inout(std::string& name, std::vector<float>& value)
	{
		buf->WriteFloats(value);
		
	}
    void inout(std::string& name, std::vector<double>& value)
	{
		buf->WriteDoubles(value);
		
	}
	void inout(std::string& name, std::vector<std::string>& value)
	{
		buf->WriteStrings(value);
		
	}
    int beginList(std::string& name, int size)
	{
		buf->WriteInt(size);
		return size;
	}
	void endList(std::string& name)
	{
		//Nothing to do in this implementation
	}
private:
	ByteBuffer* buf;
 
};
}

#endif