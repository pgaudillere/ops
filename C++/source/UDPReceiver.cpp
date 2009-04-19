//==============================================================================
// Class UDPReciever
//
// Description:
// Class used to recieve UDP messages from a certain port.
//
//==============================================================================

#include <iostream>
#include "stdio.h"

#include "UDPReceiver.h"


namespace ops
{
	using boost::asio::ip::udp;

	UDPReceiver::UDPReceiver(int bindPort)
	{
		
		ioService = new boost::asio::io_service();
		
		udp::resolver resolver(*ioService);
		udp::resolver::query query(boost::asio::ip::host_name(),"");
		udp::resolver::iterator it=resolver.resolve(query);
		boost::asio::ip::address addr=(it++)->endpoint().address();
		ipaddress = addr.to_string();
		localEndpoint = new udp::endpoint(addr, bindPort);
		
		sock = new udp::socket(*ioService, *localEndpoint);
		port = sock->local_endpoint().port();
		
		

	}
	UDPReceiver::UDPReceiver(int bindPort, std::string address)
	{

	}

	void UDPReceiver::setReceiveTimeout(int millis)
	{

	}

	UDPReceiver::~UDPReceiver()
	{

	}


	int UDPReceiver::receive(char* buf, int size)
	{
		try
		{
			int nReceived = sock->receive_from(boost::asio::buffer(buf, size), lastEndpoint);
			return nReceived;
		}
		catch(...)
		{
			return -1;
		}
	}


	bool UDPReceiver::sendReply(char* buf, int size)
	{
		try
        {
            sock->send_to(boost::asio::buffer(buf, size), lastEndpoint);
            return true;
        }
        catch (...)
        {
            return false;
        }

	}
}




