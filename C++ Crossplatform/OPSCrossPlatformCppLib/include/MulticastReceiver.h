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

#ifndef ops_MulticastReceiverH
#define ops_MulticastReceiverH

#include <string>
#include "Participant.h"
#include "Receiver.h"
#include "boost/bind.hpp"
#include "ByteBuffer.h"

namespace ops
{
	using boost::asio::ip::udp;

	class MulticastReceiver : public Receiver
	{
	public:
		MulticastReceiver(std::string mcAddress, int bindPort)
		{
			boost::asio::io_service* ioService = Participant::getIOService();
			udp::resolver resolver(*ioService);
			udp::resolver::query query(boost::asio::ip::host_name(),"");
			udp::resolver::iterator it=resolver.resolve(query);
			boost::asio::ip::address addr=(it++)->endpoint().address();

			localEndpoint = new udp::endpoint(addr, bindPort);

			sock = new boost::asio::ip::udp::socket(*ioService);



			sock->open(localEndpoint->protocol());
			/*boost::asio::socket_base::receive_buffer_size option(1048576);
			sock->set_option(option);*/


			sock->set_option(boost::asio::ip::udp::socket::reuse_address(true));
			sock->bind(*localEndpoint);


			// Join the multicast group.
			const boost::asio::ip::address multicastAddress = boost::asio::ip::address::from_string(mcAddress);
			sock->set_option(boost::asio::ip::multicast::join_group(multicastAddress));

			ipaddress = mcAddress;
			port = sock->local_endpoint().port();

			sock->async_receive(
				boost::asio::buffer(data, max_length), 
				boost::bind(&MulticastReceiver::handle_receive_from, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

		}

		void handle_receive_from(const boost::system::error_code& error,
			size_t nrBytesReceived)
		{
			
			if (!error && nrBytesReceived > 0)
			{
				//printf("Data receivedm in multicast receiver\n");
				handleReadOK();
				//notifyNewEvent(data);
			
			}
			else
			{
				handleReadError();
			}
			
			
		}
		void handleReadOK()
		{
			notifyNewEvent(data);
			sock->async_receive(
				boost::asio::buffer(data, max_length), 
				boost::bind(&MulticastReceiver::handle_receive_from, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

		}
		void handleReadError()
		{
			//notifyNewEvent(data);
			sock->async_receive(
				boost::asio::buffer(data, max_length), 
				boost::bind(&MulticastReceiver::handle_receive_from, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

		}


		~MulticastReceiver()
		{
			delete sock;
			delete localEndpoint;
			delete ioService;
		}
		int receive(char* buf, int size)
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
		int available()
		{
			return sock->available();
		}
		bool sendReply(char* buf, int size)
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

		enum { max_length = 65535 };
		char data[max_length];


	};
}
#endif