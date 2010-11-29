#ifndef chatUserDataSubscriber_h
#define chatUserDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "UserData.h"


namespace chat {



class UserDataSubscriber : public ops::Subscriber
{

public:
    UserDataSubscriber(ops::Topic t)
        : ops::Subscriber(t)
    {

    }

    bool getData(UserData* d)
    {
        if(!data) return false;
        aquireMessageLock();
		data->fillClone(d);
		releaseMessageLock();
        return true;
    }

    UserData* getTypedDataReference()
    {
        return (UserData*)getDataReference();
    }

    ~UserDataSubscriber(void)
    {

    }
private:
    UserData narrowedData;

};


}


#endif
