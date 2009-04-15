//Auto generated OPS-code. DO NOT MODIFY!

#ifndef testall_TestData_h
#define testall_TestData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>



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

    ///This method acceptes an ops::ArchiverInOut visitor which will serialize or deserialize an
    ///instance of this class to a format dictated by the implementation of the ArchiverInout.
    void serialize(ops::ArchiverInOut* archive)
    {
		ops::OPSObject::serialize(archive);
		archive->inout(std::string("text"), text);
		archive->inout(std::string("value"), value);

    }

    ///Destructor: Note that all aggregated data and vectors are completely deleted.
    virtual ~TestData(void)
    {

    }
    
};

}


#endif
