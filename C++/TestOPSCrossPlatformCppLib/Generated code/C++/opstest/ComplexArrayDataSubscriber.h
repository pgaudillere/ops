#ifndef opstestComplexArrayDataSubscriber_h
#define opstestComplexArrayDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "Transport.h"
#include "OPSObject.h"
#include "ComplexArrayData.h"
#include "ComplexArrayDataHelper.h"

namespace opstest
{


class ComplexArrayDataSubscriber : public ops::Subscriber
{

public:
    ComplexArrayDataSubscriber(ops::Topic<ComplexArrayData> t)
        : ops::Subscriber(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {
        setObjectHelper(new ComplexArrayDataHelper());


    }

    bool getData(ComplexArrayData* d)
    {
        bool ret = firstDataReceived;
        ops::SafeLock lock(this);
        hasUnreadData = false;
        *d = narrowedData;
        return ret;
    }
    ComplexArrayData getDataCopy()
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

    ~ComplexArrayDataSubscriber(void)
    {

    }
private:
    ComplexArrayData narrowedData;
protected:
    //Override
    void saveCopy(ops::OPSObject* o)
    {
        ops::SafeLock lock(this);
        narrowedData = *((ComplexArrayData*)o);
    }


};
}



#endif
