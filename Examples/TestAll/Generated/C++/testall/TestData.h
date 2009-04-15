//Auto generated OPS-code. DO NOT MODIFY!

#ifndef testall_TestData_h
#define testall_TestData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>



//Nested namespaces opener.
namespace testall {


class TestData :
	public ops::OPSObject
{
public:
	
	std::string text;
	double value;


    TestData()
        : ops::OPSObject()
		, value(0)
    {
        OPSObject::appendType(std::string("testall.TestData"));


    }
    virtual ~TestData(void)
    {

    }
    void serialize(ops::ArchiverInOut* archive)
    {
		ops::OPSObject::serialize(archive);
		archive->inout(std::string("text"), text);
		archive->inout(std::string("value"), value);

    }
    
};

//Close nested namespace
}


#endif
