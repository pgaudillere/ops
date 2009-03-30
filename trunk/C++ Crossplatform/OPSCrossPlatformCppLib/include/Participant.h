#ifndef ops_ParticipantH
#define	ops_ParticipantH

#include <boost/asio.hpp>
#include <string>
#include "SingleThreadPool.h"


namespace ops
{
class Participant
{
public:
	const static int MESSAGE_MAX_SIZE = 65000;
	static ThreadPool* getReceiveThreadPool()
	{
		static SingleThreadPool* receiveThreadPool = NULL;
		
		if(receiveThreadPool == NULL)
		{
			receiveThreadPool = new SingleThreadPool();
			receiveThreadPool->start();
			
		}

		return receiveThreadPool;
	}

	static Participant* getParticipant()
	{
		static Participant* theParticipant = NULL;
		if(theParticipant == NULL)
		{
			theParticipant = new Participant();
		}
		return theParticipant;
	}

	static boost::asio::io_service* getIOService()
	{
		static boost::asio::io_service* ioService = NULL;
		if(ioService == NULL)
		{
			ioService = new boost::asio::io_service();	
		}
		return ioService;
	}
private:
	

};

}
#endif
