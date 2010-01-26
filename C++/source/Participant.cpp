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
				Domain* tDomain = newInst->config->getDomain(domainID_);

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
		config = OPSConfig::getConfig();
		if(!config)
		{
			throw std::exception("No config on rundirectory");
		}

		objectFactory = new OPSObjectFactoryImpl();
		
		//------------Will be created when need------
		partInfoPub = NULL;
		udpSendDataHandler = NULL;
		//-------------------------------------------

		//------------Setup udpReceiveDataHandler-----
		Topic topic("__", 0, "__","__"); //TODO: this is just a dummy construction, we should inject receiver int ReceiveDataHandler instead.
		topic.setParticipantID(participantID);
		topic.setTransport(Topic::TRANSPORT_UDP);
		udpReceiveDataHandler = new ReceiveDataHandler(topic, this);
		//--------------------------------------------
		
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
		ops::Topic infoTopic("ops.bit.ParticipantInfoTopic", 9494, "ops.ParticipantInfoData", ((MulticastDomain*)config->getDomain(domainID))->getDomainAddress());
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
		delete udpRec;


	}

	void Participant::run()
	{
		aliveDeadlineTimer->start(aliveTimeout);
		ioService->run();	
	}
	void Participant::reportError(Error* err)
	{
		notifyNewEvent(err);
	}

	void Participant::reportStaticError(Error* err)
	{
		std::map<std::string, Participant*>::iterator it = instances.begin();
		while(it !=instances.end())
		{
			it->second->notifyNewEvent(err);
			it++;
		}
		
	}

	void Participant::cleanUpReceiveDataHandlers()
	{
		SafeLock lock(&garbageLock);
///LA
		for(int i = garbageReceiveDataHandlers.size() - 1; i >= 0; i--)
		{
			if (garbageReceiveDataHandlers[i]->numReservedMessages() == 0) {
				delete garbageReceiveDataHandlers[i];
				std::vector<ReceiveDataHandler*>::iterator iter = garbageReceiveDataHandlers.begin() + i;
				garbageReceiveDataHandlers.erase(iter);
			}
		}
		////for(unsigned int i = 0; i < garbageReceiveDataHandlers.size(); i++)
		////{
		////	garbageReceiveDataHandlers[i]->stop();
		////	delete garbageReceiveDataHandlers[i];
		////}
		////garbageReceiveDataHandlers.clear();
///LA
	}
	void Participant::onNewEvent(Notifier<int>* sender, int message)
	{
		SafeLock lock(&serviceMutex);
		cleanUpReceiveDataHandlers();
		aliveDeadlineTimer->start(aliveTimeout);
		SafeLock lock2(&garbageLock);
		if(partInfoPub == NULL)
		{

			//Setup publisher if none exist
			partInfoData.languageImplementation = "c++";
			partInfoData.id = participantID;
			partInfoData.domain = domainID;
			partInfoData.ip= ((UDPReceiver*)udpReceiveDataHandler->getReceiver())->getAddress();
			partInfoData.mc_udp_port = ((UDPReceiver*)udpReceiveDataHandler->getReceiver())->getPort();
			
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
		Topic topic = config->getDomain(domainID)->getTopic(name);
		topic.setParticipantID(participantID);
		topic.setDomainID(domainID);
		
		
		return topic;
	}

	///By Singelton, one ReceiveDataHandler per Topic (Name)
	//TODO: Delegate to factory class
	ReceiveDataHandler* Participant::getReceiveDataHandler(Topic top)
	{
		SafeLock lock(&garbageLock);
		if(receiveDataHandlerInstances.find(top.getName()) != receiveDataHandlerInstances.end())
		{
			//If we already have a ReceiveDataHandler for this topic, return it.
			return receiveDataHandlerInstances[top.getName()]; 
			
		}
		else if(top.getTransport() == Topic::TRANSPORT_MC)
		{	
			ReceiveDataHandler* newReceiveDataHandler = NULL;
			//Check if there isnt already a multicast configured ReceiveDataHandler on tops port. If not create one.
			if(multicastReceiveDataHandlerInstances.find(top.getPort()) == multicastReceiveDataHandlerInstances.end())
			{
				newReceiveDataHandler = new ReceiveDataHandler(top, this);
				multicastReceiveDataHandlerInstances[top.getPort()] = newReceiveDataHandler;
				

			}
			partInfoData.subscribeTopics.push_back(TopicInfoData(top));
			receiveDataHandlerInstances[top.getName()] = newReceiveDataHandler;
			return multicastReceiveDataHandlerInstances[top.getPort()]; 
		}
		else if(top.getTransport() == Topic::TRANSPORT_TCP)
		{	
			ReceiveDataHandler* newReceiveDataHandler = NULL;
			//Check if there isnt already a tcp configured ReceiveDataHandler on tops port. If not create one.
			if(tcpReceiveDataHandlerInstances.find(top.getPort()) == tcpReceiveDataHandlerInstances.end())
			{
				newReceiveDataHandler = new ReceiveDataHandler(top, this);
				tcpReceiveDataHandlerInstances[top.getPort()] = newReceiveDataHandler;
				
			}
			partInfoData.subscribeTopics.push_back(TopicInfoData(top));
			receiveDataHandlerInstances[top.getName()] = newReceiveDataHandler;
			return tcpReceiveDataHandlerInstances[top.getPort()];
		}
		else if(top.getTransport() == Topic::TRANSPORT_UDP)
		{	
			partInfoData.subscribeTopics.push_back(TopicInfoData(top));
			receiveDataHandlerInstances[top.getName()] = udpReceiveDataHandler;
			return udpReceiveDataHandler;
		}
		else //For now we can not handle more transports
		{
			//Signal an error by returning NULL.
			reportError(&BasicError("Creation of ReceiveDataHandler failed. Topic = " + top.getName()));
			return NULL;
		}
		
	}//end getReceiveDataHandler

	//TODO: Delegate to factory class
	void Participant::releaseReceiveDataHandler(Topic top)
	{
		SafeLock lock(&garbageLock);
		if(receiveDataHandlerInstances.find(top.getName()) != receiveDataHandlerInstances.end())
		{
			ReceiveDataHandler* topHandler = receiveDataHandlerInstances[top.getName()];
			if(topHandler->getNrOfListeners() == 0)
			{
				//Time to mark this receiveDataHandler as garbage.
				receiveDataHandlerInstances.erase(receiveDataHandlerInstances.find(top.getName()));
///LA
				topHandler->stop();
///LA
				garbageReceiveDataHandlers.push_back(topHandler);
				if(top.getTransport() == Topic::TRANSPORT_MC)
				{
					multicastReceiveDataHandlerInstances.erase(multicastReceiveDataHandlerInstances.find(top.getPort()));
				}
				else if(top.getTransport() == Topic::TRANSPORT_TCP)
				{
					tcpReceiveDataHandlerInstances.erase(tcpReceiveDataHandlerInstances.find(top.getPort()));
				}

			}
		}
		
	}//end releaseReceiveDataHandler

	//TODO: Delegate to factory class
	SendDataHandler* Participant::getSendDataHandler(Topic top)
	{

		if(top.getTransport() == Topic::TRANSPORT_MC)
		{
			return new McSendDataHandler(top, ((MulticastDomain*)config->getDomain(domainID))->getLocalInterface(), 1); //TODO: make ttl configurable.
		}
		else if(top.getTransport() == Topic::TRANSPORT_UDP)
		{
			if(udpSendDataHandler == NULL)
			{
				udpSendDataHandler = new McUdpSendDataHandler();
				partInfoListener = new ParticipantInfoDataListener(udpSendDataHandler, this);

				partInfoSub = new Subscriber(createParticipantInfoTopic());
				partInfoSub->addDataListener(partInfoListener);

				partInfoSub->start();
			}
			return udpSendDataHandler;
		}
		else if(top.getTransport() == Topic::TRANSPORT_TCP)
		{
			if(tcpSendDataHandlers.find(top.getName()) == tcpSendDataHandlers.end() )
			{
				SendDataHandler* newSendDataHanler = new TCPSendDataHandler(top, getIOService());
				tcpSendDataHandlers[top.getName()] = newSendDataHanler;
				return newSendDataHanler;
			}
			else
			{
				return tcpSendDataHandlers[top.getName()];
			}			

		}
		else
		{
			return NULL;
		}

	}

	//TODO: Delegate to factory class
	void Participant::releaseSendDataHandler(Topic top)
	{
		


	}

}