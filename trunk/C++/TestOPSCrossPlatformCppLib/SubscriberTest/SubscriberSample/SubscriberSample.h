// SubscriberSample.cpp : Defines the entry point for the console application.
//

//Include the OPS core functionalities
#include <ops.h>

//Include a subscriber class our your generated data type.
#include <opstest/ByteArrayDataSubscriber.h>
#include <opstest/ByteArrayDataPublisher.h>
#include <opstest/OPSTestTopicConfig.h>

#include <vector>


//A class that will setup a subscription to our data and reply
class MainSub
	: ops::DataListener, ops::DeadlineMissedListener
{
public:
	
	opstest::ByteArrayDataSubscriber* sub;
	opstest::ByteArrayDataPublisher* pub;

	std::vector<int> samples;

	__int64 lastSample;

	bool reliable;
	MainSub()
	{
		lastSample = -1;
		//Create a typed topic.
		opstest::OPSTestTopicConfig topicConfig("235.5.4.1");
		
		//Setup publisher for sending replies
		//pub = new opstest::ByteArrayDataPublisher(topicConfig.getByteArray2Topic());

		//Create a subscriber to receive messages
		ops::Topic<opstest::ByteArrayData> topic = topicConfig.getByteArrayTopic();
		topic.port = 45000;
		sub = new opstest::ByteArrayDataSubscriber(topic);


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
		//Reply immediately with as little overhead as possible.
		printf("Data received! %i\n", ((opstest::ByteArrayData*)sub->getDataReference())->timestamp);

		//__int64 newSample = ((opstest::ByteArrayData*)sub->getDataReference())->timestamp;

		//if(lastSample + 1 != newSample)
		//{
		//	printf("Data missed\n");
		//}

		//lastSample = newSample;
		
		

	}
	//Override from ops::DeadlineMissedListener
	void onDeadlineMissed(ops::DeadlineMissedEvent* deadlineEvent)
	{}
	~MainSub()
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

