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
//#include "SingleThreadPool.h"
#include "IOService.h"


namespace ops
{
class Participant
{
public:
	
	///By Singelton, one Participant per participantID
	static std::map<std::string, Participant*> instances;
	static Participant* getInstance(std::string domainID);
	static Participant* getInstance(std::string domainID, std::string participantID);

	void addTypeSupport(ops::SerializableFactory* typeSupport);

	Topic createTopic(std::string name);

	//Subscriber* createSubscriber(Topic topic);
	//Subscriber* createSubscriber(std::string topicName);

	//Publisher* createPublisher(Topic topic);
	//Publisher* createPublisher(std::string topicName);





	static Participant* getParticipant()
	{
		static Participant* theParticipant = NULL;
		if(theParticipant == NULL)
		{
			theParticipant = new Participant();
		}
		return theParticipant;
	}

	static IOService* getIOService()
	{
		static IOService* ioService = NULL;
		if(ioService == NULL)
		{
			ioService = IOService::getInstance();	
		}
		return ioService;
	}

	//const static int PACKET_MAX_SIZE = 65000;
	//const static int MESSAGE_MAX_SIZE = 2600000;
	const static int PACKET_MAX_SIZE = 60000;
	const static int MESSAGE_MAX_SIZE = 2400000;

private:

	Participant();
	~Participant();

	OPSConfig* config;

	

};

}
#endif
