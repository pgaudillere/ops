#include "DeadlineTimer.h"
#include "BoostDeadlineTimerImpl.h"

namespace ops
{

	DeadlineTimer* DeadlineTimer::create()
	{
		return new BoostDeadlineTimerImpl();
	}

}