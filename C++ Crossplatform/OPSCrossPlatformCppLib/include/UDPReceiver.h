//==============================================================================
// Class UDPReciever
//
// Description:
// Class used to recieve UDP messages from a certain port.
//
//==============================================================================

#ifndef ops_UDPReceiverH
#define ops_UDPReceiverH

#include <string>
#include "Receiver.h"
#include "ByteBuffer.h"
#include <boost/asio.hpp>



namespace ops
{
    
	class UDPReceiver : public Receiver
    {
    public:
        
        UDPReceiver(int bindPord);
		UDPReceiver(int bindPord, std::string address);        
		~UDPReceiver();
        
		int receive(char* buf, int size);
		bool sendReply(char* buf, int size);
		void setReceiveTimeout(int millis);
        
        int getPort()
        {
            return port;
        }
        std::string getAddress()
        {
            return ipaddress;
    	}
        
    private:
        int port;
        std::string ipaddress;
		boost::asio::ip::udp::socket* sock;
		boost::asio::ip::udp::endpoint* localEndpoint;
		boost::asio::ip::udp::endpoint lastEndpoint;
		
		
		boost::asio::io_service* ioService;



    };
}
#endif


