//Auto generated OPS-code. DO NOT MODIFY!

#ifndef hello_HelloData_h
#define hello_HelloData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>

#include "ops/Reply.h"


namespace hello {


class HelloData :
	public ops::Reply
{
public:
   static std::string getTypeName(){return std::string("hello.HelloData");}
	
	std::string helloString;

    ///Default constructor.
    HelloData()
        : ops::Reply()
		
    {
        OPSObject::appendType(std::string("hello.HelloData"));


    }
    ///Copy-constructor making full deep copy of a(n) HelloData object.
    HelloData(const HelloData& __c)
       : ops::Reply()
		
    {
        OPSObject::appendType(std::string("hello.HelloData"));

        __c.fillClone((HelloData*)this);

    }
    ///Assignment operator making full deep copy of a(n) HelloData object.
    HelloData& operator = (const HelloData& other)
    {
        other.fillClone(this);
        return *this;
    }

    ///This method acceptes an ops::ArchiverInOut visitor which will serialize or deserialize an
    ///instance of this class to a format dictated by the implementation of the ArchiverInout.
    void serialize(ops::ArchiverInOut* archive)
    {
		ops::Reply::serialize(archive);
		archive->inout(std::string("helloString"), helloString);

    }
    //Returns a deep copy of this object.
    virtual ops::OPSObject* clone()
    {
		HelloData* ret = new HelloData;
		this->fillClone(ret);
		return ret;

    }

    virtual void fillClone(ops::OPSObject* obj) const
    {
		HelloData* narrRet = (HelloData*)obj;
		ops::Reply::fillClone(narrRet);
		narrRet->helloString = helloString;

    }

    ///Destructor: Note that all aggregated data and vectors are completely deleted.
    virtual ~HelloData(void)
    {

    }
    
};

}


#endif
