//Auto generated OPS-code. DO NOT MODIFY!

#ifndef chat_ExtendedUserData_h
#define chat_ExtendedUserData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>

#include "UserData.h"


namespace chat {


class ExtendedUserData :
	public UserData
{
public:
   static std::string getTypeName(){return std::string("chat.ExtendedUserData");}
	
	std::string nickname;
	std::string email;
	std::string telephone;
	std::string profileImageUrl;

    ///Default constructor.
    ExtendedUserData()
        : UserData()
		
    {
        OPSObject::appendType(std::string("chat.ExtendedUserData"));


    }
    ///Copy-constructor making full deep copy of a(n) ExtendedUserData object.
    ExtendedUserData(const ExtendedUserData& __c)
       : UserData()
		
    {
        OPSObject::appendType(std::string("chat.ExtendedUserData"));

        __c.fillClone((ExtendedUserData*)this);

    }
    ///Assignment operator making full deep copy of a(n) ExtendedUserData object.
    ExtendedUserData& operator = (const ExtendedUserData& other)
    {
        other.fillClone(this);
        return *this;
    }

    ///This method acceptes an ops::ArchiverInOut visitor which will serialize or deserialize an
    ///instance of this class to a format dictated by the implementation of the ArchiverInout.
    void serialize(ops::ArchiverInOut* archive)
    {
		UserData::serialize(archive);
		archive->inout(std::string("nickname"), nickname);
		archive->inout(std::string("email"), email);
		archive->inout(std::string("telephone"), telephone);
		archive->inout(std::string("profileImageUrl"), profileImageUrl);

    }
    //Returns a deep copy of this object.
    virtual ops::OPSObject* clone()
    {
		ExtendedUserData* ret = new ExtendedUserData;
		this->fillClone(ret);
		return ret;

    }

    virtual void fillClone(ops::OPSObject* obj) const
    {
		ExtendedUserData* narrRet = (ExtendedUserData*)obj;
		UserData::fillClone(narrRet);
		narrRet->nickname = nickname;
		narrRet->email = email;
		narrRet->telephone = telephone;
		narrRet->profileImageUrl = profileImageUrl;

    }

    ///Destructor: Note that all aggregated data and vectors are completely deleted.
    virtual ~ExtendedUserData(void)
    {

    }
    
};

}


#endif
