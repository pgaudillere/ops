#include "Sender.h"
#include "UDPSender.h"

namespace ops
{

	Sender* Sender::create()
	{
		return new UDPSender();
	}


}