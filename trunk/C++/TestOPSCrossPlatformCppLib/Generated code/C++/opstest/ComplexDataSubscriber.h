#ifndef opstestComplexDataSubscriber_h
#define opstestComplexDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "Transport.h"
#include "OPSObject.h"
#include "ComplexData.h"
#include "ComplexDataHelper.h"

namespace opstest
{


class ComplexDataSubscriber : public ops::Subscriber
{

public:
    ComplexDataSubscriber(ops::Topic<ComplexData> t)
        : ops::Subscriber(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {
        setObjectHelper(new ComplexDataHelper());


    }

    bool getData(ComplexData* d)
    {
        bool ret = firstDataReceived;
        ops::SafeLock lock(this);
        hasUnreadData = false;
        *d = narrowedData;
        return ret;
    }
    ComplexData getDataCopy()
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

    ~ComplexDataSubscriber(void)
    {

    }
private:
    ComplexData narrowedData;
protected:
    //Override
    void saveCopy(ops::OPSObject* o)
    {
        ops::SafeLock lock(this);
        narrowedData = *((ComplexData*)o);
    }


};
}



#endif
