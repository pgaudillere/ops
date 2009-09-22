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

#ifndef ops_ParticipantH
#define	ops_ParticipantH

#include <string>
#include "ThreadPool.h"
#include "Runnable.h"
#include "IOService.h"
#include "SerializableFactory.h"
#include <map>
#include "Topic.h"
#include "OPSConfig.h"
#include "OPSObjectFactory.h"
#include "DeadlineTimer.h"
#include "Error.h"
#include "Publisher.h"
#include "ParticipantInfoData.h"
#include "Receiver.h"

//


namespace ops
{
	//Forward declaration..
	class ReceiveDataHandler;

	class Participant : Runnable, Listener<int>, public Notifier<Error*>
	{
		friend class Subscriber;
	public:

		///By Singelton, one Participant per participantID
		static std::map<std::string, Participant*> instances;
		static Participant* getInstance(std::string domainID);
		static Participant* getInstance(std::string domainID, std::string participantID);
		static void reportStaticError(Error* err);
		ops::Topic createParticipantInfoTopic();

		void addTypeSupport(ops::SerializableFactory* typeSupport);

		Topic createTopic(std::string name);

		void run();

		void reportError(Error* err);

		//Deadline listener callback
		void onNewEvent(Notifier<int>* sender, int message);
		void cleanUpReceiveDataHandlers();


		IOService* getIOService()
		{
			return ioService;
		}
		OPSConfig* getConfig()
		{
			return config;
		}
		OPSObjectFactory* getObjectFactory()
		{
			return objectFactory;
		}

		~Participant();

	private:

		Participant(std::string domainID_, std::string participantID_);
		

		OPSConfig* config;
		IOService* ioService;
		ThreadPool* threadPool;
		DeadlineTimer* aliveDeadlineTimer;

		Publisher* partInfoPub;
		ParticipantInfoData partInfoData;

		//Receiver used to get a unigue port/id for this participant on the current machine
		Receiver* udpRec;


		///By Singelton, one ReceiveDataHandler per Topic (name) on this Participant
		std::map<std::string, ReceiveDataHandler*> receiveDataHandlerInstances;

		///By Singelton, one ReceiveDataHandler on multicast transport per port
		std::map<int, ReceiveDataHandler*> multicastReceiveDataHandlerInstances;

		///By Singelton, one ReceiveDataHandler on tcp transport per port
		std::map<int, ReceiveDataHandler*> tcpReceiveDataHandlerInstances;

		//Garbage vector for ReceiveDataHandlers, these can safely be deleted.
		std::vector<ReceiveDataHandler*> garbageReceiveDataHandlers;
		ops::Lockable garbageLock;

		//Visible to friends only
		ReceiveDataHandler* getReceiveDataHandler(Topic top);
		void releaseReceiveDataHandler(Topic top);

		//Mutex for ioService, used to shutdown safely
		Lockable serviceMutex;

		std::string domainID;
		std::string participantID;

		bool keepRunning;

		__int64 aliveTimeout;

		OPSObjectFactory* objectFactory;

		//Static Mutex used by factory methods getInstance()
		static Lockable creationMutex;



	};

}
#endif
