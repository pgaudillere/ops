//Auto generated OPS-code. DO NOT MODIFY!

#ifndef pizza_special_ExtraAllt_h
#define pizza_special_ExtraAllt_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>

#include "LHCData.h"
#include "pizza/special/Cheese.h"
#include "pizza/special/Cheese.h"


//Nested namespaces opener.
namespace pizza { namespace special {


class ExtraAllt :
	public LHCData
{
public:
	
	///Does the order include extra cheese???
	bool extraCheese;
	///@limits(0,INFINITY)
	char nrOfMushRooms;
	int meetQuality;
	__int64 timestamp;
	float timeBakedHours;
	double timeBakedSeconds;
	std::string description;
	pizza::special::Cheese* cheese;
	std::vector<bool> bools;
	std::vector<char> bytes;
	std::vector<int> ints;
	std::vector<__int64> longs;
	std::vector<float> floats;
	std::vector<double> doubles;
	std::vector<std::string> strings;
	std::vector<pizza::special::Cheese*> cheeses;


    ExtraAllt()
        : LHCData()
		,extraCheese(false)
		,nrOfMushRooms(0)
		,meetQuality(0)
		,timestamp(0)
		,timeBakedHours(0)
		,timeBakedSeconds(0)

    {
        OPSObject::appendType(std::string("pizza.special.ExtraAllt"));
		cheese = new pizza::special::Cheese();


    }
    virtual ~ExtraAllt(void)
    {
		delete cheese;

    }
    void serialize(ops::ArchiverInOut* archive)
    {
		LHCData::serialize(archive);
		extraCheese = archive->inout(std::string("extraCheese"), extraCheese);
		nrOfMushRooms = archive->inout(std::string("nrOfMushRooms"), nrOfMushRooms);
		meetQuality = archive->inout(std::string("meetQuality"), meetQuality);
		timestamp = archive->inout(std::string("timestamp"), timestamp);
		timeBakedHours = archive->inout(std::string("timeBakedHours"), timeBakedHours);
		timeBakedSeconds = archive->inout(std::string("timeBakedSeconds"), timeBakedSeconds);
		description = archive->inout(std::string("description"), description);
		cheese = (pizza::special::Cheese*) archive->inout(std::string("cheese"), cheese);
		archive->inout(std::string("bools"), bools);
		archive->inout(std::string("bytes"), bytes);
		archive->inout(std::string("ints"), ints);
		archive->inout(std::string("longs"), longs);
		archive->inout(std::string("floats"), floats);
		archive->inout(std::string("doubles"), doubles);
		archive->inout(std::string("strings"), strings);
		archive->inout<pizza::special::Cheese*>(std::string("cheeses"), cheeses);

    }
    
};

//Close nested namespace
}}


#endif
