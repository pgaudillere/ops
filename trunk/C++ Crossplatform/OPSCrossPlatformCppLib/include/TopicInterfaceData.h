//Auto generated OPS-code. DO NOT MODIFY!

#ifndef opsTopicInterfaceData_h
#define opsTopicInterfaceData_h

#include "OPSObject.h"
#include <string>
#include <vector>



namespace ops
{
class TopicInterfaceData :
	public ops::OPSObject
{
public:
	
    bool hasReliableSubscribers;
    int port;
    int timebaseSeparation;
    std::string address;
    std::string topicName;
    std::string participantName;
    std::vector<std::string> keys;
    std::vector<std::string> reliableIdentities;
    

    TopicInterfaceData()
        : ops::OPSObject()
    {
        
        hasReliableSubscribers = 0;
        port = 0;
        timebaseSeparation = 0;
        address = "";
        topicName = "";
        participantName = "";
        

    }
    std::string GetTypeID()
    {
        return "ops.TopicInterfaceData";
    }

    ~TopicInterfaceData(void)
    {
                keys.clear();
        reliableIdentities.clear();

    }
    
};
}

#endif
