/**
* 
* Copyright (C) 2006-2009 Anton Gravestam.
*
* This file is part of OPS (Open Publish Subscribe).
*
* OPS (Open Publish Subscribe) is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* OPS (Open Publish Subscribe) is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with OPS (Open Publish Subscribe).  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ops_PublisherH
#define	ops_PublisherH

#include "OPSObject.h"
#include "OPSMessage.h"
#include "OPSArchiverOut.h"
#include "Topic.h"
#include "Sender.h"
#include "Participant.h"
#include "TimeHelper.h"
#include <string>
#include "MemoryMap.h"

//#include "DataHeaderHelper.h"

namespace ops
{
class Publisher
{
public:

	Publisher(Topic<> t): topic(t),name(""), key(""),priority(0), currentPublicationID(0), memMap(Participant::MESSAGE_MAX_SIZE / Participant::PACKET_MAX_SIZE, Participant::PACKET_MAX_SIZE)
	{
		udpSender = Sender::create();
		//bytes = new char[Participant::PACKET_MAX_SIZE];		
		message.setPublisherName(name);
		message.setTopicName(topic.GetName());
	}
    virtual ~Publisher()
	{
		delete udpSender;
		//delete bytes;
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
		//ByteBuffer buf(bytes, Participant::MESSAGE_MAX_SIZE / Participant::PACKET_MAX_SIZE, Participant::PACKET_MAX_SIZE); 
		
		ByteBuffer buf(&memMap);
		
		message.setData(data);

		message.setPublicationID(currentPublicationID);

		//buf.writeProtocol();
		//buf.WriteString("");
		//buf.WriteInt(1);
		//buf.WriteInt(0);
		buf.writeNewSegment();

		OPSArchiverOut archive(&buf);

		message = *((OPSMessage*)(archive.inout(std::string("message"), &message)));

		buf.finish();

		for(int i = 0; i < buf.getNrOfSegments(); i++)
		{
			int segSize = buf.getSegmentSize(i);
			udpSender->sendTo(buf.getSegment(i), segSize, topic.GetDomainAddress(), topic.GetPort());
			//TimeHelper::sleep(0);
		}
		
		//udpSender->sendTo(bytes, buf.GetSize(), topic.GetDomainAddress(), topic.GetPort());
				

		IncCurrentPublicationID();



	}

    void setTopic(Topic<> topic)
	{
		this->topic = topic;
	}
 

private:


	//char bytes[Participant::MESSAGE_MAX_SIZE / Participant::PACKET_MAX_SIZE][Participant::PACKET_MAX_SIZE];

	MemoryMap memMap;

	Sender* udpSender;

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
