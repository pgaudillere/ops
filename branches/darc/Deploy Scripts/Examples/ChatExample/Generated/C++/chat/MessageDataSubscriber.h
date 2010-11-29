#ifndef chatMessageDataSubscriber_h
#define chatMessageDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "MessageData.h"


namespace chat {



class MessageDataSubscriber : public ops::Subscriber
{

public:
    MessageDataSubscriber(ops::Topic t)
        : ops::Subscriber(t)
    {

    }

    bool getData(MessageData* d)
    {
        if(!data) return false;
        aquireMessageLock();
		data->fillClone(d);
		releaseMessageLock();
        return true;
    }

    MessageData* getTypedDataReference()
    {
        return (MessageData*)getDataReference();
    }

    ~MessageDataSubscriber(void)
    {

    }
private:
    MessageData narrowedData;

};


}


#endif
