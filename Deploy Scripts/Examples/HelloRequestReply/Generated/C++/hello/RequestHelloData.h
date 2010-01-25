//Auto generated OPS-code. DO NOT MODIFY!

#ifndef hello_RequestHelloData_h
#define hello_RequestHelloData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>

#include "ops/Request.h"


namespace hello {


class RequestHelloData :
	public ops::Request
{
public:
   static std::string getTypeName(){return std::string("hello.RequestHelloData");}
	
	std::string requestersName;

    ///Default constructor.
    RequestHelloData()
        : ops::Request()
		
    {
        OPSObject::appendType(std::string("hello.RequestHelloData"));


    }
    ///Copy-constructor making full deep copy of a(n) RequestHelloData object.
    RequestHelloData(const RequestHelloData& __c)
       : ops::Request()
		
    {
        OPSObject::appendType(std::string("hello.RequestHelloData"));

        __c.fillClone((RequestHelloData*)this);

    }
    ///Assignment operator making full deep copy of a(n) RequestHelloData object.
    RequestHelloData& operator = (const RequestHelloData& other)
    {
        other.fillClone(this);
        return *this;
    }

    ///This method acceptes an ops::ArchiverInOut visitor which will serialize or deserialize an
    ///instance of this class to a format dictated by the implementation of the ArchiverInout.
    void serialize(ops::ArchiverInOut* archive)
    {
		ops::Request::serialize(archive);
		archive->inout(std::string("requestersName"), requestersName);

    }
    //Returns a deep copy of this object.
    virtual ops::OPSObject* clone()
    {
		RequestHelloData* ret = new RequestHelloData;
		this->fillClone(ret);
		return ret;

    }

    virtual void fillClone(ops::OPSObject* obj) const
    {
		RequestHelloData* narrRet = (RequestHelloData*)obj;
		ops::Request::fillClone(narrRet);
		narrRet->requestersName = requestersName;

    }

    ///Destructor: Note that all aggregated data and vectors are completely deleted.
    virtual ~RequestHelloData(void)
    {

    }
    
};

}


#endif
