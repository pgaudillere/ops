/* 
 * File:   UDPSender.h
 * Author: Anton Gravestam
 *
 * Created on den 22 oktober 2008, 20:14
 */

#ifndef ops_UDPSenderH
#define	ops_UDPSenderH

#include "Sender.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "HeartBeat.h"
#include "Notifier.h"

namespace ops
{
    ///A sender implementation that dispatches messages over ip based UDP.
    class UDPSender : Sender, Notifier<const HeartBeat&>
    {
    public:
        ///Costructs a new UDPSender an binds its underlying socket to local host
        ///and a dynamically allocated local port.
		///This class accepts synchronous write operations through sendTo().
		///This class dispatches HeartBeats comming in to its attached Listener<HeartBeat>:s.
        UDPSender();
        ~UDPSender();
        
        ///Override from Sender
        bool sendTo(char* buf, int size, std::string ip, int port);
		///Override from Sender
		int receiveReply(char* buf, int size);
        ///Override from Sender
        int getPort() {return socket->local_endpoint().port();};
        ///Override from Sender
        std::string getAddress() {return socket->local_endpoint().address().to_string();};

		bool waitForReply(int timeout);

    private:
        ///This UDPSender wraps boost socket functionality.
        ///These are the required boost members to perform operations required.
        boost::asio::ip::udp::endpoint* localEndpoint;  //<-- The local port to bind to.
        boost::asio::ip::udp::socket* socket;           //<-- The socket that sends data.
        boost::asio::io_service io_service;             //<-- Required for boost sockets.

		


    };

}
#endif	

