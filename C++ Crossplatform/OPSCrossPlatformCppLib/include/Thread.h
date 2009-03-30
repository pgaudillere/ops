#ifndef ops_ThreadH
#define ops_ThreadH

#include <boost/thread/thread.hpp>

namespace ops
{
	///Abstract Thread class for other classes that wishes to be "Active".
    class Thread
    {
    public:
        
        Thread();
        ~Thread();
        int start();
		void stop();
		bool join();
		virtual void run() = 0;
		//boost::thread* GetThreadHandle();
		static void Thread::EntryPoint(void* pthis);
    
    protected:
        bool started;
		bool threadRunning;
		boost::thread* thread;
        
    };
}


#endif
