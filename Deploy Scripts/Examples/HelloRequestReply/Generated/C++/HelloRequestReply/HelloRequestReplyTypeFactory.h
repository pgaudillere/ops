/**
 *
 * OPS generated code, DO NOT MODIFY!
 */
#ifndef HelloRequestReply_HelloRequestReplyTypeFactory_h
#define HelloRequestReply_HelloRequestReplyTypeFactory_h

#include "SerializableFactory.h"
#include <string>

#include "hello/RequestHelloData.h"
#include "hello/HelloData.h"


namespace HelloRequestReply {


class HelloRequestReplyTypeFactory : public ops::SerializableFactory
{
public:
    ops::Serializable* create(std::string& type)
    {
		if(type == "hello.RequestHelloData")
		{
			return new hello::RequestHelloData();
		}
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