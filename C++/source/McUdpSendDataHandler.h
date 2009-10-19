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
#ifndef ops_McUdpSendDataHandler_h
#define	ops_McUdpSendDataHandler_h


//#include "Participant.h"
#include "SendDataHandler.h"
#include <map>
#include "Sender.h"
#include "OPSObject.h"
#include "Lockable.h"
#include "MemoryMap.h"
#include <iostream>

namespace ops
{
	
	class McUdpSendDataHandler : public SendDataHandler
	{
	public:
		McUdpSendDataHandler(/*Participant* part*/)
		{
			//this->participant = part;
		}
		bool sendData(char* buf, int bufSize, Topic& topic)
		{
			SafeLock lock(&mutex);

			std::map<IpPortPair, IpPortPair, CompIpPortPair> topicSinks = topicSinkMap[topic.getName()];
			std::map<IpPortPair, IpPortPair, CompIpPortPair>::iterator it;
			
			bool result = true;
			//Loop all senders and send data here
			for(it = topicSinks.begin(); it != topicSinks.end(); it++ )
			{
				result &= sender->sendTo(buf, bufSize, it->second.ip, it->first.port);
			}

			return result;
		}
		void addSink(std::string& topic, std::string& ip, int& port)
		{
			
			//TODO: decide what class will handle serialization.
			//First, check if the MemoryMap we have allocated is big enough to deal with this topic.	
			//int nrSegs = topic.getSampleMaxSize() / OPSConstants::PACKET_MAX_SIZE + 1;
			//if(memMap->getNrOfSegments() < nrSegs)
			//{
			//	//We need a bigger memMap to take care of serialization for data sent on this topic.
			//	SafeLock lock(&mutex);
			//	delete memMap;
			//	memMap = new MemoryMap(nrSegs, OPSConstants::PACKET_MAX_SIZE);
			//}			
			
			//Secondly, check if we already have any sink for this topic, if not add a new sink map for this topic.
			IpPortPair ipPort(ip, port);
			if(topicSinkMap.find(topic) == topicSinkMap.end())
			{
				//We have no sinks for this topic. Lets add a new sink map
				std::map<IpPortPair, IpPortPair, CompIpPortPair> newIpPortMap;

				//And add the new sink to the map.
				newIpPortMap[ipPort] = ipPort;

				SafeLock lock(&mutex);
				topicSinkMap[topic] = newIpPortMap;

				std::cout << topic << " added as sink" << std::endl;

				return;		
			}
			else
			{
				//We already have a map of sinks for this topic lets just add the new sink to the map.
				SafeLock lock(&mutex);
				topicSinkMap[topic][ipPort] = ipPort;

				return;

			}

			
		}
		void removeSink(std::string& topic, std::string& ip, int& port)
		{
			//Find sender to delete here

			SafeLock lock(&mutex);
			//TODO: Remove, stop and delete sender here

		}

		virtual ~McUdpSendDataHandler(){}

	private:
		//Participant* participant;
		std::map<std::string, Sender*> senders;
		Sender* sender;

		MemoryMap* memMap;
		
		Lockable mutex;

		class IpPortPair
		{
		public:
			IpPortPair(std::string ip, int port)
			{
				this->ip = ip;
				this->port = port;
			}
			IpPortPair()
			{

			}
			std::string ip;
			int port;
		};
		class CompIpPortPair
		{
		public:
			bool operator()(const IpPortPair &ip1, const IpPortPair &ip2) const
			{
				return ( ip1.ip == ip2.ip && ip1.port == ip2.port );
			}
		};
		

		std::map<std::string, std::map<IpPortPair, IpPortPair, CompIpPortPair> > topicSinkMap;

	};


}

#endif