#ifndef chat_MessageDataPublisher_h
#define chat_MessageDataPublisher_h

#include "Publisher.h"
#include "Topic.h"
#include "OPSObject.h"
#include "MessageData.h"
#include <string>

namespace chat {



class MessageDataPublisher : public ops::Publisher 
{
    
public:
    MessageDataPublisher(ops::Topic t)
        : ops::Publisher(t)
    {


    }
    
    ~MessageDataPublisher(void)
    {
    }
    
    void write(MessageData* data)
    {
        ops::Publisher::write(data);

    }
    /*
    ops::AckData writeReliable(MessageData* data, std::string destinationIdentity)
    {
        return ops::Publisher::writeReliable(data, destinationIdentity);

    }
    */
    

};


}


#endif