//Auto generated OPS-code. DO NOT MODIFY!

#ifndef TestAll_BaseData_h
#define TestAll_BaseData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>



namespace TestAll {


class BaseData :
	public ops::OPSObject
{
public:
	
	std::string baseText;


    BaseData()
        : ops::OPSObject()
		
    {
        OPSObject::appendType(std::string("TestAll.BaseData"));


    }

    ///This method acceptes an ops::ArchiverInOut visitor which will serialize or deserialize an
    ///instance of this class to a format dictated by the implementation of the ArchiverInout.
    void serialize(ops::ArchiverInOut* archive)
    {
		ops::OPSObject::serialize(archive);
		archive->inout(std::string("baseText"), baseText);

    }
    //Returns a deep copy of this object.
    virtual ops::OPSObject* clone()
    {
		BaseData* ret = new BaseData;
		this->fillClone(ret);
		return ret;

    }

    virtual void fillClone(ops::OPSObject* obj)
    {
		BaseData* narrRet = (BaseData*)obj;
		ops::OPSObject::fillClone(narrRet);
		narrRet->baseText = baseText;

    }

    ///Destructor: Note that all aggregated data and vectors are completely deleted.
    virtual ~BaseData(void)
    {

    }
    
};

}


#endif
