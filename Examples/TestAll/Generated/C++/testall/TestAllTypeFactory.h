/**
 *
 * OPS generated code, DO NOT MODIFY!
 */
#ifndef TestAll_TestAllTypeFactory_h
#define TestAll_TestAllTypeFactory_h

#include "SerializableFactory.h"
#include <string>

#include "testall/ChildData.h"
#include "testall/BaseData.h"
#include "testall/TestData.h"


namespace TestAll {


class TestAllTypeFactory : public ops::SerializableFactory
{
public:
    ops::Serializable* create(std::string& type)
    {
		if(type == "testall.ChildData")
		{
			return new testall::ChildData();
		}
		if(type == "testall.BaseData")
		{
			return new testall::BaseData();
		}
		if(type == "testall.TestData")
		{
			return new testall::TestData();
		}
		return NULL;

    }
};

}

//end namespaces

#endif