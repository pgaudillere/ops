#ifndef opstestByteArrayDataSubscriber_h
#define opstestByteArrayDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "ByteArrayData.h"
#include "ByteArrayDataHelper.h"

namespace opstest
{


class ByteArrayDataSubscriber : public ops::Subscriber
{

public:
    ByteArrayDataSubscriber(ops::Topic<ByteArrayData> t)
        : ops::Subscriber(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {
        setObjectHelper(new ByteArrayDataHelper());


    }

    bool getData(ByteArrayData* d)
    {
        bool ret = firstDataReceived;
        ops::SafeLock lock(this);
        hasUnreadData = false;
        *d = narrowedData;
        return ret;
    }
    ByteArrayData getDataCopy()
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

    ~ByteArrayDataSubscriber(void)
    {

    }
private:
    ByteArrayData narrowedData;
protected:
    //Override
    void saveCopy(ops::OPSObject* o)
    {
        ops::SafeLock lock(this);
        narrowedData = *((ByteArrayData*)o);
    }


};
}



#endif
