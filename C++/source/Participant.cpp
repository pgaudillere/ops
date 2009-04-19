#include "Participant.h"


namespace ops
{
	//static
	std::map<std::string, Participant*> Participant::instances;

	Participant* Participant::getInstance(std::string domainID)
	{
		return getInstance(domainID, "DEFAULT_PARTICIPANT");
	}
	Participant* Participant::getInstance(std::string domainID, std::string participantID)
	{
		if(instances.find(participantID) == instances.end())
		{
			Participant* newInst = new Participant(domainID);
			Domain* tDomain = newInst->config->getDomain(domainID);

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

	Participant::Participant(std::string domainID_): domainID(domainID_)
	{
		config = OPSConfig::getConfig();
	}
	Participant::~Participant()
	{

	}

		

	void Participant::addTypeSupport(ops::SerializableFactory* typeSupport)
	{
		OPSObjectFactory::getInstance()->add(typeSupport);
	}

	Topic Participant::createTopic(std::string name)
	{
		return config->getDomain(domainID)->getTopic(name);
	}


}