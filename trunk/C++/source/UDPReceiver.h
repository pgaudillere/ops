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


