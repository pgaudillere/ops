/**
* 
* Copyright (C) 2006-2009 Anton Gravestam.
*
* This notice apply to all source files, *.cpp, *.h, *.java, and *.cs in this directory 
* and all its subdirectories if nothing else is explicitly stated within the source file itself.
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

#ifndef ops_TopicHandler_h
#define ops_TopicHandler_h

#include <string>
#include <map>
#include "Topic.h"
#include "ByteBuffer.h"
#include "OPSArchiverIn.h"
#include "OPSConstants.h"
#include "Receiver.h"
#include "OPSMessage.h"
#include "Notifier.h"
#include "Listener.h"
#include <iostream>
#include "Participant.h"



namespace ops
{
	class TopicHandler : public Notifier<OPSMessage*>, Listener<char*>
	{
	public:
		///By Singelton, one TopicHandler per Topic (Name)
		static TopicHandler* getTopicHandler(Topic top)
		{
			if(instances.find(top.getName()) == instances.end())
			{
				instances[top.getName()] = new TopicHandler(top);
			}
			return instances[top.getName()];
		}
		///Destructor
		virtual ~TopicHandler()
		{
			delete receiver;
		}

	protected:
		///Override from Listener
		///Called whenever the receiver has new data.
		void onNewEvent(Notifier<char*>* sender, char* bytes)
		{
			//Deserialize data
			//ByteBuffer tBuf(bytes, Participant::PACKET_MAX_SIZE);

			//Create a temporay map and buf to peek data before putting it in to memMap
			MemoryMap tMap(memMap.getSegment(expectedSegment), memMap.getSegmentSize());
			ByteBuffer tBuf(&tMap);

			//Check protocol
			if(tBuf.checkProtocol())
			{

				//Read of message ID and fragmentation info, this is ignored so far.
				//std::string messageID = tBuf.ReadString();
				int nrOfFragments = tBuf.ReadInt();
				int currentFragment = tBuf.ReadInt();

				if(currentFragment != expectedSegment)
				{//For testing only...
					std::cout << "________________________Segment ERROR_____________________________" << std::endl;
					expectedSegment = 0;
					receiver->asynchWait(memMap.getSegment(expectedSegment), memMap.getSegmentSize());
					return;
				}
	
				if(currentFragment == (nrOfFragments - 1))
				{
					expectedSegment = 0;
					ByteBuffer buf(&memMap);
					
					buf.checkProtocol();
					int i1 = buf.ReadInt();
					int i2 = buf.ReadInt();

					//Read of the actual OPSMessage
					OPSArchiverIn archiver(&buf);

					OPSMessage* message = NULL;
					message = dynamic_cast<OPSMessage*>(archiver.inout(std::string("message"), message));
					if(message)
					{
						//Send it to Subscribers
						notifyNewEvent(message);
						delete message;
					}
					else
					{
						//Inform participant that invalid data is on the network.
						printf("_______________Factory_ERROR_____________\n");
					}
				}
				else
				{
					expectedSegment ++;
				}
				receiver->asynchWait(memMap.getSegment(expectedSegment), memMap.getSegmentSize());
			}
			else
			{
				//Inform participant that invalid data is on the network.
				std::cout << "________________________Protocol ERROR_____________________________" << std::endl;
			}
			
		}

	private:
		///By Singelton, one TopicHandler per Topic (name)
		static std::map<std::string, TopicHandler*> instances;
		
		///Constructor is private, use static getTopicHandler(Topic)
		TopicHandler(Topic top) 
			: expectedSegment(0),
			memMap(top.getSampleMaxSize() / OPSConstants::PACKET_MAX_SIZE + 1, OPSConstants::PACKET_MAX_SIZE)
		{
			IOService* ioService = Participant::getInstance(top.getDomainID(), top.getParticipantID())->getIOService();
			
			receiver = Receiver::create(top.getDomainAddress(), top.getPort(), ioService);
			receiver->addListener(this);
			receiver->asynchWait(memMap.getSegment(expectedSegment), memMap.getSegmentSize());
			
		}

		///The receiver used for this topic. 
		///TODO: make independent of implemntation through factory. Transport::getTransport(Topic t), see java implementation.
		Receiver* receiver;

		///Preallocated bytebuffer for receiving data
		
		//const static int DATA_ALLOCATION_SIZE = 2000000;
		//char bytes[DATA_ALLOCATION_SIZE];
		MemoryMap memMap;
		
		int expectedSegment;


	};

	
}
#endif