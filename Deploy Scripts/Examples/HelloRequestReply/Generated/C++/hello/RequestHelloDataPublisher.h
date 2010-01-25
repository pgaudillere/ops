#ifndef hello_RequestHelloDataPublisher_h
#define hello_RequestHelloDataPublisher_h

#include "Publisher.h"
#include "Topic.h"
#include "OPSObject.h"
#include "RequestHelloData.h"
#include <string>

namespace hello {



class RequestHelloDataPublisher : public ops::Publisher 
{
    
public:
    RequestHelloDataPublisher(ops::Topic t)
        : ops::Publisher(t)
    {


    }
    
    ~RequestHelloDataPublisher(void)
    {
    }
    
    void write(RequestHelloData* data)
    {
        ops::Publisher::write(data);

    }
    /*
    ops::AckData writeReliable(RequestHelloData* data, std::string destinationIdentity)
    {
        return ops::Publisher::writeReliable(data, destinationIdentity);

    }
    */
    

};


}


#endif