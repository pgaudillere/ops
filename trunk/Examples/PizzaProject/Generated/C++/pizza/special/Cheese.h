//Auto generated OPS-code. DO NOT MODIFY!

#ifndef pizza_special_Cheese_h
#define pizza_special_Cheese_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>



//Nested namespaces opener.
namespace pizza { namespace special {


class Cheese :
	public ops::OPSObject
{
public:
	
	std::string name;
	double age;


    Cheese()
        : ops::OPSObject()
		,age(0)

    {
        OPSObject::appendType(std::string("pizza.special.Cheese"));


    }
    virtual ~Cheese(void)
    {

    }
    void serialize(ops::ArchiverInOut* archive)
    {
		ops::OPSObject::serialize(archive);
		name = archive->inout(std::string("name"), name);
		age = archive->inout(std::string("age"), age);

    }
    
};

//Close nested namespace
}}


#endif
