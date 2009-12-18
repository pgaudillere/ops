// TestAll_Subscribe.cpp : Defines the entry point for the console application.
//
#include <ops.h>
#include "TestAll/ChildDataSubscriber.h"
#include "TestAll/BaseDataSubscriber.h"
#include "TestAll/TestAllTypeFactory.h"
#include <iostream>
#include <vector>
#include "Receiver.h"

//Create a class to act as a listener for OPS data and deadlines
class Main : ops::DataListener, ops::DeadlineMissedListener, ops::Listener<ops::BytesSizePair>
{
public:
	//Use a member subscriber so we can use it from onNewData, see below.
	TestAll::ChildDataSubscriber* sub;
	TestAll::BaseDataSubscriber* baseSub;
	TestAll::ChildData data;

	std::vector<ops::OPSMessage*> inCommingMessages;

	//
	int packagesLost;
	int lastPacket;

	ops::Receiver* rec;
	char bytes[100];
public:
	void onNewEvent(ops::Notifier<ops::BytesSizePair>* sender, ops::BytesSizePair byteSizePair)
	{
		rec->asynchWait(bytes, 100);
	}
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

		/*rec = ops::Receiver::createTCPClient("127.0.0.1", 1342, participant->getIOService());
		rec->addListener(this);
		rec->asynchWait(bytes, 100);
		while(true)
		{
			Sleep(1000);
		}*/

		ErrorWriter* errorWriter = new ErrorWriter(std::cout);
		participant->addListener(errorWriter);

		Topic topic = participant->createTopic("ChildTopic");

		//Create a subscriber on that topic.
		sub = new ChildDataSubscriber(topic);
		sub->setDeadlineQoS(10);
		//sub->setTimeBasedFilterQoS(1000);
		sub->addFilterQoSPolicy(new KeyFilterQoSPolicy("key1"));
		sub->addDataListener(this);
		sub->deadlineMissedEvent.addDeadlineMissedListener(this);
		//sub->setHistoryMaxSize(5);
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
			
			sub->numReservedMessages();

			sub->getData(&data);
	
			//std::cout << data.i << " From: " << sub->getMessage()->getPublisherName() << std::endl;


			//data = (TestAll::ChildData*)sub->getMessage()->getData();
			//for(int i = 0; i < data->fs.size(); i++)
			//{
			//	if(i != (int)data->fs[i])
			//	{
			//		throw "Error!";
			//	}

			//}

			////Do this to tell OPS not to delete this message until you do unreserve() on it, note you must keep track of your reserved references to avoid memory leak.
			//ops::OPSMessage* newMess = sub->getMessage();
			//newMess->reserve();
			//inCommingMessages.push_back(newMess);

			////When we have 50 samples in our list, we print, remove and unreserve them. This will allow their memory to be freed.
			//if(inCommingMessages.size() == 5)
			//{
			//	for(unsigned int i = 0; i < inCommingMessages.size(); i++)
			//	{
			//		std::cout << inCommingMessages[i]->getPublicationID() << " From: " << inCommingMessages[i]->getPublisherName() << std::endl;
			//		inCommingMessages[i]->unreserve();

			//	}
			//	inCommingMessages.clear();

			//}
			//If you dont want to keep track of data yourself, you can use the history deque from the subscriber, its max size is set by sub->setHistoryMaxSize() in constructor.
			//std::cout << "Buffer size: " << sub->getHistory().size() << std::endl;

			
			
			//if(data == NULL) return;
			if(data.i != (lastPacket + 1))
			{
				packagesLost++;
			}
			lastPacket = data.i;
			std::cout << data.baseText << " "  << " " << sub->getMessage()->getPublicationID() << " From: " << sub->getMessage()->getPublisherName() << ". Lost messages: " << packagesLost << "          \r";// << std::endl;
		
		}
		else
		{
			//Sleep(100000);
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
		baseSub->stop();
		delete baseSub;
		sub->stop();
		delete sub;
		
	}

};

//Application entry point
int main(int argc, char* args)
{
	ops::Participant* participant = ops::Participant::getInstance("TestAllDomain");
	
	
	//Create an object that will listen to OPS events
	Main* m = new Main();

	//Make sure the OPS ioService never runs out of work.
	//Run it on main application thread only.
	for(int i = 0; i < 100; )
	{
		Sleep(100);
		//break;
		/*m.sub->aquireMessageLock();
		std::deque<ops::OPSMessage*> messages = m.sub->getHistory();
		for(int i = 0; i < 5 && i < messages.size(); i++)
		{
			std::cout << messages[i]->getPublicationID() << " ";
		}
		m.sub->releaseMessageLock();
		std::cout << std::endl;*/

		//ops::Participant::getIOService()->run();
	}


	delete m;
	//Force OPS shudown.
	delete participant;
	
	
	return 0;
}

