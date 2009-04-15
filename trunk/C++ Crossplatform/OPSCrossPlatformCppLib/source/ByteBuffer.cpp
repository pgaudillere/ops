
#include "ByteBuffer.h"
//#include <boost/asio.hpp>

namespace ops
{
    
    
    ByteBuffer::ByteBuffer(MemoryMap* mMap)
    {
		index = 0;
		memMap = mMap;
		currentSegment = 0;
		nextSegmentAt = memMap->getSegmentSize();
		//writeNewSegment();
		/*
		index = 0;
		buffer = new char*[1];
        buffer[0] = buf;
		segmentSize = bufSize;
		nextSegmentAt = segmentSize;
		nrOfSegments = 1; 
		currentSegment = -1;

		writeNewSegment();*/
    }
	
	
	int ByteBuffer::getNrOfSegments()
	{
		return currentSegment + 1;
	}
	int ByteBuffer::getSegmentSize(int i)
	{
		if(i < currentSegment)
		{
			return memMap->getSegmentSize();
		}
		else
		{
			//int bytesLeftInSegment = getSegmentSize() - index;
			//int lastSegmentSize = memMap->getSegmentSize() - bytesLeftInSegment;
			return index;
		}
	}
	char* ByteBuffer::getSegment(int i)
	{
		return memMap->getSegment(i);
	}

	void ByteBuffer::finish()
	{
		int oldIndex = index;
		int oldNextSegmentAt = nextSegmentAt;
		nextSegmentAt = 0;
		int nrSeg = getNrOfSegments();
		for(int i = 0; i < nrSeg; i++)
		{
			index = 6;
			currentSegment = i;
			nextSegmentAt += memMap->getSegmentSize();
			WriteInt(nrSeg);
		}
		index = oldIndex;
		nextSegmentAt = oldNextSegmentAt;

	}


	/*ByteBuffer::ByteBuffer(char** buf, int nrSegs, int segSize)
    {
		index = 0;
        buffer = buf;
		segmentSize = segSize;
		nextSegmentAt = segmentSize;
		nrOfSegments = nrSegs; 
		currentSegment = -1;

		writeNewSegment();
    }*/
    
    ByteBuffer::~ByteBuffer()
    {
      
        //delete buffer;
    }
    void ByteBuffer::WriteChars(char* chars, int length)
    {
		//int bytesLeftInSegment = nextSegmentAt - index;
		int bytesLeftInSegment = memMap->getSegmentSize() - index;
		if(bytesLeftInSegment >= length)
		{
			memcpy((void*)(memMap->getSegment(currentSegment) + index), chars, length);
			index += length;
		}
		else
		{
			memcpy((void*)(memMap->getSegment(currentSegment) + index), chars, bytesLeftInSegment);
			index += bytesLeftInSegment;
			nextSegmentAt += memMap->getSegmentSize();
			currentSegment++;
			writeNewSegment();
			WriteChars(chars + bytesLeftInSegment, length - bytesLeftInSegment);
		}
        
    }

	void ByteBuffer::writeNewSegment()
	{
		index = 0;
		writeProtocol();
		int tInt = 0;
		WriteInt(tInt);//memMap->getNrOfSegments());
		WriteInt(currentSegment);

	}
	void ByteBuffer::readNewSegment()
	{
		index = 0;
		nextSegmentAt += memMap->getSegmentSize();
		//currentSegment++;
		bool ok = checkProtocol();
		int i1 = ReadInt();
		int i2 = ReadInt();

	}

    void ByteBuffer::ReadChars(char* chars, int length)
    {
        //int bytesLeftInSegment = nextSegmentAt - index;
		int bytesLeftInSegment = memMap->getSegmentSize() - index;
		if(bytesLeftInSegment >= length)
		{
			memcpy((void*)chars, memMap->getSegment(currentSegment) + index, length);
			index += length;
		}
		else
		{
			memcpy((void*)chars, memMap->getSegment(currentSegment) + index, bytesLeftInSegment);
			index += bytesLeftInSegment;
			currentSegment++;
			readNewSegment();
			ReadChars(chars + bytesLeftInSegment, length - bytesLeftInSegment);
		}
		
		//memcpy((void*)chars, buffer + index, length);
        //index += length;
        
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
    
    void ByteBuffer::WriteFloat(float& f)
    {
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)&f, 4); 
		#endif
        
