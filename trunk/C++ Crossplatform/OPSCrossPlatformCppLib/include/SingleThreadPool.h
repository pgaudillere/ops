/**
* 
* Copyright (C) 2006-2009 Anton Gravestam.
*
* This file is part of OPS (Open Publish Subscribe).
*
* OPS (Open Publish Subscribe) is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* OPS (Open Publish Subscribe) is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with OPS (Open Publish Subscribe).  If not, see <http://www.gnu.org/licenses/>.
*/

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