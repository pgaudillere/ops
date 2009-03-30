#ifndef ops_PublisherH
#define	ops_PublisherH

#include "OPSObject.h"
#include "OPSMessage.h"
#include "OPSArchiverOut.h"
#include "Topic.h"
#include "UDPSender.h"
#include "Participant.h"
#include <string>
//#include "DataHeaderHelper.h"

namespace ops
{
class Publisher
{
public:

	Publisher(Topic<> t): topic(t),name(""), key(""),priority(0), currentPublicationID(0)
	{
		bytes = new char[Participant::MESSAGE_MAX_SIZE];		
		message.setPublisherName(name);
		message.setTopicName(topic.GetName());
	}
    virtual ~Publisher()
	{
		delete bytes;
	}

    Topic<> getTopic()
	{
		return this->topic;
	}

    void setName(std::string name)
	{
		this->name = name;
	}
    void setKey(std::string name)
	{
		this->key = key;
	}
    std::string getKey()
	{
		return this->key;
	}
    std::string getName()
	{
		return this->name;
	}

	void writeOPSObject(OPSObject* obj)
	{
		write(obj);
	}

protected:
	void write(OPSObject* data)
	{
		ByteBuffer buf(bytes); 
		message.setData(data);

		message.setPublicationID(currentPublicationID);

		buf.writeProtocol();
		buf.WriteString("");
		buf.WriteInt(1);
		buf.WriteInt(0);

		OPSArchiverOut archive(&buf);

		message = *((OPSMessage*)(archive.inout(std::string("message"), &message)));

		udpSender.sendTo(buf.GetBuffer(), buf.GetSize(), topic.GetDomainAddress(), topic.GetPort());
				

		IncCurrentPublicationID();



	}

    void setTopic(Topic<> topic)
	{
		this->topic = topic;
	}
 

private:


	char* bytes;

	UDPSender udpSender;

	OPSMessage message;
 
    Topic<> topic;

    __int64 currentPublicationID;
    std::string name;
    std::string key;
    char priority;

    void IncCurrentPublicationID()
	{
		currentPublicationID++;		
	}


};

}
#endif
