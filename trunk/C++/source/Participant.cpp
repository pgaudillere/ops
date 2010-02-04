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

#include "Participant.h"
#include "SingleThreadPool.h"
#include "MultiThreadPool.h"
#include "ReceiveDataHandler.h"
#include "ReceiveDataHandlerFactory.h"
#include "SendDataHandlerFactory.h"
#include "OPSObjectFactoryImpl.h"
#include "UDPReceiver.h"
#include "BasicError.h"
#include "McUdpSendDataHandler.h"
#include "McSendDataHandler.h"
#include "TCPSendDataHandler.h"
//#include "ParticipantInfoDataSubscriber.h"


namespace ops
{
	//static
	std::map<std::string, Participant*> Participant::instances;
	Lockable Participant::creationMutex;


	Participant* Participant::getInstance(std::string domainID_)
	{
		return getInstance(domainID_, "DEFAULT_PARTICIPANT");
	}
	Participant* Participant::getInstance(std::string domainID_, std::string participantID)
	{
		SafeLock lock(&creationMutex);
		if(instances.find(participantID) == instances.end())
		{
			try
			{
				Participant* newInst = new Participant(domainID_, participantID);
				Domain* tDomain = newInst->getDomain();

				if(tDomain != NULL)
				{
					instances[participantID] = newInst;
				}
				else
				{
					return NULL;
				}
			}
			catch(...)
			{
				return NULL;
			}
		}
		return instances[participantID];
	}

	Participant::Participant(std::string domainID_, std::string participantID_):
		domainID(domainID_), 
		participantID(participantID_),
		keepRunning(true),
		aliveTimeout(1000)
	{
		
		ioService = IOService::create();
		
		if(!ioService)
		{
			//Error, should never happen, throw?
			throw std::exception("Could not dreateIOService");
		}


		//Should trow?
		OPSConfig* config = OPSConfig::getConfig();
		if(!config)
		{
			throw std::exception("No config on rundirectory");
		}

		//Get the domain from config.
		domain = config->getDomain(domainID);
		objectFactory = new OPSObjectFactoryImpl();
		
		//-----------Create delegate helper classes---
		errorService = new ErrorService();
		receiveDataHandlerFactory = new ReceiveDataHandlerFactory(this);
		sendDataHandlerFactory = new SendDataHandlerFactory();
		//--------------------------------------------

		//------------Will be created when need------
		partInfoPub = NULL;
		//-------------------------------------------

		//------------Create timer for peridic events-
		aliveDeadlineTimer = DeadlineTimer::create(ioService);
		aliveDeadlineTimer->addListener(this);
		//--------------------------------------------

		//------------Create thread pool--------------
		threadPool = new SingleThreadPool();
		//threadPool = new MultiThreadPool();
		threadPool->addRunnable(this);
		threadPool->start();
		//--------------------------------------------

		
		
	}
	ops::Topic Participant::createParticipantInfoTopic()
	{
		ops::Topic infoTopic("ops.bit.ParticipantInfoTopic", 9494, "ops.ParticipantInfoData", ((MulticastDomain*)domain)->getDomainAddress());
		infoTopic.setDomainID(domainID);
		infoTopic.setParticipantID(participantID);
		infoTopic.setTransport(Topic::TRANSPORT_MC);
		
		return infoTopic;
	}
	Participant::~Participant()
	{
		SafeLock lock(&serviceMutex);
		delete partInfoPub;
		aliveDeadlineTimer->cancel();
		delete ioService;
		delete errorService;
		delete domain;
		delete receiveDataHandlerFactory;


	}

	void Participant::run()
	{
		aliveDeadlineTimer->start(aliveTimeout);
		ioService->run();	
	}
	void Participant::reportError(Error* err)
	{
		errorService->report(err);
	}

	void Participant::reportStaticError(Error* err)
	{
		std::map<std::string, Participant*>::iterator it = instances.begin();
		while(it !=instances.end())
		{
			it->second->getErrorService()->report(err);
			it++;
		}
	}

	
	void Participant::onNewEvent(Notifier<int>* sender, int message)
	{
		SafeLock lock(&serviceMutex);
		cleanUpReceiveDataHandlers();
		aliveDeadlineTimer->start(aliveTimeout);
		//SafeLock lock2(&garbageLock);
		if(partInfoPub == NULL)
		{

			partInfoPub = new Publisher(createParticipantInfoTopic());

			
		}
		partInfoPub->writeOPSObject(&partInfoData);

	}

	void Participant::addTypeSupport(ops::SerializableFactory* typeSupport)
	{
		//OPSObjectFactory::getInstance()->add(typeSupport);
		objectFactory->add(typeSupport);
	}

	Topic Participant::createTopic(std::string name)
	{
		Topic topic = domain->getTopic(name);
		topic.setParticipantID(participantID);
		topic.setDomainID(domainID);
		
		
		return topic;
	}

	///Deprecated, use addErrorListener instead. Add a listener for OPS core reported Errors
	void Participant::addListener(Listener<Error*>* listener)
	{
		errorService->addListener(listener);
		
	}
	///Deprecated, use removeErrorListener instead. Remove a listener for OPS core reported Errors
	void Participant::removeListener(Listener<Error*>* listener)
	{
		errorService->removeListener(listener);
	}

	

	///By Singelton, one ReceiveDataHandler per Topic (Name)
	ReceiveDataHandler* Participant::getReceiveDataHandler(Topic top)
	{
		return receiveDataHandlerFactory->getReceiveDataHandler(top, this);
		
	}//end getReceiveDataHandler

	void Participant::releaseReceiveDataHandler(Topic top)
	{
		receiveDataHandlerFactory->releaseReceiveDataHandler(top, this);
	}

	//TODO: Delegate to factory class
	SendDataHandler* Participant::getSendDataHandler(Topic top)
	{

		return sendDataHandlerFactory->getSendDataHandler(top, this);
	}

	//TODO: Delegate to factory class
	void Participant::releaseSendDataHandler(Topic top)
	{
		sendDataHandlerFactory->releaseSendDataHandler(top, this);


	}

}