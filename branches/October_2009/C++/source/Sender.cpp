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

#include "Sender.h"
#include "UDPSender.h"
#include "TCPServer.h"

namespace ops
{

	Sender* Sender::create(std::string localInterface, int ttl, __int64 outSocketBufferSize)
	{
		return new UDPSender(localInterface, ttl, outSocketBufferSize);
	}
	Sender* Sender::createTCPServer(std::string ip, int port, IOService* ioService)
	{
		return new TCPServer(ip, port, ioService);
	}


}