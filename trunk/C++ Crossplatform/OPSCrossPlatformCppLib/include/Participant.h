/**
* 
* Copyright (C) 2006-2009 Anton Gravestam.
*
* This notice apply to all source files, *.cpp, *.h, *.java, and *.cs in this directory 
* and all its subdirectories if nothing else is explicitly stated within the source file itself.
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
	const static int MESSAGE_MAX_SIZE = 65000;
	/*static ThreadPool* getReceiveThreadPool()
	{
		static SingleThreadPool* receiveThreadPool = NULL;
		
		if(receiveThreadPool == NULL)
		{
			receiveThreadPool = new SingleThreadPool();
			receiveThreadPool->start();
			
		}

		return receiveThreadPool;
	}*/

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
private:
	

};

}
#endif
