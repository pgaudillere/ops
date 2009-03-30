// SubscriberSample.cpp : Defines the entry point for the console application.
//
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <mmsystem.h>

//Include the OPS core functionalities
#include <ops.h>

//Include a publisher class for your generated data type.
#include <opstest/ByteArrayDataSubscriber.h>
#include <opstest/ByteArrayDataPublisher.h>
#include <opstest/OPSTestTopicConfig.h>

#include <map>

//A class that is used to test roundtrip times for OPS 
class MainPub
	: ops::DataListener, ops::DeadlineMissedListener
{
public:

	std::map<__int64, DWORD> outMap;
	std::map<__int64, DWORD> inMap;

	const static int nrSamples = 1000;
	const static int nrBytesPerSample = 50000;
	const static int sleepTime = 2;


	opstest::ByteArrayDataSubscriber* sub;
	opstest::ByteArrayDataPublisher* pub;
	MainPub()
	{


		//Create a typed topic.
		opstest::OPSTestTopicConfig topicConfig("235.5.4.1");

		//Setup publisher for sending messages
		ops::Topic<opstest::ByteArrayData> topic = topicConfig.getByteArrayTopic();
		topic.port = 45000;
		pub = new opstest::ByteArrayDataPublisher(topic);

		//Create a subscriber to receive replies.
		//sub = new opstest::ByteArrayDataSubscriber(topicConfig.getByteArray2Topic());

		//Add this DataListener to the subscriber to get notification when new data
		//is received.
		//sub->addDataListener(this);

		//Start the thread of the subscriber
		//sub->start();

		//Create some data to publish, just add random number between 0-100 to our byte array.
		opstest::ByteArrayData dataSample;
		for(int i = 0 ; i < nrBytesPerSample ; i++)
		{
			dataSample.bytes.push_back((rand() / RAND_MAX) * 100);
		}
		//Wait some time to make sure publishers and subscribers are connected
		//Sleep(2000);

		//Loop and write data to the publisher.
		printf("Test started...\n");
		__int64 startTime = timeGetTime();
		timeBeginPeriod(1);	//Set the accurancy of Sleep() to 1 millisecond.

		__int64 j = 0;
		while(true)
		{
			dataSample.timestamp = j;
			pub->write(&dataSample);
			Sleep(sleepTime);
			j++;
			if(j > 100) break;
		}


		timeEndPeriod(1);
		__int64 totalTime = timeGetTime() - startTime;


		printf("Rate = %f Hz\n", (double)( nrSamples / (totalTime / 1000.0 ) ));

		//Wait to make sure all replies ar safely received
		//Sleep(2000);

		//Calculate some statistics about the test and print them
		/*DWORD avarageRoundtripTime = 0;
		DWORD maxRoundtripTime = 0;
		int samplesLost = 0;
		for(__int64 k = 0 ; k < nrSamples ; k++)
		{

			if(inMap.find(k) != inMap.end())
			{
				DWORD rt = (inMap[k] - outMap[k]);
				avarageRoundtripTime += rt;
				if(rt > maxRoundtripTime)
				{
					maxRoundtripTime = rt;
				}
			}
			else
			{
				printf("%i ", k);
				samplesLost++;
			}	
		}
		printf("\n");
		avarageRoundtripTime /= (nrSamples - samplesLost);
		DWORD avarageLatancy = avarageRoundtripTime / 2;*/

		/*double megaBytesSent = nrSamples * nrBytesPerSample / 1000000;
		double megaBytesPerSecond = megaBytesSent / (totalTime /1000.0);

		printf("%i samples lost (%f percent)\n", samplesLost, (double)samplesLost/(double)nrSamples*100.0);
		printf("%f  MBytes sent with %f MBytes per second.\n", megaBytesSent, megaBytesPerSecond);
		printf("Avarage roundtrip time: %2d\nAvarage latancy: %2d\nMax roundtrip time: %2d\n", avarageRoundtripTime, avarageLatancy, maxRoundtripTime);*/

		char c[100];

		printf("Hit return to exit\n");
		gets(c);

	}
	//Override from ops::DataListener
	void onNewData(ops::DataNotifier* subscriber)
	{
		//Put the rply in a map mapping the sample (timestamp field) to the time of recepction.
		//inMap[((opstest::ByteArrayData*)sub->getDataReference())->timestamp] = GetTickCount();	

	}
	//Override from ops::DeadlineMissedListener
	void onDeadlineMissed(ops::DeadlineMissedEvent* deadlineEvent)
	{


	}
	~MainPub()
	{
		//delete sub;
		delete pub;
	}
};

//int main()
//{
//	Main m;
//}

