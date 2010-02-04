#ifndef ops_SendDataHandlerFactory_h
#define ops_SendDataHandlerFactory_h

#include <map>
#include "Topic.h"
namespace ops 
{
	class SendDataHandler;
	class ParticipantInfoDataListener;
	class Participant;


	class SendDataHandlerFactory
	{
	private:
		SendDataHandler* udpSendDataHandler;

		std::map<std::string, SendDataHandler*> tcpSendDataHandlers;

		ParticipantInfoDataListener* partInfoListener;
	
	public:
		SendDataHandler* getSendDataHandler(Topic& top, Participant* participant);
		void releaseSendDataHandler(Topic& top, Participant* participant);		
	};

}

#endif