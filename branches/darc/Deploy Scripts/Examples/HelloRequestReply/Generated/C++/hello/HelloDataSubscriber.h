#ifndef helloHelloDataSubscriber_h
#define helloHelloDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "HelloData.h"


namespace hello {



class HelloDataSubscriber : public ops::Subscriber
{

public:
    HelloDataSubscriber(ops::Topic t)
        : ops::Subscriber(t)
    {

    }

    bool getData(HelloData* d)
    {
        if(!data) return false;
        aquireMessageLock();
		data->fillClone(d);
		releaseMessageLock();
        return true;
    }

    HelloData* getTypedDataReference()
    {
        return (HelloData*)getDataReference();
    }

    ~HelloDataSubscriber(void)
    {

    }
private:
    HelloData narrowedData;

};


}


#endif
