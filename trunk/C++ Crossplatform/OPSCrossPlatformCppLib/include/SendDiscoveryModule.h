#ifndef ops_SendDiscoveryModuleH
#define	ops_SendDiscoveryModuleH

#include <vector>
#include <string>


//#include "TopicInterfaceDataSubscriber.h"

#include "MulticastReceiver.h"
#include <boost/thread/mutex.hpp>
#include "Thread.h"
#include "TopicInterface.h"
#include "TopicInterfaceDataHelper.h"



namespace ops
{
class SendDiscoveryModule : public Thread
{
    friend class SendTransport;
public:
	SendDiscoveryModule(std::string domainAddress);
    virtual ~SendDiscoveryModule();
    void updateInterfaces(TopicInterfaceData inter);

	void run();


private:

	MulticastReceiver mcReceiver;
    std::vector<TopicInterface> topicInterfaces;
    void removeInactiveInterfaces();
	bool keepRunning;
	TopicInterfaceDataHelper helper;
	boost::mutex mutex;
    //std::map<std::string, std::vector<TopicInterface> > topicInterfaceMap;


};

}
#endif





