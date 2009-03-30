#ifndef ops_ThreadPool
#define ops_ThreadPool

namespace ops
{
	//Forward declaration/
	class Runnable;///////
	//////////////////////

	class ThreadPool
	{
	public:
		virtual void addRunnable(Runnable* runnable) = 0;
		virtual void removeRunnable(Runnable* runnable) = 0;
	};

}



#endif