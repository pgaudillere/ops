//Auto generated OPS-code. DO NOT MODIFY!

#ifndef testall_BaseData_h
#define testall_BaseData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>



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

    ///This method acceptes an ops::ArchiverInOut visitor which will serialize or deserialize an
    ///instance of this class to a format dictated by the implementation of the ArchiverInout.
    void serialize(ops::ArchiverInOut* archive)
    {
		ops::OPSObject::serialize(archive);
		archive->inout(std::string("baseText"), baseText);

    }

    ///Destructor: Note that all aggregated data and vectors are completely deleted.
    virtual ~BaseData(void)
    {

    }
    
};

}


#endif
