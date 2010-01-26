#ifndef chatExtendedChatDataSubscriber_h
#define chatExtendedChatDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "ExtendedChatData.h"


namespace chat {



class ExtendedChatDataSubscriber : public ops::Subscriber
{

public:
    ExtendedChatDataSubscriber(ops::Topic t)
        : ops::Subscriber(t)
    {

    }

    bool getData(ExtendedChatData* d)
    {
        if(!data) return false;
        aquireMessageLock();
		data->fillClone(d);
		releaseMessageLock();
        return true;
    }

    ExtendedChatData* getTypedDataReference()
    {
        return (ExtendedChatData*)getDataReference();
    }

    ~ExtendedChatDataSubscriber(void)
    {

    }
private:
    ExtendedChatData narrowedData;

};


}


#endif
