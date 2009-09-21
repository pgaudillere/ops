//Auto generated OPS-code. DO NOT MODIFY!

#ifndef pizza_VessuvioData_h
#define pizza_VessuvioData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>

#include "PizzaData.h"


//Nested namespaces opener.
namespace pizza {


class VessuvioData :
	public PizzaData
{
public:
	
	std::string ham;


    VessuvioData()
        : PizzaData()

    {
        OPSObject::appendType(std::string("pizza.VessuvioData"));


    }
    virtual ~VessuvioData(void)
    {

    }
    void serialize(ops::ArchiverInOut* archive)
    {
		PizzaData::serialize(archive);
		ham = archive->inout(std::string("ham"), ham);

    }
    
};

//Close nested namespace
}


#endif
