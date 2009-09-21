//Auto generated OPS-code. DO NOT MODIFY!

#ifndef pizza_special_LHCData_h
#define pizza_special_LHCData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>

#include "pizza/CapricosaData.h"
#include "pizza/PizzaData.h"


//Nested namespaces opener.
namespace pizza { namespace special {


class LHCData :
	public pizza::CapricosaData
{
public:
	
	std::string bearnaise;
	std::string beef;
	std::vector<pizza::PizzaData*> p;


    LHCData()
        : pizza::CapricosaData()

    {
        OPSObject::appendType(std::string("pizza.special.LHCData"));


    }
    virtual ~LHCData(void)
    {

    }
    void serialize(ops::ArchiverInOut* archive)
    {
		pizza::CapricosaData::serialize(archive);
		bearnaise = archive->inout(std::string("bearnaise"), bearnaise);
		beef = archive->inout(std::string("beef"), beef);
		archive->inout<pizza::PizzaData*>(std::string("p"), p);

    }
    
};

//Close nested namespace
}}


#endif
