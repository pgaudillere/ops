#ifndef DeadlineMissedListener_h
#define DeadlineMissedListener_h

#include <vector>

namespace ops
{
//Forward declaration//////////
class DeadlineMissedEvent;/////
///////////////////////////////

class DeadlineMissedListener
{
public:
	virtual void onDeadlineMissed(DeadlineMissedEvent* e) = 0;

};

class DeadlineMissedEvent
{
private:
		///Vector that holds pointers to the DataListeners
		std::vector<DeadlineMissedListener*> listeners;
public:
	void addDeadlineMissedListener(DeadlineMissedListener* listener)
	{
		listeners.push_back(listener);
	}
	void notifyDeadlineMissed()
    {
        for(unsigned int i = 0; i < listeners.size() ; i++)
        {
			listeners[i]->onDeadlineMissed(this);
        }
	}

};

}
#endif
