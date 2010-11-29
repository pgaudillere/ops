/**
 *
 * OPS generated code, DO NOT MODIFY!
 */
#ifndef HelloRequestReply_HelloRequestReplyTypeFactory_h
#define HelloRequestReply_HelloRequestReplyTypeFactory_h

#include "SerializableFactory.h"
#include <string>

#include "hello/HelloData.h"
#include "hello/RequestHelloData.h"


namespace HelloRequestReply {


class HelloRequestReplyTypeFactory : public ops::SerializableFactory
{
public:
    ops::Serializable* create(std::string& type)
    {
		if(type == "hello.HelloData")
		{
			return new hello::HelloData();
		}
		if(type == "hello.RequestHelloData")
		{
			return new hello::RequestHelloData();
		}
		return NULL;

    }
};

}

//end namespaces

#endif