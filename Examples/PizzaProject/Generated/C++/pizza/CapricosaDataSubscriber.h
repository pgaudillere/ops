#ifndef pizzaCapricosaDataSubscriber_h
#define pizzaCapricosaDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "CapricosaData.h"


namespace pizza {



class CapricosaDataSubscriber : public ops::Subscriber
{

public:
    CapricosaDataSubscriber(ops::Topic<CapricosaData> t)
        : ops::Subscriber(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {

    }

    bool getData(CapricosaData* d)
    {
        bool ret = firstDataReceived;
        ops::SafeLock lock(this);
        hasUnreadData = false;
        *d = narrowedData;
        return ret;
    }
    CapricosaData getDataCopy()
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

    ~CapricosaDataSubscriber(void)
    {

    }
private:
    CapricosaData narrowedData;
protected:
    //Override
    void saveCopy(ops::OPSObject* o)
    {
        ops::SafeLock lock(this);
        narrowedData = *((CapricosaData*)o);
    }


};


}


#endif
