#ifndef SendTransportH
#define	SendTransportH

#include "UDPSender.h"
#include "SendDiscoveryModule.h"
#include "OPSObjectHelper.h"
#include "AckData.h"
#include "AckDataHelper.h"


namespace ops
{
class SendTransport
{

public:
    static SendTransport* getDefaultTransport(std::string d);
	SendTransport(std::string domain);
    virtual ~SendTransport();
	
	void send(const char* bytes, int size, std::string topic);
    AckData sendWithAck(const char* bytes, int size, std::string topic, std::string destination, int timeout);

    std::string getSocketInterfaceID();


private:
	UDPSender sender;
    SendDiscoveryModule* sendDiscovery;
    static std::vector<SendTransport*> openTransports;

    std::string domain;
    std::string getDomain();
    bool containsDestination(const TopicInterfaceData& topicData, const std::string& dest);

    



};

}
#endif
