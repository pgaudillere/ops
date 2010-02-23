/**
 *
 * OPS generated code, DO NOT MODIFY!
 */
#ifndef TestAll_TestAllTypeFactory_h
#define TestAll_TestAllTypeFactory_h

#include "SerializableFactory.h"
#include <string>

#include "TestAll/TestData.h"
#include "TestAll/ChildData.h"
#include "TestAll/Fruit.h"
#include "TestAll/BaseData.h"


namespace TestAll {


class TestAllTypeFactory : public ops::SerializableFactory
{
public:
    ops::Serializable* create(std::string& type)
    {
		if(type == "TestAll.TestData")
		{
			return new TestAll::TestData();
		}
		if(type == "TestAll.ChildData")
		{
			return new TestAll::ChildData();
		}
		if(type == "TestAll.Fruit")
		{
			return new TestAll::Fruit();
		}
		if(type == "TestAll.BaseData")
		{
			return new TestAll::BaseData();
		}
		return NULL;

    }
};

}

//end namespaces

#endif