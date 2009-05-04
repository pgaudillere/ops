// TestAll_Subscribe.cpp : Defines the entry point for the console application.
//
#include <ops.h>
#include "TestAll/ChildDataSubscriber.h"
#include "TestAll/BaseDataSubscriber.h"
#include "TestAll/TestAllTypeFactory.h"
#include <iostream>
#include <vector>

//Create a class to act as a listener for OPS data and deadlines
class Main : ops::DataListener, ops::DeadlineMissedListener
{
	//Use a member subscriber so we can use it from onNewData, see below.
	TestAll::ChildDataSubscriber* sub;
	TestAll::BaseDataSubscriber* baseSub;

	std::vector<ops::OPSMessage*> inCommingMessages;

	//
	int packagesLost;
	int lastPacket;
public:
	Main(): 
	  packagesLost(0), 
	  lastPacket(-1)
	{
		using namespace TestAll;
		using namespace ops;

		//Create a topic. NOTE, this is a temporary solution to get topics before OPS4 is completely released.
		//ops::Topic<ChildData> topic("ChildTopic", 6778, "testall.ChildData", "236.7.8.44");

		//Create a topic from configuration.
		ops::Participant* participant = Participant::getInstance("TestAllDomain");
		participant->addTypeSupport(new TestAll::TestAllTypeFactory());

		ErrorWriter* errorWriter = new ErrorWriter(std::cout);
		participant->addListener(errorWriter);


		
		Topic topic = participant->createTopic("ChildTopic");

		//Create a subscriber on that topic.
		sub = new ChildDataSubscriber(topic);
		sub->setDeadlineQoS(10000);
		//sub->setTimeBasedFilterQoS(1000);
		//sub->addFilterQoSPolicy(new KeyFilterQoSPolicy("key1"));
		sub->addDataListener(this);
		sub->deadlineMissedEvent.addDeadlineMissedListener(this);
		sub->start();

		//I godtycklig component
		Topic baseTopic = participant->createTopic("BaseTopic");

		//Create a subscriber on that topic.
		baseSub = new BaseDataSubscriber(baseTopic);
		baseSub->setDeadlineQoS(10000);		
		baseSub->addDataListener(this);
		baseSub->deadlineMissedEvent.addDeadlineMissedListener(this);
		baseSub->start();

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
		if(subscriber == sub)
		{
			TestAll::ChildData* data;
			data = (TestAll::ChildData*)sub->getMessage()->getData();

			//Do this to tell OPS not to delete this message until you do unreserve() on it, note you must keep track of your reference to avoid memory leak.
			ops::OPSMessage* newMess = sub->getMessage();
			newMess->reserve();
			inCommingMessages.push_back(newMess);

			//When we have 50 samples in our list, we print them out and unreserve them. This will cause their memory to be freed.
			if(inCommingMessages.size() == 50)
			{
				for(unsigned int i = 0; i < inCommingMessages.size(); i++)
				{
					std::cout << inCommingMessages[i]->getPublicationID() << " From: " << inCommingMessages[i]->getPublisherName() << std::endl;
					inCommingMessages[i]->unreserve();

				}
				inCommingMessages.clear();

			}
			/*
			
			if(data == NULL) return;
			if(data->i != (lastPacket + 1))
			{
				packagesLost++;
			}
			lastPacket = data->i;
			std::cout << data->baseText << " "  << " " << sub->getMessage()->getPublicationID() << " From: " << sub->getMessage()->getPublisherName() << ". Lost messages: " << packagesLost << std::endl;
		*/
		}
		else
		{
			TestAll::BaseData* data;
			data = (TestAll::BaseData*)baseSub->getMessage()->getData();
			if(data == NULL) return;
			std::cout << data->baseText << " " << baseSub->getMessage()->getPublicationID() << " From: " << baseSub->getMessage()->getPublisherName() << std::endl;
		}
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

