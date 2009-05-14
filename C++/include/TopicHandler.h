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
#include "BytesSizePair.h"
#include "ReferenceHandler.h"



namespace ops
{
	class TopicHandler : public Notifier<OPSMessage*>, Listener<BytesSizePair>
	{
	public:
		
		///Constructor.
		TopicHandler(Topic top, Participant* part);
		///Destructor
		virtual ~TopicHandler();

		bool aquireMessageLock();
		void releaseMessageLock();

		void stop();

	protected:
		///Override from Listener
		///Called whenever the receiver has new data.
		void onNewEvent(Notifier<BytesSizePair>* sender, BytesSizePair byteSizePair);

	private:

		///The receiver used for this topic. 
		Receiver* receiver;

		///Preallocated MemoryMap for receiving data
		MemoryMap memMap;

		//The Participant to which this TopicHandler belongs.
		Participant* participant;

		///Current OPSMessage, valid until next sample arrives.
		OPSMessage* message;

		///The accumulated size in bytes of the current message
		int currentMessageSize;

		Lockable messageLock;

		///ReferenceHandler that keeps track of object created on reception and deletes them when no one is interested anymore.
		ReferenceHandler messageReferenceHandler;
		
		int expectedSegment;
		bool firstReceived;


	};

	
}
#endif