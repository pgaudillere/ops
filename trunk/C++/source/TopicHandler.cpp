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

#include "TopicHandler.h"
#include "BasicError.h" 
#include "MulticastDomain.h"

namespace ops
{
	///Constructor.
	TopicHandler::TopicHandler(Topic top, Participant* part) :
		expectedSegment(0),
		memMap(top.getSampleMaxSize() / OPSConstants::PACKET_MAX_SIZE + 1, OPSConstants::PACKET_MAX_SIZE),
		firstReceived(false),
		currentMessageSize(0)
	{
		message = NULL;
		participant = part;
		MulticastDomain* mcDomain = dynamic_cast<MulticastDomain*>(participant->getConfig()->getDomain(top.getDomainID()));

		IOService* ioService = participant->getIOService();

		receiver = Receiver::create(top.getDomainAddress(), top.getPort(), ioService, mcDomain->getLocalInterface(), mcDomain->getInSocketBufferSize());
		receiver->addListener(this);
		receiver->asynchWait(memMap.getSegment(expectedSegment), memMap.getSegmentSize());

	}
	///Destructor
	TopicHandler::~TopicHandler()
	{
		delete receiver;
	}


	///Override from Listener
	///Called whenever the receiver has new data.
	void TopicHandler::onNewEvent(Notifier<BytesSizePair>* sender, BytesSizePair byteSizePair)
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

			currentMessageSize += byteSizePair.size;

			if(currentFragment != expectedSegment)
			{//For testing only...
				if(firstReceived)
				{
					BasicError err("Segment Error, sample will be lost.");
					participant->reportError(&err);
				}
				expectedSegment = 0;
				currentMessageSize = 0;
				receiver->asynchWait(memMap.getSegment(expectedSegment), memMap.getSegmentSize());
				return;
			}

			if(currentFragment == (nrOfFragments - 1))
			{
				firstReceived = true;
				expectedSegment = 0;
				ByteBuffer buf(&memMap);

				buf.checkProtocol();
				int i1 = buf.ReadInt();
				int i2 = buf.ReadInt();

				//Read of the actual OPSMessage
				OPSArchiverIn archiver(&buf);

				SafeLock lock(&messageLock);

				OPSMessage* oldMessage = message;
				
				message = NULL;
				message = dynamic_cast<OPSMessage*>(archiver.inout(std::string("message"), message));
				if(message)
				{
					//Put spare bytes in data of message
					int nrOfSpareBytes = currentMessageSize - buf.GetSize();

					if(nrOfSpareBytes > 0)
					{
					
						message->getData()->spareBytes.reserve(nrOfSpareBytes);
						message->getData()->spareBytes.resize(nrOfSpareBytes, 0);

						//This will read the rest of the bytes as raw bytes and put them into sparBytes field of data.
						buf.ReadChars(&(message->getData()->spareBytes[0]), nrOfSpareBytes);
						
					}

					//Add message to a reference handler that will keep the message until it is no longer needed.
					messageReferenceHandler.addReservable(message);
					message->reserve();
					//Send it to Subscribers
					notifyNewEvent(message);
					//This will delete this message if no one reserved it in the application layer.
					if(oldMessage) oldMessage->unreserve();
					currentMessageSize = 0;
				}
				else
				{
					//Inform participant that invalid data is on the network.
					BasicError err("Unexpected type received. Type creation failed.");
					participant->reportError(&err);
					message = oldMessage;
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
			BasicError err("Protocol ERROR.");
			participant->reportError(&err);
			receiver->asynchWait(memMap.getSegment(expectedSegment), memMap.getSegmentSize());
		}

	}

	bool TopicHandler::aquireMessageLock()
	{
		return messageLock.lock();
	}
	void TopicHandler::releaseMessageLock()
	{
		messageLock.unlock();
	}



}