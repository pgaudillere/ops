#ifndef ops_DataListenerH
#define ops_DataListenerH

#include "DataNotifier.h"
#include "OPSObject.h"

namespace ops
{
//Forward declaration//
class DataNotifier;////
///////////////////////
    
    ///Interface that used in conjunction with DataNotifier 
    ///forms an implmentation of the Observer GoF-pattern.
    class DataListener
    {
    public:
        ///If this interface is registred with a DataNotifier, this method will be called when the
		///DataNotifier wants to inform its DataListeners that new data is available.
		virtual void onNewData(ops::DataNotifier* sender) = 0;
    };
}
#endif
