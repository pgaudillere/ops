#ifndef ops_OPSArchiverInH
#define ops_OPSArchiverInH

#include "ByteBuffer.h"
#include "OPSObjectFactory.h"
#include "Serializable.h"
#include "ArchiverInOut.h"
#include <vector>

namespace ops
{

class OPSArchiverIn : public ArchiverInOut
{
public:
	OPSArchiverIn(ByteBuffer* _buf) 
	{
		buf = _buf;
		factory = OPSObjectFactory::getInstance();
	}
	~OPSArchiverIn()
	{}

	bool inout(std::string& name, bool value)
	{
		return buf->ReadChar() > 0;
	}
	char inout(std::string& name, char value)
	{
		return buf->ReadChar();
	}
    int inout(std::string& name, int value)
	{
		return buf->ReadInt();
	}
    short inout(std::string& name, short value)
	{
		//Not implemented
		return value;
	}
    __int64	inout(std::string& name, __int64 value)
	{
		return buf->ReadLong();
	}
    float inout(std::string& name, float value)
	{
		return buf->ReadFloat();
	}
    double inout(std::string& name, double value)
	{
		return buf->ReadDouble();
	}
	std::string inout(std::string& name, std::string value)
	{
		return buf->ReadString();
	}
    Serializable* inout(std::string& name, Serializable* value)
	{
		std::string types = buf->ReadString();
		Serializable* newSer = factory->create(types);
        if(newSer != NULL)
        {
            newSer->serialize(this);
        }

		return newSer;
	}

	void inout(std::string& name, std::vector<bool>& value)
	{
		buf->ReadBooleans(value);
	}
	void inout(std::string& name, std::vector<char>& value)
	{
		buf->ReadBytes(value);
	}
    void inout(std::string& name, std::vector<int>& value)
	{
		buf->ReadInts(value);
	}
    void inout(std::string& name, std::vector<short>& value)
	{
		//Not implemented
		//return value;
	}
    void inout(std::string& name, std::vector<__int64>& value)
	{
		buf->ReadLongs(value);
	}
    void inout(std::string& name, std::vector<float>& value)
	{
		buf->ReadFloats(value);
	}
    void inout(std::string& name, std::vector<double>& value)
	{
		buf->ReadDoubles(value);
	}
	void inout(std::string& name, std::vector<std::string>& value)
	{
		buf->ReadStrings(value);
	}

	int beginList(std::string& name, int size)
	{
		return buf->ReadInt();
	}
	void endList(std::string& name)
	{
		//Nothing to do in this implementation
	}
	
	/*template <class SerializableTypeVector> SerializableTypeVector archiveSerializables(ArchiverInOut* archive, SerializableTypeVector vec)
	{
		int size = archive->inout("size", size);
		for(unsigned int i = 0; i < size; i++)
		{
			vec[i] = archive->inout((Serializable*)NULL);
		}
		return vec;

	}*/


private:
	ByteBuffer* buf;
	OPSObjectFactory* factory;
};

	
}
#endif