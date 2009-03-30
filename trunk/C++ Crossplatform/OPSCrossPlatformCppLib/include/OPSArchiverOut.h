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
	bool inout(std::string& name, bool value)
	{
		buf->WriteChar(value ? 1 : 0);
		return value;
	}
	char inout(std::string& name, char value)
	{
		buf->WriteChar(value);
		return value;
	}
    int inout(std::string& name, int value)
	{
		buf->WriteInt(value);
		return value;
	}
    short inout(std::string& name, short value)
	{
		//Not implemented
		return value;
	}
    __int64	inout(std::string& name, __int64 value)
	{
		buf->WriteLong(value);
		return value;
	}
    float inout(std::string& name, float value)
	{
		buf->WriteFloat(value);
		return value;
	}
    double inout(std::string& name, double value)
	{
		buf->WriteDouble(value);
		return value;
	}
	std::string inout(std::string& name, std::string value)
	{
		buf->WriteString(value);
		return value;
	}
    Serializable* inout(std::string& name, Serializable* value)
	{
		buf->WriteString(((OPSObject*)value)->getTypeString());
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