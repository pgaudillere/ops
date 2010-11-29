// TestAll_Publish.cpp : Defines the entry point for the console application.
//

//Include ops
#include <ops.h>

//Include a publisher for the data type we want to publish, generated from our IDL project TestAll.
#include "TestAll/ChildDataPublisher.h"

//Include type support for the data types we have defined in our IDL project, generated from our IDL project TestAll.
#include "TestAll/TestAllTypeFactory.h"

//Include iostream to get std::cout
#include <iostream>

//Include windows to get Sleep()
#include <Windows.h>


int main(int argc, const char* args[])
{
	using namespace TestAll;
	using namespace ops;

	//Create a Participant (i.e. an entry point for using ops.), compare with your ops_config.xml
	ops::Participant* participant = Participant::getInstance("TestAllDomain");
	if(!participant)
	{
		std::cout << "Create participant failed. do you have ops_config.xml on your rundirectory?" << std::endl;
		Sleep(10000); exit(1);
	}

	//Add type support for our types, to make this participant understand what we are talking
	participant->addTypeSupport(new TestAll::TestAllTypeFactory());

	//Now, create the Topic we wish to publish on. Might throw ops::NoSuchTopicException if no such Topic exist in ops_config.xml
	Topic topic = participant->createTopic("ChildTopic");

	//Create a publisher on that topic
	ChildDataPublisher pub(topic);
	pub.setName("TestAllPublisher"); //Optional identity of the publisher

	//Create some data to publish, this is our root object.
	ChildData data;

	//ChildData extends from BaseData which has a string field called baseText.
	data.baseText = "Hello";

	//ChildData has a field of type TestData which has the fields text and value.
	data.testData.text = "Text in aggregated class";
	data.testData.value = 3456.0;

	//ChildData has a field for every primitive type available in OPS IDL.
	data.bo = true;
	data.b = 1;
	data.i = 0;
	data.l = 3;
	data.f = 4.0;
	data.d = 5.0;
	data.s = "Hello World!";

	//ChildData has a field for every primitive array
	data.bos.push_back(true);
	data.bs.push_back(6);
	data.is.push_back(7);
	data.ls.push_back(8);
	data.fs.push_back(9.0);
	data.ds.push_back(10.0);
	data.ss.push_back("Hello World From Array!");
	
	//Publish the data peridically and make a small changes to the data.
	int mainSleep = 1000;
	while(true)
	{
		pub.write(&data);
		std::cout << "Writing " << data.i <<  std::endl;
		data.i++;

		Sleep(mainSleep);
		
	}

	return 0;
}

