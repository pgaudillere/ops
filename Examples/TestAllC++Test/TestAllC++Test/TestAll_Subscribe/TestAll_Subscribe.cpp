// TestAll_Subscribe.cpp : Defines the entry point for the console application.
//
#include <ops.h>
#include "testall/ChildDataSubscriber.h"
#include "testall/TestAllTypeFactory.h"
#include <iostream>

//Create a class to act as a listener for OPS data and deadlines
class Main : ops::DataListener, ops::DeadlineMissedListener
{
	//Use a member subscriber so we can use it from onNewData, see below.
	testall::ChildDataSubscriber* sub;

	//
	int packagesLost;
	int lastPacket;
public:
	Main(): packagesLost(0), lastPacket(-1)
	{
		using namespace testall;
		using namespace ops;

		//Create a topic. NOTE, this is a temporary solution to get topics before OPS4 is completely released.
		//ops::Topic<ChildData> topic("ChildTopic", 6778, "testall.ChildData", "236.7.8.44");

		//Create a topic from configuration.
		ops::Participant* participant = Participant::getInstance("TestAllDomain");
		participant->addTypeSupport(new TestAll::TestAllTypeFactory());

		ErrorWriter* errorWriter = new ErrorWriter(std::cout);
		participant->addListener(errorWriter);


		//I godtycklig component
		Topic topic = participant->createTopic("ChildTopic");

		//Create a subscriber on that topic.
		sub = new ChildDataSubscriber(topic);
		sub->setDeadlineQoS(10000);
		sub->setTimeBasedFilterQoS(1000);
		sub->addDataListener(this);
		sub->deadlineMissedEvent.addDeadlineMissedListener(this);
		sub->start();

		//while(true)
		//{
		//	Sleep(1000);
		//	sub->aquireMessageLock();
		//	onNewData(sub);
		//	sub->releaseMessageLock();
		//}
	}
	///Override from ops::DataListener, called whenever new data arrives.
	void onNewData(ops::DataNotifier* subscriber)
	{
		testall::ChildData* data;
		data = (testall::ChildData*)sub->getMessage()->getData();
		if(data == NULL) return;
		if(data->i != (lastPacket + 1))
		{
			packagesLost++;
		}
		lastPacket = data->i;
		std::cout << data->baseText << " " << data->fs[10] << " " << sub->getMessage()->getPublicationID() << " From: " << sub->getMessage()->getPublisherName() << ". Lost messages: " << packagesLost << std::endl;
	}
	///Override from ops::DeadlineMissedListener, called if no new data has arrived within deadlineQoS.
	void onDeadlineMissed(ops::DeadlineMissedEvent* evt)
	{
		std::cout << "Deadline Missed!" << std::endl;
	}
	~Main()
	{
		delete sub;
	}

};

//Application entry point
int main(int argc, char* args)
{
	//Add support for our types from TestAll IDL project.
	ops::OPSObjectFactory::getInstance()->add(new TestAll::TestAllTypeFactory()); 

	//Create an object that will listen to OPS events
	Main m;

	//Make sure the OPS ioService never runs out of work.
	//Run it on main application thread only.
	while(true)
	{
		Sleep(1000);
		//ops::Participant::getIOService()->run();
	}
	return 0;
}

