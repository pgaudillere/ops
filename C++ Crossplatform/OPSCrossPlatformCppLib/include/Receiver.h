#ifndef ops_ReceiverH
#define ops_ReceiverH

#include <string>


namespace ops
{
	class Receiver
	{
	public:
		virtual int receive(char* buf, int size) = 0;
		virtual bool sendReply(char* buf, int size) = 0;
		virtual int getPort() = 0;
		virtual std::string getAddress() = 0;
		virtual ~Receiver(){}
		
	};
}
#endif