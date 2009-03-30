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