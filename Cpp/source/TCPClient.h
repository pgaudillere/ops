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

#ifndef ops_TCPCLientH
#define ops_TCPClientH

#include <string>
#include "Receiver.h"
#include "IOService.h" 
#include "BytesSizePair.h"

#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "BoostIOServiceImpl.h"
#include "boost/bind.hpp"
#include "Participant.h"
#include "BasicError.h"

namespace ops
{

    class TCPClient : public Receiver
    {
    public:

        TCPClient(std::string serverIP, int serverPort, IOService* ioServ) : connected(false), accumulatedSize(0)
        {

            boost::asio::io_service* ioService = ((BoostIOServiceImpl*) ioServ)->boostIOService; //((BoostIOServiceImpl*)Participant::getIOService())->boostIOService;
            boost::asio::ip::address ipAddr(boost::asio::ip::address_v4::from_string(serverIP));
            endpoint = new boost::asio::ip::tcp::endpoint(ipAddr, serverPort);

            sock = new boost::asio::ip::tcp::socket(*ioService);



            boost::system::error_code error = boost::asio::error::host_not_found;
            sock->async_connect(*endpoint, boost::bind(&TCPClient::handleConnect, this, boost::asio::placeholders::error));




        }

        void handleConnect(const boost::system::error_code& error)
        {
            if (error)
            {
                //connect again
                connected = false;
                //std::cout << "connection failed tcp asynch" << std::endl;
                Participant::reportStaticError(&ops::BasicError("TCPClient", "handleConnect", "connection failed tcp asynch"));
                sock->async_connect(*endpoint, boost::bind(&TCPClient::handleConnect, this, boost::asio::placeholders::error));
            }
            else
            {
                connected = true;

                boost::asio::socket_base::receive_buffer_size option(16000000);
                boost::system::error_code ec;
                ec = sock->set_option(option, ec);
                sock->get_option(option);
                if (ec != 0 || option.value() != 16000000)
                {
                    //std::cout << "Socket buffer size could not be set" << std::endl;
                    Participant::reportStaticError(&ops::BasicError("TCPClient", "TCPClient", "Socket buffer size could not be set"));
                }

                //Disable Nagle algorithm

                boost::asio::ip::tcp::no_delay option2(true);
                sock->set_option(option2);
                //if(sockOptErr != 0)
                //{
                //std::cout << "Failed to disable Nagle algorithm." << std::endl;
                //Participant::reportStaticError(&ops::BasicError("Failed to disable Nagle algorithm."));
                //}

                std::cout << "connected tcp asynch" << std::endl;
                notifyNewEvent(BytesSizePair("", -5)); //Connection was down but has been reastablished.
            }
        }

        virtual ~TCPClient()
        {
            delete sock;
            delete endpoint;

        }

        void asynchWait(char* bytes, int size)
        {

            data = bytes;
            max_length = size;

            if (connected)
            {
                //Always start by reading the packet size when using tcp
                sock->async_receive(
                        boost::asio::buffer(data, 22),
                        boost::bind(&TCPClient::handle_receive_sizeInfo, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
            }

        }

        void handle_receive_sizeInfo(const boost::system::error_code& error, size_t nrBytesReceived)
        {
            if (!connected)
            {
                notifyNewEvent(BytesSizePair("", -2));
                return;
            }
            if (!error)
            {
                accumulatedSize += nrBytesReceived;
                if (accumulatedSize < 22)// we have not gotten the size pack yet
                {
                    sock->async_receive(
                            boost::asio::buffer(data + accumulatedSize, 22 - accumulatedSize),
                            boost::bind(&TCPClient::handle_receive_sizeInfo, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
                }
                else // We are ready to receive the main data package
                {
                    accumulatedSize = 0;
                    max_length = *((int*) (data + 18));
                    sock->async_receive(
                            boost::asio::buffer(data, max_length),
                            boost::bind(&TCPClient::handle_receive_from, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
                }
            }
            else
            {
                //handleReadError(error);
                //printf("Error \n");
                Participant::reportStaticError(&ops::BasicError("TCPClient", "handle_receive_sizeInfo", "Error in receive."));
                notifyNewEvent(BytesSizePair("", -1));

                //Close the socket and try to connect again
                connected = false;
                sock->close();
                sock->async_connect(*endpoint, boost::bind(&TCPClient::handleConnect, this, boost::asio::placeholders::error));
            }


        }

        void handle_receive_from(const boost::system::error_code& error, size_t nrBytesReceived)
        {

            if (!connected)
            {
                notifyNewEvent(BytesSizePair("", -2));
                return;
            }
            if (!error && nrBytesReceived > 0)
            {
                accumulatedSize += nrBytesReceived;
                if (accumulatedSize < max_length)// we have not gotten all bytes yet
                {
                    sock->async_receive(
                            boost::asio::buffer(data + accumulatedSize, max_length - accumulatedSize),
                            boost::bind(&TCPClient::handle_receive_from, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
                }
                else
                {

                    notifyNewEvent(BytesSizePair(data, accumulatedSize));
                    accumulatedSize = 0;
                }

            }
            else
            {
                //handleReadError(error);
                printf("Error \n");
                notifyNewEvent(BytesSizePair("", -1));

                //Close the socket and try to connect again
                connected = false;
                sock->close();
                sock->async_connect(*endpoint, boost::bind(&TCPClient::handleConnect, this, boost::asio::placeholders::error));
            }


        }

        virtual void stop()
        {
        }

    private:
        int port;
        std::string ipaddress;
        boost::asio::ip::tcp::socket* sock;
        boost::asio::ip::tcp::endpoint* endpoint;

        int max_length; //enum { max_length = 65535 };
        char* data; //[max_length];
        bool connected;

        int accumulatedSize;


    };
}
#endif
