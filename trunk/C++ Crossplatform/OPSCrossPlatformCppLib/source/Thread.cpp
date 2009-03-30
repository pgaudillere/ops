


#include "Thread.h"

namespace ops
{
	Thread::Thread() : started(false)
    {
	}
    
    Thread::~Thread()
    {
		thread->interrupt();
	}
    
    int Thread::start()
	{
		if(!started)
		{
			thread = new boost::thread(&Thread::EntryPoint, this);
			started = true;
		}
        return 0;
	}

	bool Thread::join()
	{
		thread->join();
		return true;
    }
   /* 
	boost::thread* Thread::GetThreadHandle()
    {
		return thread;
    }*/
    
    void  Thread::stop()
    {
		thread->interrupt();
    }
    
    /*static */ void  Thread::EntryPoint(void* pthis)
    {
        Thread* pt = (Thread*)pthis;
        pt->run();
    }
}



