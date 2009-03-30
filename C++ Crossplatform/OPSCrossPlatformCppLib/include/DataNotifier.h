#ifndef DataNotifier_h
#define DataNotifier_h
#include <vector>
#include "DataListener.h"
#include "OPSObject.h"

namespace ops
{
    ///class which in the conjunction with DataListener forms an implementation of the
    ///observer GoF-pattern. classes extending this class extends an interface to which
    ///DataListeners can register their interest to be notified when new OPSObjects are available.
    class DataNotifier
    {
    private:
        ///Vector that holds pointers to the DataListeners
        std::vector<DataListener*> listeners;
        
    protected:
        ///Called by subclasses that wishes to notify its listeners of the arrival of new data.
		void notifyNewData();
    public:
        
        
        ///Register a DataListener
        void addDataListener(DataListener* listener);
        
        //Destructor:
        ~DataNotifier();
    };
}
#endif