		WriteChars(((char*)&f), 4);
		//memcpy((void*)(buffer + index), &f, 4);
        //index += 4;
        
    }
    void ByteBuffer::WriteInt(int& i)
    {
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)&i, 4);
		#endif
        WriteChars(((char*)&i), 4);
		//memcpy((void*)(buffer + index), &i, 4);
        //index += 4;
        
    }
    void ByteBuffer::WriteLong(long long& l)
    {
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)&l, 8);
		#endif
		WriteChars(((char*)&l), 8);
        //memcpy((void*)(buffer + index), &l, 8);
        //index += 8;
        
    }
    void ByteBuffer::WriteDouble(double& d)
    {
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)&d, 8);
		#endif
		WriteChars(((char*)&d), 8);
        //memcpy((void*)(buffer + index), &d, 8);
        //index += 8;
        
    }
    void ByteBuffer::WriteChar(char& c)
    {
		/*#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)&c, 1);
		#endif
        buffer[index] = c;
        index += 1;*/
		WriteChars(&c, 1);
        
    }
    void ByteBuffer::WriteString(std::string& s)
    {
		int siz = (int)s.size();
        WriteInt(siz);
		WriteChars((char*)s.c_str(), s.size());
		
		//memcpy((void*)(buffer + index), s.c_str(), s.size());
        //(char*)(buffer + index) = (char*)s.c_str();
        //index += (int)s.size();

        
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
        float ret = 0;
	
		ReadChars((char*)&ret, 4);	
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)&ret, 4);
		#endif
        return ret;
        
    }
    double ByteBuffer::ReadDouble()
    {
        double ret = 0;

        ReadChars((char*)&ret, 8);
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)&ret, 8);
		#endif
        return ret;
        
    }
    int ByteBuffer::ReadInt()
    {
        int ret = 0;
        ReadChars((char*)&ret, 4);

		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)&ret, 4);
		#endif
        return ret;
        
    }
    __int64 ByteBuffer::ReadLong()
    {
        __int64 ret = 0;
        ReadChars((char*)&ret, 8);
		#ifndef NETWORK_BYTE_ORDER
			ByteSwap((unsigned char*)&ret, 8);
		#endif
        return ret;
        
    }
    char ByteBuffer::ReadChar()
    {
        char ret = 0;

        ReadChars((char*)&ret, 1);

        return ret;
        
    }
    std::string ByteBuffer::ReadString()
    {
        
        //ByteSwap((unsigned char*)(buffer + index), 4);
        int length = ReadInt();
        char* text = new char[length];
		ReadChars(text, length);
        //text = (buffer + index);
		std::string ret(text, length);
        //std::string ret((buffer + index), length);
		//index += length;

		delete[] text;
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
				char ch = 0;
				out[i] ? ch = 1 : ch = 0;
				WriteChar(ch);
			}	
		}

		void ByteBuffer::ReadBytes(std::vector<char>& out)
		{
			int length = ReadInt();
			out.reserve(length);
			out.resize(length, 0);
			ReadBytes(out, 0, length);

		}

		void ByteBuffer::ReadBytes(std::vector<char>& out, int offset, int length)
		{
			//int bytesLeftInSegment = nextSegmentAt - index;
			int bytesLeftInSegment = memMap->getSegmentSize() - index;
			std::vector<char>::iterator it = out.begin();
			it += offset;
			if(bytesLeftInSegment > length)
			{
				//memcpy((void*)(buffer + index), chars, length);
				//index += length;
				std::copy(memMap->getSegment(currentSegment) + index, memMap->getSegment(currentSegment) + index + length, it);
				index += length;
			}
			else
			{
				//memcpy((void*)(buffer + index), chars, bytesLeftInSegment);
				//index += bytesLeftInSegment;
				
				//ReadBytes(out, offset, bytesLeftInSegment);

				std::copy(memMap->getSegment(currentSegment) + index, memMap->getSegment(currentSegment) + index + bytesLeftInSegment, it);
				index += bytesLeftInSegment;
				
				currentSegment++;
				readNewSegment();
				
				ReadBytes(out, offset + bytesLeftInSegment, length - bytesLeftInSegment);
				//WriteChars(chars + bytesLeftInSegment, length - bytesLeftInSegment);
			}

		}

		void ByteBuffer::WriteBytes(std::vector<char>& out)
		{
			int size = out.size();
			WriteInt(size);
			WriteBytes(out, 0, size);
			
		}
		void ByteBuffer::WriteBytes(std::vector<char>& out, int offset, int length)
		{
			//int bytesLeftInSegment = nextSegmentAt - index;
			int bytesLeftInSegment = memMap->getSegmentSize() - index;
			std::vector<char>::iterator it = out.begin();
			it += offset;
			if(bytesLeftInSegment > length)
			{
				//memcpy((void*)(buffer + index), chars, length);
				//index += length;
				std::copy(it, out.end(), memMap->getSegment(currentSegment) + index);
				index += length;
			}
			else
			{
				//memcpy((void*)(buffer + index), chars, bytesLeftInSegment);
				//index += bytesLeftInSegment;
				
				//WriteBytes(out, offset, bytesLeftInSegment);
				std::copy(it, it + bytesLeftInSegment, memMap->getSegment(currentSegment) + index);
				index += bytesLeftInSegment;
				
				nextSegmentAt += memMap->getSegmentSize();
				currentSegment++;
				writeNewSegment();
				
				WriteBytes(out, offset + bytesLeftInSegment, length - bytesLeftInSegment);
				//WriteChars(chars + bytesLeftInSegment, length - bytesLeftInSegment);
			}

			 
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
			WriteChars((char*)&out[0], size*8);
			/*for(int i = 0; i < size; i++)
			{
				WriteDouble(out[i]);
			}	*/
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
			WriteChars((char*)&out[0], size*4);
			/*for(int i = 0; i < size; i++)
			{
				WriteInt(out[i]);
			}*/	
		}
		void ByteBuffer::ReadFloats(std::vector<float>& out)
		{
			int size = ReadInt();
			out.reserve(size);
			out.resize(size, 0.0);
			ReadChars((char*)&out[0], size*4);
/*
			for(int i = 0; i < size; i++)
			{
				out[i] = ReadFloat();
			}*/			
			//std::copy((double*)buffer + index, (double*)buffer + index + size, out.begin());
			//index += size*8;

		}
		void ByteBuffer::WriteFloats(std::vector<float>& out)
		{
			int size = out.size();
			WriteInt(size);
			WriteChars((char*)&out[0], size*4);
			/*for(int i = 0; i < size; i++)
			{
				WriteFloat(out[i]);
			}	*/
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
			WriteChars((char*)&out[0], size*8);
			/*for(int i = 0; i < size; i++)
			{
				WriteLong(out[i]);
			}	*/
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
