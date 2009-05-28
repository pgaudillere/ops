//Auto generated OPS-code. DO NOT MODIFY!

#ifndef TestAll_TestData_h
#define TestAll_TestData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>



namespace TestAll {


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
        OPSObject::appendType(std::string("TestAll.TestData"));


    }

    ///This method acceptes an ops::ArchiverInOut visitor which will serialize or deserialize an
    ///instance of this class to a format dictated by the implementation of the ArchiverInout.
    void serialize(ops::ArchiverInOut* archive)
    {
		ops::OPSObject::serialize(archive);
		archive->inout(std::string("text"), text);
		archive->inout(std::string("value"), value);

    }
    //Returns a deep copy of this object.
    virtual ops::OPSObject* clone()
    {
		TestData* ret = new TestData;
		this->fillClone(ret);
		return ret;

    }

    virtual void fillClone(ops::OPSObject* obj)
    {
		TestData* narrRet = (TestData*)obj;
		ops::OPSObject::fillClone(narrRet);
		narrRet->text = text;
		narrRet->value = value;

    }

    ///Destructor: Note that all aggregated data and vectors are completely deleted.
    virtual ~TestData(void)
    {

    }
    
};

}


#endif
