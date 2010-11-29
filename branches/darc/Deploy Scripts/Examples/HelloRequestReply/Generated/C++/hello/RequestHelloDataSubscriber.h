#ifndef helloRequestHelloDataSubscriber_h
#define helloRequestHelloDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "RequestHelloData.h"


namespace hello {



class RequestHelloDataSubscriber : public ops::Subscriber
{

public:
    RequestHelloDataSubscriber(ops::Topic t)
        : ops::Subscriber(t)
    {

    }

    bool getData(RequestHelloData* d)
    {
        if(!data) return false;
        aquireMessageLock();
		data->fillClone(d);
		releaseMessageLock();
        return true;
    }

    RequestHelloData* getTypedDataReference()
    {
        return (RequestHelloData*)getDataReference();
    }

    ~RequestHelloDataSubscriber(void)
    {

    }
private:
    RequestHelloData narrowedData;

};


}


#endif
