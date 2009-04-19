#include "Receiver.h"
#include "MulticastReceiver.h"

namespace ops
{
	Receiver* Receiver::create(std::string ip, int bindPort)
	{
		return new MulticastReceiver(ip, bindPort);
	}

}