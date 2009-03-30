#ifndef ops_ReceiveTransportH
#define	ops_ReceiveTransportH

#include <vector>
#include <string>

namespace ops
{
////Forward declaration////
class SubscriberHandler;///
///////////////////////////

class ReceiveTransport 
{

public:
	virtual ~ReceiveTransport(){}
	virtual void addSubscriberHandler(SubscriberHandler* listener) = 0;
    virtual void removeSubscriberHandler(SubscriberHandler* handler) = 0;
    virtual void run() = 0;
    virtual std::string getDomain() = 0;

};

}
#endif
