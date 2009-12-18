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
	Lockable(const Lockable& l)
	{
		mutex = CreateMutex(NULL, false, NULL);
	}
	Lockable & operator = (const Lockable& l)
	{
		mutex = CreateMutex(NULL, false, NULL);
		return *this;
	}
	/*Lockable& Lockable::operator=(const Lockable& l) 
	{
	  CopyObj(rhs);
	  return *this;
	}*/

	bool lock()
	{
		if(WaitForSingleObject(mutex, INFINITE) != WAIT_FAILED)
		{
			return true;
		}
		return false;
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
