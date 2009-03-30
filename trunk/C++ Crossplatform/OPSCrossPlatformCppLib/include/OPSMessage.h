#ifndef OPSMessageH
#define OPSMessageH

#include "OPSObject.h"
#include "ArchiverInOut.h"

namespace ops
{

class OPSMessage : public OPSObject
{
public:

	OPSMessage() :
		messageType(0),
		endianness(0),
		publisherPriority(),
		port(0),
		qosMask(0),
		publicationID(0)
	{
		OPSObject::appendType(std::string("ops.protocol.OPSMessage"));
	}
	~OPSMessage()
	{
		//TODO: should this delete data???
	}

private:
	char messageType;
    char  endianness;
    char publisherPriority;
    int port;
    __int64 qosMask;
    __int64 publicationID;
	std::string publisherName;
    std::string topicName;
    std::string topLevelKey;
    std::string address;
    OPSObject* data;

public:
	__int64 getPublicationID()
	{
		return publicationID;
	}
	void setPublicationID(__int64 pubID)
	{
		publicationID = pubID;
	}
	std::string getPublisherName()
	{
		return publisherName;
	}
	void setPublisherName(std::string pubName)
	{
		publisherName = pubName;
	}
	std::string getTopicName()
	{
		return topicName;
	}
	void setTopicName(std::string topName)
	{
		topicName = topName;
	}
	void setData(OPSObject* d)
	{
		data = d;
	}
	OPSObject* getData()
	{
		return data;
	}


	void serialize(ArchiverInOut* archive)
	{
		OPSObject::serialize(archive);

		messageType = archive->inout(std::string("messageType"), messageType);
        publisherPriority = archive->inout(std::string("publisherPriority"), publisherPriority);
        publicationID = archive->inout(std::string("publicationID"), publicationID);
        publisherName = archive->inout(std::string("publisherName"), publisherName);
        topicName = archive->inout(std::string("topicName"), topicName);
        topLevelKey = archive->inout(std::string("topLevelKey"), topLevelKey);
        address = archive->inout(std::string("address"), address);
        data = (OPSObject*) archive->inout(std::string("data"), data);
		
	}
};

}


#endif