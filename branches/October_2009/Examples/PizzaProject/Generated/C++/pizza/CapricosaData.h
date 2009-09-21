//Auto generated OPS-code. DO NOT MODIFY!

#ifndef pizza_CapricosaData_h
#define pizza_CapricosaData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>

#include "VessuvioData.h"


//Nested namespaces opener.
namespace pizza {


class CapricosaData :
	public VessuvioData
{
public:
	
	std::string mushrooms;


    CapricosaData()
        : VessuvioData()

    {
        OPSObject::appendType(std::string("pizza.CapricosaData"));


    }
    virtual ~CapricosaData(void)
    {

    }
    void serialize(ops::ArchiverInOut* archive)
    {
		VessuvioData::serialize(archive);
		mushrooms = archive->inout(std::string("mushrooms"), mushrooms);

    }
    
};

//Close nested namespace
}


#endif
