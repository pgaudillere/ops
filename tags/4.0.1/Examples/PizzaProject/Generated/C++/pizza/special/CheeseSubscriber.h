#ifndef pizza_specialCheeseSubscriber_h
#define pizza_specialCheeseSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "Cheese.h"


namespace pizza { namespace special {



class CheeseSubscriber : public ops::Subscriber
{

public:
    CheeseSubscriber(ops::Topic<Cheese> t)
        : ops::Subscriber(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {

    }

    bool getData(Cheese* d)
    {
        bool ret = firstDataReceived;
        ops::SafeLock lock(this);
        hasUnreadData = false;
        *d = narrowedData;
        return ret;
    }
    Cheese getDataCopy()
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

    ~CheeseSubscriber(void)
    {

    }
private:
    Cheese narrowedData;
protected:
    //Override
    void saveCopy(ops::OPSObject* o)
    {
        ops::SafeLock lock(this);
        narrowedData = *((Cheese*)o);
    }


};


}}


#endif
