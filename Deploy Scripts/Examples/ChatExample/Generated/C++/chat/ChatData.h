//Auto generated OPS-code. DO NOT MODIFY!

#ifndef chat_ChatData_h
#define chat_ChatData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>

#include "MessageData.h"
#include "UserData.h"


namespace chat {


class ChatData :
	public ops::OPSObject
{
public:
   static std::string getTypeName(){return std::string("chat.ChatData");}
	
	UserData* sender;
	MessageData* messageData;

    ///Default constructor.
    ChatData()
        : ops::OPSObject()
		
    {
        OPSObject::appendType(std::string("chat.ChatData"));
		sender = new UserData;
		messageData = new MessageData;


    }
    ///Copy-constructor making full deep copy of a(n) ChatData object.
    ChatData(const ChatData& __c)
       : ops::OPSObject()
		
    {
        OPSObject::appendType(std::string("chat.ChatData"));
		sender = new UserData;
		messageData = new MessageData;

        __c.fillClone((ChatData*)this);

    }
    ///Assignment operator making full deep copy of a(n) ChatData object.
    ChatData& operator = (const ChatData& other)
    {
        other.fillClone(this);
        return *this;
    }

    ///This method acceptes an ops::ArchiverInOut visitor which will serialize or deserialize an
    ///instance of this class to a format dictated by the implementation of the ArchiverInout.
    void serialize(ops::ArchiverInOut* archive)
    {
		ops::OPSObject::serialize(archive);
		sender = (UserData*) archive->inout(std::string("sender"), sender);
		messageData = (MessageData*) archive->inout(std::string("messageData"), messageData);

    }
    //Returns a deep copy of this object.
    virtual ops::OPSObject* clone()
    {
		ChatData* ret = new ChatData;
		this->fillClone(ret);
		return ret;

    }

    virtual void fillClone(ops::OPSObject* obj) const
    {
		ChatData* narrRet = (ChatData*)obj;
		ops::OPSObject::fillClone(narrRet);
		if(narrRet->sender) delete narrRet->sender;
		narrRet->sender = (UserData*)sender->clone();
		if(narrRet->messageData) delete narrRet->messageData;
		narrRet->messageData = (MessageData*)messageData->clone();

    }

    ///Destructor: Note that all aggregated data and vectors are completely deleted.
    virtual ~ChatData(void)
    {
		if(sender) delete sender;
		if(messageData) delete messageData;

    }
    
};

}


#endif
