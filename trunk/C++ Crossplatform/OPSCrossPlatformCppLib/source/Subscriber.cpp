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

#include "Subscriber.h"
#include "TimeHelper.h"
#include "Participant.h"

namespace ops
{
	Subscriber::Subscriber(Topic t) :
    	topic(t),
        hasUnreadData(false),
        deadlineTimeout(TimeHelper::infinite),
        timeBaseMinSeparationTime(0),
        threadPolicy(SHARED_THREAD),
        deadlineMissed(false),
		firstDataReceived(false)//,
		//deadlineTimer(*Participant::getIOService())		
    {
		deadlineTimer = DeadlineTimer::create(Participant::getInstance(topic.getDomainID(), topic.getParticipantID())->getIOService());
		deadlineTimer->addListener(this);
        filterQoSPolicyMutex = CreateMutex(NULL, false, NULL);
        newDataEvent = CreateEvent(NULL, true, false, NULL);
		timeLastData = TimeHelper::currentTimeMillis();

		topicHandler = TopicHandler::getTopicHandler(t);

    }
    Subscriber::~Subscriber()
    {
		topicHandler->removeListener(this);
    }

	

    void Subscriber::start()
    {
		
    	topicHandler->addListener(this);
		deadlineTimer->start(deadlineTimeout);
		//cancelDeadlineTimeouts();
		//registerForDeadlineTimeouts();
		
    }
	void Subscriber::onNewEvent(Notifier<OPSMessage*>* sender, OPSMessage* message)
	{
		onNewOPSObject(message->getData());
	}

	void Subscriber::onNewOPSObject(OPSObject* o)
    {
    	if(applyFilterQoSPolicies(o))
        {
            if(TimeHelper::currentTimeMillis() - timeLastDataForTimeBase > timeBaseMinSeparationTime || timeBaseMinSeparationTime == 0)
            {
            	firstDataReceived = true;
            	hasUnreadData = true;
            	//saveCopy(o);
         		data = o;
				notifyNewData();
				SetEvent(newDataEvent);
                timeLastDataForTimeBase = TimeHelper::currentTimeMillis();
                timeLastData = TimeHelper::currentTimeMillis();
                setDeadlineMissed(false);

				deadlineTimer->start(deadlineTimeout);
				
				//cancelDeadlineTimeouts();
				//registerForDeadlineTimeouts();
				
            }
        }
    }
  
    OPSObject* Subscriber::getData()
    {
    	hasUnreadData = false;
    	return data;
    }
    void Subscriber::setData(OPSObject* data)
    {
        SafeLock lock(this);
     	this->data = data;
    }
    Topic Subscriber::getTopic()
    {
    	return topic;
    }

    void Subscriber::addFilterQoSPolicy(FilterQoSPolicy* fqos)
    {
        WaitForSingleObject(filterQoSPolicyMutex, INFINITE);
        filterQoSPolicies.push_back(fqos);
        ReleaseMutex(filterQoSPolicyMutex);
    }
    void Subscriber::removeFilterQoSPolicy(FilterQoSPolicy* fqos)
    {
        WaitForSingleObject(filterQoSPolicyMutex, INFINITE);
        filterQoSPolicies.remove(fqos);
        ReleaseMutex(filterQoSPolicyMutex);
    }
	bool Subscriber::applyFilterQoSPolicies(OPSObject* obj)
    {
        WaitForSingleObject(filterQoSPolicyMutex, INFINITE);
        bool ret = true;
		std::list<FilterQoSPolicy*>::iterator p;
        p = filterQoSPolicies.begin();
        while(p != filterQoSPolicies.end())
        {
            if(!(*p)->applyFilter(obj))
            {
                ret = false;
                break;
            }
            p++;
        }
        ReleaseMutex(filterQoSPolicyMutex); 
        return ret;
        
	}
	void Subscriber::setDeadlineQoS(__int64 millis)
	{
		deadlineTimeout = millis;
		//cancelDeadlineTimeouts();
		//registerForDeadlineTimeouts();
        //transport->setReceiveTimeout(millis);
    }
    __int64 Subscriber::getDeadlineQoS()
    {
        return deadlineTimeout;
    }

