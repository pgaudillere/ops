//Auto generated OPS-code. DO NOT MODIFY!

#ifndef opsDataHeader_h
#define opsDataHeader_h

#include "OPSObject.h"
#include <string>
#include <vector>



namespace ops
{
class DataHeader :
	public ops::OPSObject
{
public:
	
    char messageType;
    char endianness;
    char publisherPriority;
    int nrOfSegments;
    int segment;
    int port;
    int dataSize;
    __int64 qosMask;
    __int64 publicationID;
    std::string publisherID;
    std::string topicName;
    std::string topLevelKey;
    std::string address;
    

    DataHeader()
        : ops::OPSObject()
    {
        
        messageType = 0;
        endianness = 0;
        publisherPriority = 0;
        nrOfSegments = 0;
        segment = 0;
        port = 0;
        dataSize = 0;
        qosMask = 0;
        publicationID = 0;
        publisherID = "";
        topicName = "";
        topLevelKey = "";
        address = "";
        

    }
    std::string GetTypeID()
    {
        return "ops.DataHeader";
    }

    ~DataHeader(void)
    {
        
    }
    
};
}

#endif
