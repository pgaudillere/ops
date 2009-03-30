
//#include "pizza/PizzaDataPublisher.h"
#include "pizza/special/ExtraAlltPublisher.h"
#include <ops.h>
#include <Publisher.h>

using namespace pizza::special;

class PizzaPub
	//: ops::DataListener, ops::DeadlineMissedListener
{
public:
	PizzaPub()
	{
		
		ops::Topic<ExtraAllt> topic("PizzaTopic", 6777, "pizza.PizzaData", "236.7.8.44");
		ExtraAlltPublisher pub(topic);

		ExtraAllt ea;
		ea.description = "From C++!!!!!!!";

		Cheese cheese1;
		cheese1.age = 30.5;
		cheese1.name = "Hattenost";

		Cheese cheese2;
		cheese2.age = 1.0;

		Cheese cheese3;
		cheese3.age = 3000.675;
		
		ea.cheeses.push_back(&cheese1);
		ea.cheeses.push_back(&cheese2);
		ea.cheese = &cheese1;

		ea.timeBakedHours = 0.1;
		ea.timeBakedSeconds = 456.0005;

		ea.description = "Skeppets bästa!";
        ea.bearnaise = "Svettigast i stan!";
        ea.ham = "Italiensk kvalitet...";
        ea.meetQuality = 10;
        ea.nrOfMushRooms = 30;
        ea.extraCheese = true;

		ea.bools.push_back(true);
        ea.bools.push_back(true);
        ea.bools.push_back(true);
        ea.bools.push_back(true);
        ea.bools.push_back(false);
        ea.bools.push_back(false);
        ea.bools.push_back(false);

        ea.doubles.push_back(2.1);
        ea.doubles.push_back(3.1);
        ea.doubles.push_back(4.1);
        ea.doubles.push_back(5.1);
        ea.doubles.push_back(6.1);

        ea.strings.push_back("12");
        ea.strings.push_back("123");
        ea.strings.push_back("1234");
        ea.strings.push_back("12345");

        ea.mushrooms = "Forest style!";

		while(true)
		{
			printf("Writing!\n");
			pub.writeOPSObject(&ea);
			Sleep(1000);
		}


	}
};