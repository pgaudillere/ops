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
#ifndef ops_BoostDeadlineTimerImpl_h
#define ops_BoostDeadlineTimerImpl_h

#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "Participant.h"

namespace ops
{
	class BoostDeadlineTimerImpl : public DeadlineTimer
	{
		bool isStarted;
		boost::asio::deadline_timer deadlineTimer;
	public:
		BoostDeadlineTimerImpl() 
			: isStarted(false),
			  deadlineTimer(*Participant::getIOService())
		{

		}
		virtual void start(__int64 timeout) 
		{
			if(deadlineTimer.expires_from_now(boost::posix_time::milliseconds(timeout)) > 0)
			{
				//TODO: Error handling?
			}
			if(!isStarted)
			{
				deadlineTimer.async_wait(boost::bind(&BoostDeadlineTimerImpl::asynchHandleDeadlineTimeout, this, boost::asio::placeholders::error));
				isStarted = true;
			}
		}
		void asynchHandleDeadlineTimeout(const boost::system::error_code& e)
		{
			notifyNewEvent(0);
			isStarted = false;

		}
		~BoostDeadlineTimerImpl()
		{
		
		}
	};
}

#endif