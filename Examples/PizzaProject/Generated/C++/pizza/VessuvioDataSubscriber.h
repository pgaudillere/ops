#ifndef pizzaVessuvioDataSubscriber_h
#define pizzaVessuvioDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "VessuvioData.h"


namespace pizza {



class VessuvioDataSubscriber : public ops::Subscriber
{

public:
    VessuvioDataSubscriber(ops::Topic<VessuvioData> t)
        : ops::Subscriber(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {

    }

    bool getData(VessuvioData* d)
    {
        bool ret = firstDataReceived;
        ops::SafeLock lock(this);
        hasUnreadData = false;
        *d = narrowedData;
        return ret;
    }
    VessuvioData getDataCopy()
    {
        ops::SafeLock lock(this);
        hasUnreadData = false;
        return narrowedData;
    }

    ops::OPSObject* getDataReference()
    {
        hasUnreadData = false;
        return &narrowedData;
    }

    ~VessuvioDataSubscriber(void)
    {

    }
private:
    VessuvioData narrowedData;
protected:
    //Override
    void saveCopy(ops::OPSObject* o)
    {
        ops::SafeLock lock(this);
        narrowedData = *((VessuvioData*)o);
    }


};


}


#endif
