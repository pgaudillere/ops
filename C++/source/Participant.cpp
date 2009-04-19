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
#include "TopicHandler.h"


namespace ops
{
	//static
	std::map<std::string, Participant*> Participant::instances;


	Participant* Participant::getInstance(std::string domainID_)
	{
		return getInstance(domainID_, "DEFAULT_PARTICIPANT");
	}
	Participant* Participant::getInstance(std::string domainID_, std::string participantID)
	{
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
		ioService = IOService::create();
		if(!ioService)
		{
			//Error, should never happen, throw?
			return;
		}
		//Should trow?
		config = OPSConfig::getConfig();

		aliveDeadlineTimer = DeadlineTimer::create(ioService);
		aliveDeadlineTimer->addListener(this);

		threadPool = new SingleThreadPool();
		threadPool->addRunnable(this);
		threadPool->start();
	}
	Participant::~Participant()
	{

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

	void Participant::onNewEvent(Notifier<int>* sender, int message)
	{
		aliveDeadlineTimer->start(aliveTimeout);
	}

	void Participant::addTypeSupport(ops::SerializableFactory* typeSupport)
	{
		OPSObjectFactory::getInstance()->add(typeSupport);
	}

	Topic Participant::createTopic(std::string name)
	{
		Topic topic = config->getDomain(domainID)->getTopic(name);
		topic.setParticipantID(participantID);
		topic.setDomainID(domainID);
		
		return topic;
	}

	///By Singelton, one TopicHandler per Topic (Name)
	//This instance map should be owned by Participant.
	TopicHandler* Participant::getTopicHandler(Topic top)
	{
		if(topicHandlerInstances.find(top.getName()) == topicHandlerInstances.end())
		{
			topicHandlerInstances[top.getName()] = new TopicHandler(top, this);

		}
		return topicHandlerInstances[top.getName()];
	}


}