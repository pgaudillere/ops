#ifndef chatExtendedUserDataSubscriber_h
#define chatExtendedUserDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "ExtendedUserData.h"


namespace chat {



class ExtendedUserDataSubscriber : public ops::Subscriber
{

public:
    ExtendedUserDataSubscriber(ops::Topic t)
        : ops::Subscriber(t)
    {

    }

    bool getData(ExtendedUserData* d)
    {
        if(!data) return false;
        aquireMessageLock();
		data->fillClone(d);
		releaseMessageLock();
        return true;
    }

    ExtendedUserData* getTypedDataReference()
    {
        return (ExtendedUserData*)getDataReference();
    }

    ~ExtendedUserDataSubscriber(void)
    {

    }
private:
    ExtendedUserData narrowedData;

};


}


#endif
