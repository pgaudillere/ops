/**
 *
 * OPS generated code, DO NOT MODIFY!
 */
#ifndef ChatExample_ChatExampleTypeFactory_h
#define ChatExample_ChatExampleTypeFactory_h

#include "SerializableFactory.h"
#include <string>

#include "chat/ExtendedChatData.h"
#include "chat/ExtendedUserData.h"
#include "chat/ChatData.h"
#include "chat/MessageData.h"
#include "chat/UserData.h"


namespace ChatExample {


class ChatExampleTypeFactory : public ops::SerializableFactory
{
public:
    ops::Serializable* create(std::string& type)
    {
		if(type == "chat.ExtendedChatData")
		{
			return new chat::ExtendedChatData();
		}
		if(type == "chat.ExtendedUserData")
		{
			return new chat::ExtendedUserData();
		}
		if(type == "chat.ChatData")
		{
			return new chat::ChatData();
		}
		if(type == "chat.MessageData")
		{
			return new chat::MessageData();
		}
		if(type == "chat.UserData")
		{
			return new chat::UserData();
		}
		return NULL;

    }
};

}

//end namespaces

#endif