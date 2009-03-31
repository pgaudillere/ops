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

#ifndef ops_NotifierH
#define ops_NotifierH
#include <vector>
#include "Listener.h"
#include <boost/thread/mutex.hpp>

namespace ops
{
    ///class which in the conjunction with Listener forms an implementation of the
    ///observer GoF-pattern. classes extending this class extends an interface to which
    ///Listeners can register their interest to be notified when new events are available.
    template<class ArgType> 
	class Notifier
    {
    private:
        ///Vector that holds pointers to the Listeners
        std::vector<Listener<ArgType>*> listeners;

		boost::mutex mutex;
        
    protected:
        ///Called by subclasses that wishes to notify its listeners of the arrival of new events.
		void notifyNewEvent(ArgType arg)
		{
			boost::mutex::scoped_lock lock(mutex);
			for(unsigned int i = 0; i < listeners.size() ; i++)
			{
				listeners[i]->onNewEvent(this, arg);
			}
		}
    public:
        
        
        ///Register a Listener
        void addListener(Listener<ArgType>* listener)
		{
			boost::mutex::scoped_lock lock(mutex);
			listeners.push_back(listener);
		}

		void removeListener(Listener<ArgType>* listener)
		{
			boost::mutex::scoped_lock lock(mutex);
			for(unsigned int i = 0; i < listeners.size(); i++)
			{
				std::vector<Listener<ArgType>*>::iterator p = listeners.begin();
				p += i;
				listeners.erase(p);
			}
		}
        
        //Destructor:
        ~Notifier()
		{
			listeners.clear();
		}
    };
}
#endif