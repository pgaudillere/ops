#ifndef ops_OPSConstants_h
#define ops_OPSConstants_h

#include <string>

namespace ops
{
	class OPSConstants
	{
	public:
		const static int PACKET_MAX_SIZE = 60000;
		const static int MESSAGE_MAX_SIZE = 2400000;
		const static __int64 MAX_DEADLINE_TIMEOUT = 0x0fffffffffffffff;
		//const static std::string DEFAULT_PARTICIPANT_ID("DEFAULT_PARTICIPANT");
	};
}

#endif