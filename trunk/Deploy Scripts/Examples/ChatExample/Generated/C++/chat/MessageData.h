//Auto generated OPS-code. DO NOT MODIFY!

#ifndef chat_MessageData_h
#define chat_MessageData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>



namespace chat {


class MessageData :
	public ops::OPSObject
{
public:
   static std::string getTypeName(){return std::string("chat.MessageData");}
	
	std::string message;
	__int64 timeStamp;

    ///Default constructor.
    MessageData()
        : ops::OPSObject()
		, timeStamp(0)
    {
        OPSObject::appendType(std::string("chat.MessageData"));


    }
    ///Copy-constructor making full deep copy of a(n) MessageData object.
    MessageData(const MessageData& __c)
       : ops::OPSObject()
		, timeStamp(0)
    {
        OPSObject::appendType(std::string("chat.MessageData"));

        __c.fillClone((MessageData*)this);

    }
    ///Assignment operator making full deep copy of a(n) MessageData object.
    MessageData& operator = (const MessageData& other)
    {
        other.fillClone(this);
        return *this;
    }

    ///This method acceptes an ops::ArchiverInOut visitor which will serialize or deserialize an
    ///instance of this class to a format dictated by the implementation of the ArchiverInout.
    void serialize(ops::ArchiverInOut* archive)
    {
		ops::OPSObject::serialize(archive);
		archive->inout(std::string("message"), message);
		archive->inout(std::string("timeStamp"), timeStamp);

    }
    //Returns a deep copy of this object.
    virtual ops::OPSObject* clone()
    {
		MessageData* ret = new MessageData;
		this->fillClone(ret);
		return ret;

    }

    virtual void fillClone(ops::OPSObject* obj) const
    {
		MessageData* narrRet = (MessageData*)obj;
		ops::OPSObject::fillClone(narrRet);
		narrRet->message = message;
		narrRet->timeStamp = timeStamp;

    }

    ///Destructor: Note that all aggregated data and vectors are completely deleted.
    virtual ~MessageData(void)
    {

    }
    
};

}


#endif