    void Subscriber::checkAndNotifyDeadlineMissed()
    {		
     	if(isDeadlineMissed())
        {
			//printf("DeadlineMissed timeLastData = %d, currTime = %d, deadlineTimeout = %d\n", timeLastData, currTime, deadlineTimeout);
         	deadlineMissedEvent.notifyDeadlineMissed();
            timeLastData = TimeHelper::currentTimeMillis();  
        }

    }
    __int64 Subscriber::getTimeBasedFilterQoS()
    {
     	return timeBaseMinSeparationTime;
    }
    void Subscriber::setTimeBasedFilterQoS(__int64 timeBaseMinSeparationMillis)
    {
     	timeBaseMinSeparationTime = timeBaseMinSeparationMillis;
    }

    bool Subscriber::waitForNewData(DWORD timeout)
	{
    	if(hasUnreadData)
        {
         	return true;
        }
		else if(WaitForSingleObject(newDataEvent, timeout) != WAIT_TIMEOUT)
		{
			ResetEvent(newDataEvent);
			return true;
		}
		else
		{
			return false;
		}
	}

    int Subscriber::getThreadPolicy()
    {
    	return threadPolicy;
    }
    void Subscriber::setThreadPolicy(int threadPolicy)
    {
     	this->threadPolicy = threadPolicy;
    }

    std::string Subscriber::getName()
    {
    	return name;
    }
    void Subscriber::setName(std::string name)
    {
     	this->name = name;
    }
    bool Subscriber::isDeadlineMissed()
    {
		__int64 currTime = TimeHelper::currentTimeMillis();
		if(currTime - timeLastData > deadlineTimeout)
        {
            deadlineMissed = true;
			return deadlineMissed;
		}
    	return false;
    }
    void Subscriber::setDeadlineMissed(bool deadlineMissed)
    {
     	this->deadlineMissed = deadlineMissed;
    }

	void Subscriber::registerForDeadlineTimeouts()
	{
		deadlineTimer->addListener(this);
		//boost::asio::deadline_timer t(Participant::getIOService(), boost::posix_time::milliseconds(deadlineTimeout));
		//deadlineTimer.cancel();

		/*if(deadlineTimer.expires_from_now(boost::posix_time::milliseconds(deadlineTimeout)) > 0)
		{*/
		//deadlineTimer.async_wait(boost::bind(&Subscriber::asynchHandleDeadlineTimeout, this, boost::asio::placeholders::error));
		//}
		
	}
	void Subscriber::cancelDeadlineTimeouts()
	{
		deadlineTimer->start(deadlineTimeout);
		//if(deadlineTimer.expires_from_now(boost::posix_time::milliseconds(deadlineTimeout)) > 0)
		//{
		//	//deadlineTimer.async_wait(boost::bind(&Subscriber::asynchHandleDeadlineTimeout, this, boost::asio::placeholders::error));
		//}
		//else
		//{
		//	/*boost::asio::deadline_timer newTimer(*Participant::getIOService());
		//	deadlineTimer = newTimer;
		//	deadlineTimer.expires_from_now(boost::posix_time::milliseconds(deadlineTimeout));*/
		//}
		
	}
	//void Subscriber::asynchHandleDeadlineTimeout(const boost::system::error_code& e)
	//{
	//	if (e != boost::asio::error::operation_aborted)
	//	{
	//		// Timer was not cancelled, take necessary action.
	//		deadlineMissedEvent.notifyDeadlineMissed();

	//		cancelDeadlineTimeouts();
	//		registerForDeadlineTimeouts();
	//	}
	//	
	//	//t.reset();
	//	
	//}
	void Subscriber::onNewEvent(Notifier<int>* sender, int message)
	{
		deadlineMissedEvent.notifyDeadlineMissed();
		deadlineTimer->start(deadlineTimeout);
		//cancelDeadlineTimeouts();
	}


}
 