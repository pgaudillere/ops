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

#include "Publisher.h"

namespace ops
{
	Publisher::Publisher(Topic t): topic(t),name(""), key(""),priority(0), currentPublicationID(0), memMap(t.getSampleMaxSize() / OPSConstants::PACKET_MAX_SIZE + 1, OPSConstants::PACKET_MAX_SIZE)
	{
		udpSender = Sender::create();
		//bytes = new char[Participant::PACKET_MAX_SIZE];		
		message.setPublisherName(name);
		message.setTopicName(topic.getName());
	}
	Publisher::~Publisher()
	{
		delete udpSender;
		//delete bytes;
	}

	Topic Publisher::getTopic()
	{
		return this->topic;
	}

	void Publisher::setName(std::string name)
	{
		this->name = name;
	}
	void Publisher::setKey(std::string name)
	{
		this->key = key;
	}
	std::string Publisher::getKey()
	{
		return this->key;
	}
	std::string Publisher::getName()
	{
		return this->name;
	}

	void Publisher::writeOPSObject(OPSObject* obj)
	{
		write(obj);
	}

	void Publisher::write(OPSObject* data)
	{
		//ByteBuffer buf(bytes, Participant::MESSAGE_MAX_SIZE / Participant::PACKET_MAX_SIZE, Participant::PACKET_MAX_SIZE); 
		
		if(key != "")
		{
			data->setKey(key);
		}


		ByteBuffer buf(&memMap);
		
		message.setData(data);

		message.setPublicationID(currentPublicationID);
		message.setPublisherName(name);

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
			udpSender->sendTo(buf.getSegment(i), segSize, topic.getDomainAddress(), topic.getPort());
			//TimeHelper::sleep(1);
		}
		
		//udpSender->sendTo(bytes, buf.GetSize(), topic.GetDomainAddress(), topic.GetPort());
				

		IncCurrentPublicationID();



	}

	void Publisher::setTopic(Topic topic)
	{
		this->topic = topic;
	}

	void Publisher::IncCurrentPublicationID()
	{
		currentPublicationID++;		
	}



}