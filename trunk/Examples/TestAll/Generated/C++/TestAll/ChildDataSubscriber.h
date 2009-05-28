#ifndef TestAllChildDataSubscriber_h
#define TestAllChildDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "ChildData.h"


namespace TestAll {



class ChildDataSubscriber : public ops::Subscriber
{

public:
    ChildDataSubscriber(ops::Topic t)
        : ops::Subscriber(t)
    {

    }

    bool getData(ChildData* d)
    {
        if(!data) return false;
        aquireMessageLock();
		data->fillClone(d);
		releaseMessageLock();
        return true;
    }
/*
    ChildData getDataCopy()
    {
        ops::SafeLock lock(this);
        hasUnreadData = false;
        return narrowedData;
    }
*/
    ChildData* getTypedDataReference()
    {
        return (ChildData*)getDataReference();
    }

    ~ChildDataSubscriber(void)
    {

    }
private:
    ChildData narrowedData;
protected:
    //Override
/*
    void saveCopy(ops::OPSObject* o)
    {
        ops::SafeLock lock(this);
        narrowedData = *((ChildData*)o);
    }
*/

};


}


#endif
