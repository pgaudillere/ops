#ifndef ops_DataListenerH
#define ops_DataListenerH

#include "DataNotifier.h"
#include "OPSObject.h"

namespace ops
{
//Forward declaration//
class BytesNotifier;////
///////////////////////
    
    ///Interface that used in conjunction with DataNotifier 
    ///forms an implmentation of the Observer GoF-pattern.
    class BytesListener
    {
    public:
        ///If this interface is registred with a DataNotifier, this method will be called when the
		///DataNotifier wants to inform its DataListeners that new data is available.
		virtual void onNewBytes(char* bytes, int size) = 0;
    };
}
#endif
