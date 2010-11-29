#ifndef chat_ExtendedChatDataPublisher_h
#define chat_ExtendedChatDataPublisher_h

#include "Publisher.h"
#include "Topic.h"
#include "OPSObject.h"
#include "ExtendedChatData.h"
#include <string>

namespace chat {



class ExtendedChatDataPublisher : public ops::Publisher 
{
    
public:
    ExtendedChatDataPublisher(ops::Topic t)
        : ops::Publisher(t)
    {


    }
    
    ~ExtendedChatDataPublisher(void)
    {
    }
    
    void write(ExtendedChatData* data)
    {
        ops::Publisher::write(data);

    }
    /*
    ops::AckData writeReliable(ExtendedChatData* data, std::string destinationIdentity)
    {
        return ops::Publisher::writeReliable(data, destinationIdentity);

    }
    */
    

};


}


#endif