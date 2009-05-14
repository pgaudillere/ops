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

#ifndef ops_SubscriberH
#define	ops_SubscriberH


#include "Topic.h"
#include "Lockable.h"
#include "OPSObject.h"
#include "DataNotifier.h"
#include "DeadlineMissedListener.h"
#include "FilterQoSPolicy.h"
#include <list>
#include <deque>
#include "ThreadPool.h"
#include "Listener.h"
#include "OPSMessage.h"
#include "TopicHandler.h"
#include "DeadlineTimer.h"
//#include <boost/asio.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>

namespace ops
{

class Subscriber : public DataNotifier, public Lockable, public Listener<OPSMessage*>, public Listener<int>
{

public:
	Subscriber(Topic t);
    virtual ~Subscriber();

	///Starts communication.
    void start();
	///Stops communication, unubscribe this subscriber to data.
	void stop();

    DeadlineMissedEvent deadlineMissedEvent;
    void setDeadlineQoS(__int64 deadlineT);
    __int64 getDeadlineQoS();

    void addFilterQoSPolicy(FilterQoSPolicy* fqos);
    void removeFilterQoSPolicy(FilterQoSPolicy* fqos);

    __int64 getTimeBasedFilterQoS();
    void setTimeBasedFilterQoS(__int64 timeBaseMinSeparationMillis);

    Topic getTopic();

    bool waitForNewData(DWORD timeout);

    int getThreadPolicy();
    void setThreadPolicy(int threadPolicy);

	bool aquireMessageLock();
	void releaseMessageLock();
	OPSMessage* getMessage();

    std::string getName();
    void setName(std::string name);
    
    const static int SHARED_THREAD = 0;
    const static int EXCLUSIVE_THREAD = 1;


    bool isDeadlineMissed();

	void setHistoryMaxSize(int s);
	std::deque<OPSMessage*> getHistory();
	//OPSMessage* getHistoricMessage(int i);


	virtual OPSObject* getDataReference()
    {
        hasUnreadData = false;
        return data;
    }
	//Message listener callback
	void onNewEvent(Notifier<OPSMessage*>* sender, OPSMessage* message);
	//Deadline listener callback
	void onNewEvent(Notifier<int>* sender, int message);
    

protected:
	//virtual void saveCopy(OPSObject* o) = 0;
    void checkAndNotifyDeadlineMissed();
    //void onNewOPSObject(OPSObject* o);
	
	OPSMessage* message;

    OPSObject* data;
    OPSObject* getData();
    bool firstDataReceived;
	bool hasUnreadData;


private:

	///The Participant to which this Subscriber belongs.
	Participant* participant;

	///TopicHandler delivering new data samples to this Subscriber
	TopicHandler* topicHandler;

	///The Topic this Subscriber subscribes to.
    Topic topic;

	///Name of this subscriber
    std::string name;

	///Receiver side filters that will be applied to data from topicHandler before delivery to application layer.
    std::list<FilterQoSPolicy*> filterQoSPolicies;

	std::deque<OPSMessage*> messageBuffer;
	int messageBufferMaxSize;
	void addToBuffer(OPSMessage* mess);

	HANDLE filterQoSPolicyMutex;
    HANDLE newDataEvent;

    __int64 timeLastData;
    __int64 timeLastDataForTimeBase;
    __int64 timeBaseMinSeparationTime;
    __int64 deadlineTimeout;
    int threadPolicy;
    bool reliable;

    bool applyFilterQoSPolicies(OPSObject* o);
    bool applyKeyFilter(OPSObject* o);
    void setData(OPSObject* data);

	void registerForDeadlineTimeouts();
	void cancelDeadlineTimeouts();

    bool deadlineMissed;
    void setDeadlineMissed(bool deadlineMissed);

	bool started;


	__int64 currentPulicationID ;

	DeadlineTimer* deadlineTimer;


};

}
#endif
