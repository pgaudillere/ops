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
#ifndef ops_ParticipantInfoDataListener_h
#define	ops_ParticipantInfoDataListener_h

#include "DataNotifier.h"
#include "ParticipantInfoData.h"
#include "Subscriber.h"
#include "SendDataHandler.h"

namespace ops
{
	class Participant;
	class ParticipantInfoDataListener : public DataListener
	{
	public:
		ParticipantInfoDataListener(SendDataHandler* sndDataHandler, Participant* part);
		void onNewData(DataNotifier* notifier);
		virtual ~ParticipantInfoDataListener();

	private:
		SendDataHandler* sendDataHandler;
		Participant* participant;
		
		
	};


}

#endif
