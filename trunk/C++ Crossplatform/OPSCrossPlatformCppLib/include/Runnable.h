#ifndef ops_Runnable
#define ops_Runnable

namespace ops
{
	class ThreadPool;
	class Runnable
	{
	public:
		virtual void run(ThreadPool* caller) = 0;
	};
}

#endif