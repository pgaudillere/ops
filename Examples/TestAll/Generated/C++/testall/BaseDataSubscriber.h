#ifndef testallBaseDataSubscriber_h
#define testallBaseDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "BaseData.h"


namespace testall {



class BaseDataSubscriber : public ops::Subscriber
{

public:
    BaseDataSubscriber(ops::Topic t)
        : ops::Subscriber(t)
    {

    }
/*
    bool getData(BaseData* d)
    {
        bool ret = firstDataReceived;
        ops::SafeLock lock(this);
        hasUnreadData = false;
        *d = narrowedData;
        return ret;
    }
    BaseData getDataCopy()
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
*/
    ~BaseDataSubscriber(void)
    {

    }
private:
    BaseData narrowedData;
protected:
    //Override
/*
    void saveCopy(ops::OPSObject* o)
    {
        ops::SafeLock lock(this);
        narrowedData = *((BaseData*)o);
    }
*/

};


}


#endif
