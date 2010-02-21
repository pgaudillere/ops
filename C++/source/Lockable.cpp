#include "OPSTypeDefs.h"
#include <boost/thread/mutex.hpp>
#include "Lockable.h"
namespace ops
{

    Lockable::Lockable()
    {
        mutex = new boost::mutex();
    }

    Lockable::Lockable(const Lockable& l)
    {
        mutex = new boost::mutex();
    }

    Lockable & Lockable::operator =(const Lockable& l)
    {
        mutex = new boost::mutex();
        return *this;
    }

    /*Lockable& Lockable::operator=(const Lockable& l)
    {
      CopyObj(rhs);
      return *this;
    }*/

    bool Lockable::lock()
    {
        if (mutex->try_lock())
        {
            return true;
        }
        return false;
    }

    void Lockable::unlock()
    {
        mutex->unlock();
    }

    Lockable::~Lockable()
    {
        //mutex->unlock();
        delete mutex;



    }
}
