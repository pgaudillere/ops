//Auto generated OPS-code. DO NOT MODIFY!

#ifndef chat_ExtendedChatData_h
#define chat_ExtendedChatData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>

#include "ChatData.h"


namespace chat {


class ExtendedChatData :
	public ChatData
{
public:
   static std::string getTypeName(){return std::string("chat.ExtendedChatData");}
	
	std::vector<std::string> attachments;

    ///Default constructor.
    ExtendedChatData()
        : ChatData()
		
    {
        OPSObject::appendType(std::string("chat.ExtendedChatData"));


    }
    ///Copy-constructor making full deep copy of a(n) ExtendedChatData object.
    ExtendedChatData(const ExtendedChatData& __c)
       : ChatData()
		
    {
        OPSObject::appendType(std::string("chat.ExtendedChatData"));

        __c.fillClone((ExtendedChatData*)this);

    }
    ///Assignment operator making full deep copy of a(n) ExtendedChatData object.
    ExtendedChatData& operator = (const ExtendedChatData& other)
    {
        other.fillClone(this);
        return *this;
    }

    ///This method acceptes an ops::ArchiverInOut visitor which will serialize or deserialize an
    ///instance of this class to a format dictated by the implementation of the ArchiverInout.
    void serialize(ops::ArchiverInOut* archive)
    {
		ChatData::serialize(archive);
		archive->inout(std::string("attachments"), attachments);

    }
    //Returns a deep copy of this object.
    virtual ops::OPSObject* clone()
    {
		ExtendedChatData* ret = new ExtendedChatData;
		this->fillClone(ret);
		return ret;

    }

    virtual void fillClone(ops::OPSObject* obj) const
    {
		ExtendedChatData* narrRet = (ExtendedChatData*)obj;
		ChatData::fillClone(narrRet);
		narrRet->attachments = attachments;

    }

    ///Destructor: Note that all aggregated data and vectors are completely deleted.
    virtual ~ExtendedChatData(void)
    {

    }
    
};

}


#endif
