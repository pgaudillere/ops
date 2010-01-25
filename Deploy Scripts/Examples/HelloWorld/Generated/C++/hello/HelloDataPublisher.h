#ifndef hello_HelloDataPublisher_h
#define hello_HelloDataPublisher_h

#include "Publisher.h"
#include "Topic.h"
#include "OPSObject.h"
#include "HelloData.h"
#include <string>

namespace hello {



class HelloDataPublisher : public ops::Publisher 
{
    
public:
    HelloDataPublisher(ops::Topic t)
        : ops::Publisher(t)
    {


    }
    
    ~HelloDataPublisher(void)
    {
    }
    
    void write(HelloData* data)
    {
        ops::Publisher::write(data);

    }
    /*
    ops::AckData writeReliable(HelloData* data, std::string destinationIdentity)
    {
        return ops::Publisher::writeReliable(data, destinationIdentity);

    }
    */
    

};


}


#endif