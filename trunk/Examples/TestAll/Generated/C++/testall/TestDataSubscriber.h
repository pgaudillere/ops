#ifndef testallTestDataSubscriber_h
#define testallTestDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "TestData.h"


namespace testall {



class TestDataSubscriber : public ops::Subscriber
{

public:
    TestDataSubscriber(ops::Topic<> t)
        : ops::Subscriber(t)
    {

    }

    bool getData(TestData* d)
    {
        bool ret = firstDataReceived;
        ops::SafeLock lock(this);
        hasUnreadData = false;
        *d = narrowedData;
        return ret;
    }
    TestData getDataCopy()
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
    ~TestDataSubscriber(void)
    {

    }
private:
    TestData narrowedData;
protected:
    //Override
    void saveCopy(ops::OPSObject* o)
    {
        ops::SafeLock lock(this);
        narrowedData = *((TestData*)o);
    }


};


}


#endif
