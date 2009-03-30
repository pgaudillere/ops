// SubscriberSample.cpp : Defines the entry point for the console application.
//

//Include the OPS core functionalities
#include <ops.h>

//Include a subscriber class our your generated data type.
#include "pizza/special/ExtraAlltSubscriber.h"
#include "PizzaProject/PizzaProjectTypeFactory.h"

#include <vector>


//A class that will setup a subscription to our data and reply
class PizzaSub
	: ops::DataListener, ops::DeadlineMissedListener
{
public:
	
	pizza::special::ExtraAlltSubscriber* sub;

	PizzaSub()
	{
		using namespace pizza::special;

		ops::OPSObjectFactory::getInstance()->add(new PizzaProject::PizzaProjectTypeFactory());

		//Create a typed topic.
		ops::Topic<ExtraAllt> topic("PizzaTopic", 6777, "pizza.PizzaData", "236.7.8.44");

		sub = new ExtraAlltSubscriber(topic);


		//Add this DataListener to the subscriber to get notification when new data
		//is received.
		sub->addDataListener(this);

		//Start the thread of the subscriber
		sub->start();

		//Just loop to keep the program alive, action will take place in onNewData()
		printf("Subscriber started...\n");
		
	}
	//Override from ops::DataListener
	void onNewData(ops::DataNotifier* subscriber)
	{
		using namespace pizza::special;
		ExtraAllt* ea = dynamic_cast<ExtraAllt*>(sub->getDataReference());

		printf("Data received! %s\n", ea->description.c_str());

	}
	//Override from ops::DeadlineMissedListener
	void onDeadlineMissed(ops::DeadlineMissedEvent* deadlineEvent)
	{
		printf("Deadline Missed...\n");
	}
	~PizzaSub()
	{
		delete sub;
		//delete pub;
	}
};

//int main()
//{
//	//Start main class
//	Main m;
//}

