
//#include "boost\asio\basic_socket.hpp"


#include "boost\asio\basic_datagram_socket.hpp"


#include "UDPSender.h"
#include "TimeHelper.h"

namespace ops
{
    using boost::asio::ip::udp;
    UDPSender::UDPSender()
           
    {
        localEndpoint = new boost::asio::ip::udp::endpoint(udp::v4(), 0);
        socket = new boost::asio::ip::udp::socket(io_service, localEndpoint->protocol());

		boost::asio::socket_base::send_buffer_size option(16000000);
		socket->set_option(option);
		boost::asio::socket_base::non_blocking_io command(true);
		socket->io_control(command);

		
    }

    UDPSender::~UDPSender()
    {
        
        socket->close();
        delete socket;
        delete localEndpoint;
    }

    bool UDPSender::sendTo(char* buf, int size, std::string ip, int port)
    {
        try
        {
            boost::asio::ip::address ipaddress = boost::asio::ip::address::from_string(ip.c_str());
            boost::asio::ip::udp::endpoint endpoint(ipaddress, port);
            socket->send_to(boost::asio::buffer(buf, size), endpoint);
            return true;
        }
        catch (...)
        {
            return false;
        }

    }
	int UDPSender::receiveReply(char* buf, int size)
	{
		int nReceived = socket->receive(boost::asio::buffer(buf, size));
		return nReceived;
	}
	bool UDPSender::waitForReply(int timeout)
	{
		/*__int64 startWait = TimeHelper::currentTimeMillis();
		while(TimeHelper::currentTimeMillis())*/
		return false;
	}

}

