#ifndef testallChildDataSubscriber_h
#define testallChildDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "ChildData.h"


namespace testall {



class ChildDataSubscriber : public ops::Subscriber
{

public:
    ChildDataSubscriber(ops::Topic<ChildData> t)
        : ops::Subscriber(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {

    }

    bool getData(ChildData* d)
    {
        bool ret = firstDataReceived;
        ops::SafeLock lock(this);
        hasUnreadData = false;
        *d = narrowedData;
        return ret;
    }
    ChildData getDataCopy()
    {
        ops::SafeLock lock(this);
        hasUnreadData = false;
        return narrowedData;
    }
/*
    ops::OPSObject* getDataReference()
    {
        hasUnreadData = false;
        return &narrowedData;
    }
*/
    ~ChildDataSubscriber(void)
    {

    }
private:
    ChildData narrowedData;
protected:
    //Override
    void saveCopy(ops::OPSObject* o)
    {
        ops::SafeLock lock(this);
        narrowedData = *((ChildData*)o);
    }


};


}


#endif
