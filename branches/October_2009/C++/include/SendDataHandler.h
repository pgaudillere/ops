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
#ifndef ops_SendDataHandler_h
#define	ops_SendDataHandler_h

#include "Participant.h"
#include <map>
#include "Sender.h"
#include "OPSObject.h"
#include "Lockable.h"

namespace ops
{
	
	class SendDataHandler
	{
	public:
		SendDataHandler(Participant* part)
		{
			this->participant = part;
			
			
		}
		bool sendData(OPSObject* o, std::string& topic)
		{
			//Deserialize data here
			
			SafeLock lock(&mutex);
			//Loop all senders and send data here
		}
		void addSink(std::string& topic, std::string& ip, int& port)
		{
			//Create sender here

			IpPortPair ipPort(ip, port);
			if(topicSinkMap.find(topic) == topicSinkMap.end())
			{
				//We have no sinks for this topic. Lets add one
				std::map<IpPortPair, IpPortPair, CompIpPortPair> newIpPortMap;
				newIpPortMap[ipPort] = ipPort;

				SafeLock lock(&mutex);
				topicSinkMap[topic] = newIpPortMap;

				return;		
			}
			else
			{
				//We already have sinks for this topic lets just add the new sink 

				SafeLock lock(&mutex);
				topicSinkMap[topic][ipPort] = ipPort;

				return;

			}

			
		}
		void removeSink(std::string& topic, std::string& ip, int& port)
		{
			//Find sender to delete here

			SafeLock lock(&mutex);
			//Remove, stop and delete sender here

		}

		virtual ~SendDataHandler(){}

	private:
		Participant* participant;
		std::map<std::string, Sender*> senders;
		
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