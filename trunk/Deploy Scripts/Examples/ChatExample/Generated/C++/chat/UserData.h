//Auto generated OPS-code. DO NOT MODIFY!

#ifndef chat_UserData_h
#define chat_UserData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>



namespace chat {


class UserData :
	public ops::OPSObject
{
public:
   static std::string getTypeName(){return std::string("chat.UserData");}
	
	std::string name;

    ///Default constructor.
    UserData()
        : ops::OPSObject()
		
    {
        OPSObject::appendType(std::string("chat.UserData"));


    }
    ///Copy-constructor making full deep copy of a(n) UserData object.
    UserData(const UserData& __c)
       : ops::OPSObject()
		
    {
        OPSObject::appendType(std::string("chat.UserData"));

        __c.fillClone((UserData*)this);

    }
    ///Assignment operator making full deep copy of a(n) UserData object.
    UserData& operator = (const UserData& other)
    {
        other.fillClone(this);
        return *this;
    }

    ///This method acceptes an ops::ArchiverInOut visitor which will serialize or deserialize an
    ///instance of this class to a format dictated by the implementation of the ArchiverInout.
    void serialize(ops::ArchiverInOut* archive)
    {
		ops::OPSObject::serialize(archive);
		archive->inout(std::string("name"), name);

    }
    //Returns a deep copy of this object.
    virtual ops::OPSObject* clone()
    {
		UserData* ret = new UserData;
		this->fillClone(ret);
		return ret;

    }

    virtual void fillClone(ops::OPSObject* obj) const
    {
		UserData* narrRet = (UserData*)obj;
		ops::OPSObject::fillClone(narrRet);
		narrRet->name = name;

    }

    ///Destructor: Note that all aggregated data and vectors are completely deleted.
    virtual ~UserData(void)
    {

    }
    
};

}


#endif
