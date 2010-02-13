/**
 *
 * OPS generated code, DO NOT MODIFY!
 */
#ifndef TestAll_TestAllTypeFactory_h
#define TestAll_TestAllTypeFactory_h

#include "SerializableFactory.h"
#include <string>

#include "TestAll/BaseData.h"
#include "TestAll/ChildData.h"
#include "TestAll/TestData.h"


namespace TestAll {


class TestAllTypeFactory : public ops::SerializableFactory
{
public:
    ops::Serializable* create(std::string& type)
    {
		if(type == "TestAll.BaseData")
		{
			return new TestAll::BaseData();
		}
		if(type == "TestAll.ChildData")
		{
			return new TestAll::ChildData();
		}
		if(type == "TestAll.TestData")
		{
			return new TestAll::TestData();
		}
		return NULL;

    }
};

}

//end namespaces

#endif