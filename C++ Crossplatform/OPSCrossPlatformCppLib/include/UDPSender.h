/**
* 
* Copyright (C) 2006-2009 Anton Gravestam.
*
* This notice apply to all source files, *.cpp, *.h, *.java, and *.cs in this directory 
* and all its subdirectories if nothing else is explicitly stated within the source file itself.
*
* This file is part of OPS (Open Publish Subscribe).
*
* OPS (Open Publish Subscribe) is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* OPS (Open Publish Subscribe) is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with OPS (Open Publish Subscribe).  If not, see <http://www.gnu.org/licenses/>.
*/

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
#include "Notifier.h"

namespace ops
{
    ///A sender implementation that dispatches messages over ip based UDP.
    class UDPSender : Sender//, Notifier<const HeartBeat&>
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

