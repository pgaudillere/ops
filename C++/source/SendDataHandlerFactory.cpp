#include "SendDataHandlerFactory.h"
#include "SendDataHandler.h"
#include "ParticipantInfoDataListener.h"
#include "Participant.h"
#include "McSendDataHandler.h"
#include "McUdpSendDataHandler.h"
#include "TCPSendDataHandler.h"
#include "MulticastDomain.h"

namespace ops
{

	
	SendDataHandler* SendDataHandlerFactory::getSendDataHandler(Topic& top, Participant* participant)
	{

		if(top.getTransport() == Topic::TRANSPORT_MC)
		{
			return new McSendDataHandler(top, ((MulticastDomain*)participant->getDomain())->getLocalInterface(), 1); //TODO: make ttl configurable.
		}
		else if(top.getTransport() == Topic::TRANSPORT_UDP)
		{
			if(udpSendDataHandler == NULL)
			{
				udpSendDataHandler = new McUdpSendDataHandler();
				partInfoListener = new ParticipantInfoDataListener(udpSendDataHandler, participant);

				participant->partInfoSub = new Subscriber(participant->createParticipantInfoTopic());
				participant->partInfoSub->addDataListener(partInfoListener);

				participant->partInfoSub->start();
			}
			return udpSendDataHandler;
		}
		else if(top.getTransport() == Topic::TRANSPORT_TCP)
		{
			if(tcpSendDataHandlers.find(top.getName()) == tcpSendDataHandlers.end() )
			{
				SendDataHandler* newSendDataHanler = new TCPSendDataHandler(top, participant->getIOService());
				tcpSendDataHandlers[top.getName()] = newSendDataHanler;
				return newSendDataHanler;
			}
			else
			{
				return tcpSendDataHandlers[top.getName()];
			}			

		}
		else
		{
			return NULL;
		}

	}


}