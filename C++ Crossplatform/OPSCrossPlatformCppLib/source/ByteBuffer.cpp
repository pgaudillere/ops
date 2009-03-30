
#include "ByteBuffer.h"
//#include <boost/asio.hpp>

namespace ops
{
    
    
    ByteBuffer::ByteBuffer(char* buf)
    {
		index = 0;
        buffer = buf;
    }
    
    ByteBuffer::~ByteBuffer()
    {
      
        //delete buffer;
    }
    void ByteBuffer::WriteChars(char* chars, int length)
    {
        memcpy((void*)(buffer + index), chars, length);
        index += length;
    }
    void ByteBuffer::ReadChars(char* chars, int length)
    {
        memcpy((void*)chars, buffer + index, length);
        index += length;
        
    }
    
    void ByteBuffer::ByteSwap(unsigned char * b, int n)
    {
        register int i = 0;
        register int j = n-1;
        while (i<j)
        {
            std::swap(b[i], b[j]);
            i++, j--;
        }
	}


	int ByteBuffer::GetSize()
    {
        return index;
    }
    
    void ByteBuffer::WriteFloat(float f)
    {
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)&f, 4); 
		#endif
        memcpy((void*)(buffer + index), &f, 4);
        index += 4;
        
    }
    void ByteBuffer::WriteInt(int i)
    {
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)&i, 4);
		#endif
        memcpy((void*)(buffer + index), &i, 4);
        index += 4;
        
    }
    void ByteBuffer::WriteLong(long long l)
    {
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)&l, 8);
		#endif
        memcpy((void*)(buffer + index), &l, 8);
        index += 8;
        
    }
    void ByteBuffer::WriteDouble(double d)
    {
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)&d, 8);
		#endif
        memcpy((void*)(buffer + index), &d, 8);
        //buffer[index] = d;
        index += 8;
        
    }
    void ByteBuffer::WriteChar(char c)
    {
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)&c, 1);
		#endif
        buffer[index] = c;
        index += 1;
        
    }
    void ByteBuffer::WriteString(std::string s)
    {
        WriteInt((int)s.size());
        memcpy((void*)(buffer + index), s.c_str(), s.size());
        //(char*)(buffer + index) = (char*)s.c_str();
        index += (int)s.size();
        
    }
  //  void ByteBuffer::WriteOPSObject(OPSObject* o, OPSObjectHelper* oh)
  //  {
  //      int size = oh->getSize(o);
		///*if(size > (Manager::MAX_SIZE - index))
		//{
		//	throw exceptions::CommException("In ByteBuffer::WriteOPSObject: Size exceeds MAX_SIZE limit.");
		//}*/
  //      WriteInt(size);
  //      //char* oBytes = oh->serialize(o, buffer + index);
  //      oh->serialize(o, buffer + index);
		//index += size;
  //      //delete oh;
  //  }
    /*void ByteBuffer::WriteOPSObjectFields(OPSObject* o)
    {
        
        WriteString(o->publisherName);
        WriteString(o->key);
        WriteInt(o->publicationID);
        WriteChar(o->publicationPriority);
        WriteString(o->typesString);
    }*/
    
    
    //Readers
    
  //  OPSObject* ByteBuffer::ReadOPSObject(OPSObjectHelper* oh)
  //  {
  //      int size = ReadInt();
		///*if(size < 0)
		//{
		//	throw exceptions::CommException("In ByteBuffer::ReadOPSObject: Negative size read from data.");
		//}
		//if(size > Manager::MAX_SIZE)
		//{
		//	throw exceptions::CommException("In ByteBuffer::ReadOPSObject: Size of incomming data exceeds local MAX_SIZE limit.");
		//}*/
  //      //char* oBytes = new char[size];
  //      //ReadChars(oBytes, size);
  //      OPSObject* o = oh->deserialize(buffer + index);
		//index += size;
  //      //delete oh;
  //      return o;
  //  }
    float ByteBuffer::ReadFloat()
    {
        float ret;
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)(buffer + index), 4);
		#endif
		ret = *((float*)(buffer + index));
        index += 4;
        return ret;
        
    }
    double ByteBuffer::ReadDouble()
    {
        double ret;
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)(buffer + index), 8);
		#endif
        ret = *((double*)(buffer + index));
        index += 8;
        return ret;
        
    }
    int ByteBuffer::ReadInt()
    {
        int ret;
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)(buffer + index), 4);
		#endif
        ret = *((int*)(buffer + index));
        index += 4;
        return ret;
        
    }
    long long ByteBuffer::ReadLong()
    {
        long long ret;
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)(buffer + index), 8);
		#endif
        ret = *((long long*)(buffer + index));
        index += 8;
        return ret;
        
    }
    char ByteBuffer::ReadChar()
    {
        char ret;
		#ifndef NETWORK_BYTE_ORDER
        ByteSwap((unsigned char*)(buffer + index), 1);
		#endif
        ret = *((char*)(buffer + index));
        index += 1;
        return ret;
        
    }
    std::string ByteBuffer::ReadString()
    {
        
        //ByteSwap((unsigned char*)(buffer + index), 4);
        int length = ReadInt();
        //char* text = new char[length];
        //text = (buffer + index);
        std::string ret((buffer + index), length);
		index += length;

		//delete text;
		return ret;

	}
	/*void ByteBuffer::ReadOPSObjectFields(ops::OPSObject* o)
	{

		o->publisherName = ReadString();
		o->key = ReadString();
		o->publicationID = ReadInt();
		o->publicationPriority = ReadChar();
        o->typesString = ReadString();


	}*/


	void ByteBuffer::ReadBooleans(std::vector<bool>& out)
		{
			int size = ReadInt();
			out.reserve(size);
			out.resize(size, false);
			for(int i = 0; i < size; i++)
			{
				out[i] = ReadChar() > 0;
			}			
			//std::copy((double*)buffer + index, (double*)buffer + index + size, out.begin());
			//index += size*8;

		}
		void ByteBuffer::WriteBooleans(std::vector<bool>& out)
		{
			int size = out.size();
			WriteInt(size);
			for(int i = 0; i < size; i++)
			{
				WriteChar(out[i] ? 1 : 0);
			}	
		}

		void ByteBuffer::ReadBytes(std::vector<char>& out)
		{
			int size = ReadInt();
			out.reserve(size);
			out.resize(size, 0);
						
			std::copy(buffer + index, buffer + index + size, out.begin());
			index += size;

		}
		void ByteBuffer::WriteBytes(std::vector<char>& out)
		{
			int size = out.size();
			WriteInt(size);
			std::copy(out.begin(), out.end(), buffer + index);
			index += size;
		}

		void ByteBuffer::ReadDoubles(std::vector<double>& out)
		{
			int size = ReadInt();
			out.reserve(size);
			out.resize(size, 0.0);
			for(int i = 0; i < size; i++)
			{
				out[i] = ReadDouble();
			}			
			//std::copy((double*)buffer + index, (double*)buffer + index + size, out.begin());
			//index += size*8;

		}
		void ByteBuffer::WriteDoubles(std::vector<double>& out)
		{
			int size = out.size();
			WriteInt(size);
			for(int i = 0; i < size; i++)
			{
				WriteDouble(out[i]);
			}	
		}
		void ByteBuffer::ReadInts(std::vector<int>& out)
		{
			int size = ReadInt();
			out.reserve(size);
			out.resize(size, 0);
			for(int i = 0; i < size; i++)
			{
				out[i] = ReadInt();
			}			
			//std::copy((double*)buffer + index, (double*)buffer + index + size, out.begin());
			//index += size*8;

		}
		void ByteBuffer::WriteInts(std::vector<int>& out)
		{
			int size = out.size();
			WriteInt(size);
			for(int i = 0; i < size; i++)
			{
				WriteInt(out[i]);
			}	
		}
		void ByteBuffer::ReadFloats(std::vector<float>& out)
		{
			int size = ReadInt();
			out.reserve(size);
			out.resize(size, 0.0);
			for(int i = 0; i < size; i++)
			{
				out[i] = ReadFloat();
			}			
			//std::copy((double*)buffer + index, (double*)buffer + index + size, out.begin());
			//index += size*8;

		}
		void ByteBuffer::WriteFloats(std::vector<float>& out)
		{
			int size = out.size();
			WriteInt(size);
			for(int i = 0; i < size; i++)
			{
				WriteFloat(out[i]);
			}	
		}
		void ByteBuffer::ReadLongs(std::vector<__int64>& out)
		{
			int size = ReadInt();
			out.reserve(size);
			out.resize(size, 0);
			for(int i = 0; i < size; i++)
			{
				out[i] = ReadLong(); 
			}			
			//std::copy((double*)buffer + index, (double*)buffer + index + size, out.begin());
			//index += size*8;

		}
		void ByteBuffer::WriteLongs(std::vector<__int64>& out)
		{
			int size = out.size();
			WriteInt(size);
			for(int i = 0; i < size; i++)
			{
				WriteLong(out[i]);
			}	
		}
		void ByteBuffer::ReadStrings(std::vector<std::string>& out)
		{
			int size = ReadInt();
			out.reserve(size);
			out.resize(size, "");
			for(int i = 0; i < size; i++)
			{
				out[i] = ReadString();
			}			
			//std::copy((double*)buffer + index, (double*)buffer + index + size, out.begin());
			//index += size*8;

		}
		void ByteBuffer::WriteStrings(std::vector<std::string>& out)
		{
			int size = out.size();
			WriteInt(size);
			for(int i = 0; i < size; i++)
			{
				WriteString(out[i]);
			}	
		}

	bool ByteBuffer::checkProtocol()
	{
		static char versionHigh = 0;
		static char versionLow = 5;
		static std::string protocolID("opsp");

		char* inProtocolIDChars = new char[5];
		ReadChars(inProtocolIDChars, 4);
		inProtocolIDChars[4] = '\0';
		std::string inProtocolId(inProtocolIDChars);
		delete inProtocolIDChars;

		if(inProtocolId != protocolID)
		{
			//printf("data refused\n");
			return false;
		}

		char inVersionLow = ReadChar();
		char inVersionHigh = ReadChar();
		
		if( (inVersionHigh != versionHigh) || (inVersionLow != versionLow) )
		{
			//printf("data refused\n");
            return false;
        }
        
        return true;
        
    }   
    void ByteBuffer::writeProtocol()
    {
        static char versionHigh = 0;
        static char versionLow = 5;
        static std::string protocolID("opsp");
        
        WriteChars((char*)protocolID.c_str(), 4);
        
		WriteChar(versionLow);
		WriteChar(versionHigh);
                
        
	}

	
	void ByteBuffer::ResetIndex()
	{
        index = 0;
    }

    
}
