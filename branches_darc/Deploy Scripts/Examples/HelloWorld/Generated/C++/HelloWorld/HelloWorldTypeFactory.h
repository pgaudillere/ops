/**
 *
 * OPS generated code, DO NOT MODIFY!
 */
#ifndef HelloWorld_HelloWorldTypeFactory_h
#define HelloWorld_HelloWorldTypeFactory_h

#include "SerializableFactory.h"
#include <string>

#include "hello/HelloData.h"


namespace HelloWorld {


class HelloWorldTypeFactory : public ops::SerializableFactory
{
public:
    ops::Serializable* create(std::string& type)
    {
		if(type == "hello.HelloData")
		{
			return new hello::HelloData();
		}
		return NULL;

    }
};

}

//end namespaces

#endif