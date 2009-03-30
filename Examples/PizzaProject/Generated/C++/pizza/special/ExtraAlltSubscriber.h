#ifndef pizza_specialExtraAlltSubscriber_h
#define pizza_specialExtraAlltSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "ExtraAllt.h"


namespace pizza { namespace special {



class ExtraAlltSubscriber : public ops::Subscriber
{

public:
    ExtraAlltSubscriber(ops::Topic<ExtraAllt> t)
        : ops::Subscriber(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {

    }

    bool getData(ExtraAllt* d)
    {
        bool ret = firstDataReceived;
        ops::SafeLock lock(this);
        hasUnreadData = false;
        *d = narrowedData;
        return ret;
    }
    ExtraAllt getDataCopy()
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

    ~ExtraAlltSubscriber(void)
    {

    }
private:
    ExtraAllt narrowedData;
protected:
    //Override
    void saveCopy(ops::OPSObject* o)
    {
        ops::SafeLock lock(this);
        narrowedData = *((ExtraAllt*)o);
    }


};


}}


#endif
