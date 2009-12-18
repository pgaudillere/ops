//Auto generated OPS-code. DO NOT MODIFY!

#ifndef pizza_PizzaData_h
#define pizza_PizzaData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>



//Nested namespaces opener.
namespace pizza {


class PizzaData :
	public ops::OPSObject
{
public:
	
	std::string cheese;
	std::string tomatoSauce;


    PizzaData()
        : ops::OPSObject()

    {
        OPSObject::appendType(std::string("pizza.PizzaData"));


    }
    virtual ~PizzaData(void)
    {

    }
    void serialize(ops::ArchiverInOut* archive)
    {
		ops::OPSObject::serialize(archive);
		cheese = archive->inout(std::string("cheese"), cheese);
		tomatoSauce = archive->inout(std::string("tomatoSauce"), tomatoSauce);

    }
    
};

//Close nested namespace
}


#endif
