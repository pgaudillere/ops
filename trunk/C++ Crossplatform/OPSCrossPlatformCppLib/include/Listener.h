#ifndef ops_ListenerH
#define ops_ListenerH


namespace ops
{
//Forward declaration//
template<class ArgType> class Notifier;////
///////////////////////
    
    ///Interface that used in conjunction with DataNotifier 
    ///forms an implmentation of the Observer GoF-pattern.
	template<class ArgType>
    class Listener
    {
    public:
        ///If this interface is registred with a DataNotifier, this method will be called when the
		///DataNotifier wants to inform its DataListeners that new data is available.
		virtual void onNewEvent(Notifier<ArgType>* sender, ArgType arg) = 0;
    };
}
#endif
