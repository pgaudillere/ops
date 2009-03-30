#ifndef __underscoredPackName___classNamePublisher_h
#define __underscoredPackName___classNamePublisher_h

#include "Publisher.h"
#include "Topic.h"
#include "OPSObject.h"
#include "__className.h"
#include <string>

__packageDeclaration



class __classNamePublisher : public ops::Publisher 
{
    
public:
    __classNamePublisher(ops::Topic<__className> t)
        : ops::Publisher(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {


    }
    
    ~__classNamePublisher(void)
    {
    }
    
    void write(__className* data)
    {
        ops::Publisher::write(data);

    }
    /*
    ops::AckData writeReliable(__className* data, std::string destinationIdentity)
    {
        return ops::Publisher::writeReliable(data, destinationIdentity);

    }
    */
    

};


__packageCloser

#endif