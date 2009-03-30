#ifndef ops_LockableH
#define ops_LockableH
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace ops
{
class SafeLock;


class Lockable
{
	friend class SafeLock;

private:
	HANDLE mutex;
public:

	Lockable()
	{
		mutex = CreateMutex(NULL, false, NULL);
	}
	void lock()
	{
		WaitForSingleObject(mutex, INFINITE);
	}
	void unlock()
	{
		ReleaseMutex(mutex);
    }
	virtual ~Lockable()
	{
    	CloseHandle(mutex);    	

    }

};

class SafeLock
{
	private:
	Lockable* lockable;
	public:
	SafeLock(Lockable* lockable)
	{
		this->lockable = lockable;
		this->lockable->lock();
	}
	~SafeLock()
	{
		this->lockable->unlock();
	}

};


}


#endif
