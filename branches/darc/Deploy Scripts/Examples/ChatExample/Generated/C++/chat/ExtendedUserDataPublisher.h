#ifndef chat_ExtendedUserDataPublisher_h
#define chat_ExtendedUserDataPublisher_h

#include "Publisher.h"
#include "Topic.h"
#include "OPSObject.h"
#include "ExtendedUserData.h"
#include <string>

namespace chat {



class ExtendedUserDataPublisher : public ops::Publisher 
{
    
public:
    ExtendedUserDataPublisher(ops::Topic t)
        : ops::Publisher(t)
    {


    }
    
    ~ExtendedUserDataPublisher(void)
    {
    }
    
    void write(ExtendedUserData* data)
    {
        ops::Publisher::write(data);

    }
    /*
    ops::AckData writeReliable(ExtendedUserData* data, std::string destinationIdentity)
    {
        return ops::Publisher::writeReliable(data, destinationIdentity);

    }
    */
    

};


}


#endif