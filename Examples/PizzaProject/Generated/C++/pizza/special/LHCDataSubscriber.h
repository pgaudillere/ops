#ifndef pizza_specialLHCDataSubscriber_h
#define pizza_specialLHCDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "LHCData.h"


namespace pizza { namespace special {



class LHCDataSubscriber : public ops::Subscriber
{

public:
    LHCDataSubscriber(ops::Topic<LHCData> t)
        : ops::Subscriber(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {

    }

    bool getData(LHCData* d)
    {
        bool ret = firstDataReceived;
        ops::SafeLock lock(this);
        hasUnreadData = false;
        *d = narrowedData;
        return ret;
    }
    LHCData getDataCopy()
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

    ~LHCDataSubscriber(void)
    {

    }
private:
    LHCData narrowedData;
protected:
    //Override
    void saveCopy(ops::OPSObject* o)
    {
        ops::SafeLock lock(this);
        narrowedData = *((LHCData*)o);
    }


};


}}


#endif
