#include "Participant.h"


namespace ops
{
	//static
	std::map<std::string, Participant*> Participant::instances;

	Participant* getInstance(std::string domainID)
	{
		return getInstance(domainID, "DEFAULT_PARTICIPANT");
	}
	Participant* getInstance(std::string domainID, std::string participantID)
	{
		if(instances.find(participantID) == instances.end())
		{
			Participant* newInst = new Participant();
			bool configOK = newInst->findConfig(domainID);

			if(configOK)
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

	Participant::Participant()
	{
		config = OPSConfig::getConfig();
	}
	Participant::~Participant()
	{

	}

		

	void addTypeSupport(ops::SerializableFactory* typeSupport)
	{


	}

	Topic createTopic(std::string name)
	{


	}


}