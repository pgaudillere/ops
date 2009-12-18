/**
* 
* Copyright (C) 2006-2009 Anton Gravestam.
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




