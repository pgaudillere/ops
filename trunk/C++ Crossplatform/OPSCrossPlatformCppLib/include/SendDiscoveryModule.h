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

#ifndef ops_SendDiscoveryModuleH
#define	ops_SendDiscoveryModuleH

#include <vector>
#include <string>


//#include "TopicInterfaceDataSubscriber.h"

#include "MulticastReceiver.h"
#include <boost/thread/mutex.hpp>
#include "Thread.h"
#include "TopicInterface.h"
#include "TopicInterfaceDataHelper.h"



namespace ops
{
class SendDiscoveryModule : public Thread
{
    friend class SendTransport;
public:
	SendDiscoveryModule(std::string domainAddress);
    virtual ~SendDiscoveryModule();
    void updateInterfaces(TopicInterfaceData inter);

	void run();


private:

	MulticastReceiver mcReceiver;
    std::vector<TopicInterface> topicInterfaces;
    void removeInactiveInterfaces();
	bool keepRunning;
	TopicInterfaceDataHelper helper;
	boost::mutex mutex;
    //std::map<std::string, std::vector<TopicInterface> > topicInterfaceMap;


};

}
#endif





