#ifndef TestAllTestDataSubscriber_h
#define TestAllTestDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "TestData.h"


namespace TestAll {



class TestDataSubscriber : public ops::Subscriber
{

public:
    TestDataSubscriber(ops::Topic t)
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
    TestData getDataCopy()
    {
        ops::SafeLock lock(this);
        hasUnreadData = false;
        return narrowedData;
    }
*/
    TestData* getTypedDataReference()
    {
        return (TestData*)getDataReference();
    }

    ~TestDataSubscriber(void)
    {

    }
private:
    TestData narrowedData;
protected:
    //Override
/*
    void saveCopy(ops::OPSObject* o)
    {
        ops::SafeLock lock(this);
        narrowedData = *((TestData*)o);
    }
*/

};


}


#endif
