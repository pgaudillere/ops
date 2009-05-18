// TestAll_Publish.cpp : Defines the entry point for the console application.
//

#include <Windows.h>

#include "TestAll/ChildDataPublisher.h"
#include "TestAll/BaseDataPublisher.h"
#include "TestAll/TestAllTypeFactory.h"
#include <ops.h>
#include <XMLArchiverOut.h>
#include <XMLArchiverIn.h>

#include <iostream>
#include <fstream>

int main(int argc, char* args)
{
	//timeBeginPeriod(1);
	using namespace TestAll;
	using namespace ops;

	ops::Participant* participant = Participant::getInstance("TestAllDomain");
	participant->addTypeSupport(new TestAll::TestAllTypeFactory());

	//Create topic, might throw ops::NoSuchTopicException
	Topic topic = participant->createTopic("ChildTopic");
	//topic.setDomainAddress("10.73.4.93");
	//Create a publisher on that topic
	ChildDataPublisher pub(topic);
	pub.setName("TestAllPublisher");

	Topic baseTopic = participant->createTopic("BaseTopic");

	BaseDataPublisher basePub(baseTopic);
	basePub.setName("BasePublisher");

	//Create some data to publish
	ChildData data;
	BaseData baseData;
	baseData.baseText = "Text from base";


	//Set Base class field
	data.baseText = "Hello";

	////Set aggregated object
	//TestData testData;
	//testData.text = "text in aggregated class";
	//testData.value = 0.0;
	//data.test2 = &testData;
	//
	//Set primitives
	data.bo = true;
	data.b = 1;
	data.i = 0;
	data.l = 3;
	data.f = 4.0;
	data.d = 5.0;
	//data.s = "World";
	data.s = "World";

	//Set arrays (vectors)
	data.bos.push_back(true);
	data.bs.push_back(6);
	//data.is.push_back(7);
	data.ls.push_back(8);
	//data.fs.push_back(9.0);
	data.ds.push_back(10.0);
	data.ss.push_back("Hello Array");
	data.setKey("key1");

	//return 0;

	for(int i = 0; i < 100; i++)
	{
		data.fs.push_back(i);
	}

	
	TestData testData2;
	testData2.text = "text in aggregated array element class";
	testData2.value = 2.0;

	TestData testData3;
	testData3.text = "text in aggregated array element class";
	testData3.value = 3.0;

	data.test2s.push_back(&testData2);
	data.test2s.push_back(&testData3);

	std::ofstream oStream("hatt.xml");

	ops::XMLArchiverOut archiver(oStream, "config");

	archiver.inout(std::string("data"), &data);

	archiver.close();

	oStream.close();

	//std::ifstream iStream ("fulfile.xml");

	//ops::XMLArchiverIn archiverIn(iStream, "file");

	//
	//ops::Serializable* ser = archiverIn.inout(std::string("data"), (OPSObject*)NULL);



	//return 0;

	//Publish the data peridically and make a small changes to the data.
	while(true)
	{
		pub.write(&data);
		std::cout << "Writing " << data.i <<  std::endl;
		data.i++;

		if(data.i % 20 == 0)
		{
			basePub.write(&baseData);
		}

		Sleep(100);
	}

	//timeEndPeriod(1);
	return 0;
}

