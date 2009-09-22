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
#ifndef ops_SendDataHandler_h
#define	ops_SendDataHandler_h

#include "Participant.h"
#include <map>
#include "Sender.h"
#include "OPSObject.h"
#include "Lockable.h"

namespace ops
{
	class SendDataHandler
	{
	public:
		SendDataHandler(Participant* part)
		{
			this->participant = part;
			
			
		}
		bool sendData(OPSObject* o)
		{
			//Deserialize data here
			
			SafeLock lock(&mutex);
			//Loop all senders and send data here
		}
		void addSink(std::string ip, int port)
		{
			//Create sender here
			
			SafeLock lock(&mutex);
			//Add sender here
		}
		void removeSink(std::string ip, int port)
		{
			//Find sender to delete here

			SafeLock lock(&mutex);
			//Remove, stop and delete sender here

		}

		virtual ~SendDataHandler(){}

	private:
		Participant* participant;
		std::map<std::string, Sender*> senders;
		Lockable mutex;

	};


}

#endif