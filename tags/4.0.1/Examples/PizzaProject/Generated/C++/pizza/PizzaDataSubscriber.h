#ifndef pizzaPizzaDataSubscriber_h
#define pizzaPizzaDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "PizzaData.h"


namespace pizza {



class PizzaDataSubscriber : public ops::Subscriber
{

public:
    PizzaDataSubscriber(ops::Topic<PizzaData> t)
        : ops::Subscriber(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {

    }

    bool getData(PizzaData* d)
    {
        bool ret = firstDataReceived;
        ops::SafeLock lock(this);
        hasUnreadData = false;
        *d = narrowedData;
        return ret;
    }
    PizzaData getDataCopy()
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

    ~PizzaDataSubscriber(void)
    {

    }
private:
    PizzaData narrowedData;
protected:
    //Override
    void saveCopy(ops::OPSObject* o)
    {
        ops::SafeLock lock(this);
        narrowedData = *((PizzaData*)o);
    }


};


}


#endif
