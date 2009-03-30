#ifndef ops_SingleThreadPool
#define ops_SingleThreadPool

#include "TimeHelper.h"
#include "Thread.h"
#include "ThreadPool.h"
#include <boost/thread/mutex.hpp>
#include "Runnable.h"
#include <vector>

namespace ops
{
	class SingleThreadPool : public Thread, public ThreadPool 
	{
	public:
		virtual void addRunnable(Runnable* runnable)
		{
			boost::mutex::scoped_lock lock(mutex);
			runnables.push_back(runnable);
		}
		virtual void removeRunnable(Runnable* runnable)
		{
			for(unsigned int i = 0; i < runnables.size(); i++)
			{
				std::vector<Runnable*>::iterator p = runnables.begin();
				p += i;

				boost::mutex::scoped_lock lock(mutex);
				runnables.erase(p);
			}
			
		}

		void run()
		{
			while(true)
			{
				//__int64 startTime = TimeHelper::currentTimeMillis();
				for(unsigned int i = 0; i < runnables.size(); i++)
				{
					boost::mutex::scoped_lock lock(mutex);
					runnables[i]->run(this);
				}
				/*if(TimeHelper::currentTimeMillis() - startTime < 1)
				{
					TimeHelper::sleep(1);
				}*/
			}
		}

	private:
		std::vector<Runnable*> runnables;
		boost::mutex mutex;
	};

}

#endif