// TestAll_Publish.cpp : Defines the entry point for the console application.
//
#include <ops.h>
#include <XMLArchiverOut.h>
#include <XMLArchiverIn.h>
#include "testall/ChildDataPublisher.h"
#include "testall/TestAllTypeFactory.h"
#include <iostream>
#include <fstream>
#include <Configuration.h>

int main(int argc, char* args)
{
	using namespace testall;
	using namespace ops;

	//Add support for our types from TestAll IDL project.
	ops::OPSObjectFactory::getInstance()->add(new TestAll::TestAllTypeFactory()); 

	ops::Topic<> topic = Configuration::getConfiguration()->getTopic("ChildTopic");  //("ChildTopic", 6778, "testall.ChildData", "236.7.8.44");


	//Create a publisher on that topic
	ChildDataPublisher pub(topic);

	//Create some data to publish
	ChildData data;

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
	data.is.push_back(7);
	data.ls.push_back(8);
	data.fs.push_back(9.0);
	data.ds.push_back(10.0);
	data.ss.push_back("Hello Array");

	//return 0;

	for(int i = 0; i < 500000; i++)
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

	//std::ofstream oStream("ops_config.xml");

	//ops::XMLArchiverOut archiver(oStream, "config");

	//archiver.inout(std::string("topic"), &topic);

	//archiver.close();

	//oStream.close();

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
		Sleep(50);
	}

	return 0;
}

