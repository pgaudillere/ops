//Auto generated OPS-code. DO NOT MODIFY!

#ifndef testall_BaseData_h
#define testall_BaseData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>



//Nested namespaces opener.
namespace testall {


class BaseData :
	public ops::OPSObject
{
public:
	
	std::string baseText;


    BaseData()
        : ops::OPSObject()

    {
        OPSObject::appendType(std::string("testall.BaseData"));


    }
    virtual ~BaseData(void)
    {

    }
    void serialize(ops::ArchiverInOut* archive)
    {
		ops::OPSObject::serialize(archive);
		baseText = archive->inout(std::string("baseText"), baseText);

    }
    
};

//Close nested namespace
}


#endif
