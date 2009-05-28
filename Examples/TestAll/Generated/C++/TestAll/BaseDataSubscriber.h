#ifndef TestAllBaseDataSubscriber_h
#define TestAllBaseDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "BaseData.h"


namespace TestAll {



class BaseDataSubscriber : public ops::Subscriber
{

public:
    BaseDataSubscriber(ops::Topic t)
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
    BaseData getDataCopy()
    {
        ops::SafeLock lock(this);
        hasUnreadData = false;
        return narrowedData;
    }
*/
    BaseData* getTypedDataReference()
    {
        return (BaseData*)getDataReference();
    }

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
