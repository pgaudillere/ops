
#include "DataNotifier.h"

namespace ops
{
    
    DataNotifier::~DataNotifier()
    {
        listeners.clear();
    }
    
	void DataNotifier::notifyNewData()
    {
        for(unsigned int i = 0; i < listeners.size() ; i++)
        {
			listeners[i]->onNewData(this);
        }
    }
	void DataNotifier::addDataListener(DataListener* listener)
    {
        listeners.push_back(listener);
    }
    
}
