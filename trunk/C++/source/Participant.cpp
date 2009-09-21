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
#include "TopicHandler.h"
#include "OPSObjectFactoryImpl.h"
//#include "UDPReceiver.h"


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
		return instances[participantID];
	}

	Participant::Participant(std::string domainID_, std::string participantID_):
		domainID(domainID_), 
		participantID(participantID_),
		keepRunning(true),
		aliveTimeout(1000)
	{
		objectFactory = new OPSObjectFactoryImpl();
		ioService = IOService::create();
		if(!ioService)
		{
			//Error, should never happen, throw?
			return;
		}
		//Should trow?
		config = OPSConfig::getConfig();

		//partInfoPub = NULL;
		//udpRec = Receiver::createUDPReceiver(0);

		aliveDeadlineTimer = DeadlineTimer::create(ioService);
		aliveDeadlineTimer->addListener(this);

		threadPool = new SingleThreadPool();
		//threadPool = new MultiThreadPool();
		threadPool->addRunnable(this);
		threadPool->start();

		
		
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
		//delete partInfoPub;
		aliveDeadlineTimer->cancel();
		delete ioService;


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

	void Participant::cleanUpTopicHandlers()
	{
		SafeLock lock(&garbageLock);
///LA
		for(int i = garbageTopicHandlers.size() - 1; i >= 0; i--)
		{
			if (garbageTopicHandlers[i]->numReservedMessages() == 0) {
				delete garbageTopicHandlers[i];
				std::vector<TopicHandler*>::iterator iter = garbageTopicHandlers.begin() + i;
				garbageTopicHandlers.erase(iter);
			}
		}
		////for(unsigned int i = 0; i < garbageTopicHandlers.size(); i++)
		////{
		////	garbageTopicHandlers[i]->stop();
		////	delete garbageTopicHandlers[i];
		////}
		////garbageTopicHandlers.clear();
///LA
	}
	void Participant::onNewEvent(Notifier<int>* sender, int message)
	{
		SafeLock lock(&serviceMutex);
		cleanUpTopicHandlers();
		aliveDeadlineTimer->start(aliveTimeout);
		//SafeLock lock2(&garbageLock);
		//if(partInfoPub == NULL)
		//{
		//	//Setup publisher if none exist
		//	partInfoData.languageImplementation = "c++";
		//	partInfoData.id = participantID;
		//	partInfoData.domain = domainID;
		//	partInfoData.ips.push_back(((UDPReceiver*)udpRec)->getAddress());
		//	partInfoData.mc_udp_port = ((UDPReceiver*)udpRec)->getPort();
		//	
		//	partInfoPub = new Publisher(createParticipantInfoTopic());
		//}
		//partInfoPub->writeOPSObject(&partInfoData);

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

	///By Singelton, one TopicHandler per Topic (Name)
	TopicHandler* Participant::getTopicHandler(Topic top)
	{
		SafeLock lock(&garbageLock);
		if(topicHandlerInstances.find(top.getName()) == topicHandlerInstances.end())
		{
			topicHandlerInstances[top.getName()] = new TopicHandler(top, this);
			partInfoData.subscribeTopics.push_back(top.getName());

		}
		return topicHandlerInstances[top.getName()];
	}
	void Participant::releaseTopicHandler(Topic top)
	{
		SafeLock lock(&garbageLock);
		if(topicHandlerInstances.find(top.getName()) != topicHandlerInstances.end())
		{
			TopicHandler* topHandler = topicHandlerInstances[top.getName()];
			if(topHandler->getNrOfListeners() == 0)
			{
				//Time to mark this topicHandler as garbage.
				topicHandlerInstances.erase(topicHandlerInstances.find(top.getName()));
///LA
				topHandler->stop();
///LA
				garbageTopicHandlers.push_back(topHandler);

			}
		}
		
	}


}