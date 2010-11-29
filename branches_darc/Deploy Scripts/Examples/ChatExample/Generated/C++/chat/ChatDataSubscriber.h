#ifndef chatChatDataSubscriber_h
#define chatChatDataSubscriber_h

#include "Subscriber.h"
#include "Topic.h"
#include "OPSObject.h"
#include "ChatData.h"


namespace chat {



class ChatDataSubscriber : public ops::Subscriber
{

public:
    ChatDataSubscriber(ops::Topic t)
        : ops::Subscriber(t)
    {

    }

    bool getData(ChatData* d)
    {
        if(!data) return false;
        aquireMessageLock();
		data->fillClone(d);
		releaseMessageLock();
        return true;
    }

    ChatData* getTypedDataReference()
    {
        return (ChatData*)getDataReference();
    }

    ~ChatDataSubscriber(void)
    {

    }
private:
    ChatData narrowedData;

};


}


#endif
