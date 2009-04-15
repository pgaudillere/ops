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
	Subscriber(Topic<> t);
    virtual ~Subscriber();

    void start();

    DeadlineMissedEvent deadlineMissedEvent;
    void setDeadlineQoS(__int64 deadlineT);
    __int64 getDeadlineQoS();

    void addFilterQoSPolicy(FilterQoSPolicy* fqos);
    void removeFilterQoSPolicy(FilterQoSPolicy* fqos);

    __int64 getTimeBasedFilterQoS();
    void setTimeBasedFilterQoS(__int64 timeBaseMinSeparationMillis);

    Topic<> getTopic();

    bool waitForNewData(DWORD timeout);

    int getThreadPolicy();
    void setThreadPolicy(int threadPolicy);

    std::string getName();
    void setName(std::string name);
    
    const static int SHARED_THREAD = 0;
    const static int EXCLUSIVE_THREAD = 1;


    bool isDeadlineMissed();


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
	virtual void saveCopy(OPSObject* o) = 0;
    void checkAndNotifyDeadlineMissed();
    void onNewOPSObject(OPSObject* o);
	
    OPSObject* data;
    OPSObject* getData();
    bool firstDataReceived;
	bool hasUnreadData;


private:

	TopicHandler* topicHandler;

    Topic<> topic;

    std::string name;

    std::list<FilterQoSPolicy*> filterQoSPolicies;

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
	//void asynchHandleDeadlineTimeout(const boost::system::error_code& e);

    bool deadlineMissed;
    void setDeadlineMissed(bool deadlineMissed);


	__int64 currentPulicationID ;

	//boost::asio::deadline_timer deadlineTimer;
	DeadlineTimer* deadlineTimer;


};

}
#endif
