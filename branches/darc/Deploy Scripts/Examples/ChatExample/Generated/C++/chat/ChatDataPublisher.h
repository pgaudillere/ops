#ifndef chat_ChatDataPublisher_h
#define chat_ChatDataPublisher_h

#include "Publisher.h"
#include "Topic.h"
#include "OPSObject.h"
#include "ChatData.h"
#include <string>

namespace chat {



class ChatDataPublisher : public ops::Publisher 
{
    
public:
    ChatDataPublisher(ops::Topic t)
        : ops::Publisher(t)
    {


    }
    
    ~ChatDataPublisher(void)
    {
    }
    
    void write(ChatData* data)
    {
        ops::Publisher::write(data);

    }
    /*
    ops::AckData writeReliable(ChatData* data, std::string destinationIdentity)
    {
        return ops::Publisher::writeReliable(data, destinationIdentity);

    }
    */
    

};


}


#endif