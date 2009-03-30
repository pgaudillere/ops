/* 
 * File:   Transport.h
 * Author: Anton Gravestam
 *
 * Created on den 22 oktober 2008, 20:01
 */

#ifndef ops_SenderH
#define	ops_SenderH

#include "ByteBuffer.h"
#include <string>

namespace ops
{
    ///Interface used to send data

    class Sender
    {
    public:

        virtual bool sendTo(char* buf, int size, std::string address, int port) = 0;
		virtual int receiveReply(char* buf, int size) = 0;
        virtual int getPort() = 0;
        virtual std::string getAddress() = 0;

        virtual ~Sender()
        {
        };
    private:


    };
}



#endif	/* _TRANSPORT_H */

