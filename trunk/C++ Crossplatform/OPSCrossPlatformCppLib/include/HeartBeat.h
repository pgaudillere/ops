//Auto generated OPS-code. DO NOT MODIFY!

#ifndef opsHeartBeat_h
#define opsHeartBeat_h

#include "OPSObject.h"
#include <string>
#include <vector>



namespace ops
{
class HeartBeat :
	public ops::OPSObject
{
public:
	
    char messageType;
    char endianness;
    int highestSegment;
    int port;
    __int64 qosMask;
    __int64 highestPublicationID;
    std::string subscriberID;
    std::string topicName;
    std::string topLevelKey;
    std::string address;
    

    HeartBeat()
        : ops::OPSObject()
    {
        
        messageType = 0;
        endianness = 0;
        highestSegment = 0;
        port = 0;
        qosMask = 0;
        highestPublicationID = 0;
        subscriberID = "";
        topicName = "";
        topLevelKey = "";
        address = "";
        

    }
    std::string GetTypeID()
    {
        return "ops.HeartBeat";
    }

    ~HeartBeat(void)
    {
        
    }
    
};
}

#endif
