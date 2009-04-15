/**
 *
 * OPS generated code, DO NOT MODIFY!
 */
#ifndef TestAll_TestAllTypeFactory_h
#define TestAll_TestAllTypeFactory_h

#include "SerializableFactory.h"
#include <string>

#include "testall/TestData.h"
#include "testall/ChildData.h"
#include "testall/BaseData.h"


namespace TestAll {


class TestAllTypeFactory : public ops::SerializableFactory
{
public:
    ops::Serializable* create(std::string& type)
    {
		if(type == "testall.TestData")
		{
			return new testall::TestData();
		}
		if(type == "testall.ChildData")
		{
			return new testall::ChildData();
		}
		if(type == "testall.BaseData")
		{
			return new testall::BaseData();
		}
		return NULL;

    }
};

}

//end namespaces

#endif