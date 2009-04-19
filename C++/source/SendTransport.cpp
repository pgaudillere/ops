#include "SendTransport.h"
#include "CommException.h"
#include "UDPReceiver.h"
#include <boost/thread/mutex.hpp>
#include "OPSConstants.h"



namespace ops
{
	using namespace std;
	std::vector<SendTransport*> SendTransport::openTransports;
    SendTransport* SendTransport::getDefaultTransport(std::string domain)
    {
    	for(unsigned int i = 0; i < openTransports.size() ; i++)
        {
        	if(openTransports[i]->getDomain() == domain)
        	{
             	return openTransports[i];
        	}
        }
    	SendTransport* defaultSendTransport = NULL;
        defaultSendTransport = new SendTransport(domain);
        openTransports.push_back(defaultSendTransport);

        return defaultSendTransport;
    }
	SendTransport::SendTransport(std::string domain)
    {
    	sendDiscovery = new SendDiscoveryModule(domain);
        this->domain = domain;
    }
    SendTransport::~SendTransport()
    {
    }
    std::string SendTransport::getDomain()
    {
        return domain;
    }
    
 	void SendTransport::send(const char* bytes,int size, std::string topic)
    {
		boost::mutex::scoped_lock lock(sendDiscovery->mutex);

    	for(unsigned int i = 0; i < sendDiscovery->topicInterfaces.size(); i++)
        {
        	if(sendDiscovery->topicInterfaces[i].getData().topicName == topic)
            {
            	string ip = sendDiscovery->topicInterfaces[i].getData().address;
                int port = sendDiscovery->topicInterfaces[i].getData().port;
               	sender.sendTo((char*)bytes, size, ip, port);
			}
        }
    }

    std::string SendTransport::getSocketInterfaceID()
    {
    	/*char portS[33];
        itoa(sender.getPort(), portS, 10);
        char* ip = UDPReceiver::GetLocalIP();

    	std::string socketID = string(ip) + string(":") + string(portS);*/

		
        return sender.getAddress();
    }

	    //AckData SendTransport::sendWithAck(const char* bytes, int size, std::string topic, std::string destination, int timeout)
    //{
    //	boost::mutex::scoped_lock lock(sendDiscovery->mutex);
    //    bool destinationFound = false;
    //    bool replyReceived = false;
    //    AckData* ackP = NULL;

    //	for(unsigned int i = 0; i < sendDiscovery->topicInterfaces.size(); i++)
    //    {
    //    	if(sendDiscovery->topicInterfaces[i].getData().topicName == topic)
    //        {
				////sender.flushReceiveBuffer();
    //        	string ip = sendDiscovery->topicInterfaces[i].getData().address;
    //            int port = sendDiscovery->topicInterfaces[i].getData().port;
    //           	sender.sendTo((char*)bytes, size, ip, port);

    //            if(containsDestination(sendDiscovery->topicInterfaces[i].getData(), destination))
    //            {
				//	char* repBytes = new char[ops::constants::MAX_SIZE];
    //             	if(sender.receiveReply(repBytes, ops::constants::MAX_SIZE, timeout))
    //                {
    //                	ByteBuffer buf(repBytes);

				//		bool headerOK = buf.CheckHeader();
				//		if(!headerOK)
				//		{
				//			delete repBytes;
				//			destinationFound = true;
				//			continue;
				//		}
    //                 	ackP = (AckData*)buf.ReadOPSObject(&AckDataHelper());
    //                    delete repBytes;
    //                    destinationFound = true;
    //                    replyReceived = true;
    //                }
    //                else
    //                {
    //                    delete repBytes;
    //                    destinationFound = true;
    //                }
    //            }
    //        }


    //    }
    //    if(destinationFound)
    //    {
    //     	if(replyReceived)
    //        {
    //         	AckData ack = *ackP;
    //            delete ackP;
    //            return ack;
    //        }
    //        throw exceptions::CommException("No reply from destination.");

    //    }
    //    throw exceptions::CommException("Destination not found.");


    //}
    //bool SendTransport::containsDestination(const TopicInterfaceData& topicData, const std::string& dest)
    //{
    // 	for(unsigned int i = 0 ; i < topicData.reliableIdentities.size() ; i ++)
    //    {
    //     	if(topicData.reliableIdentities[i] == dest)
    //        {
    //         	return true;
    //        }
    //    }
    //    return false;

    //}

}
