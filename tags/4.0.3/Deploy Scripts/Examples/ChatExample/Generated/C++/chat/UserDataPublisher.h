#ifndef chat_UserDataPublisher_h
#define chat_UserDataPublisher_h

#include "Publisher.h"
#include "Topic.h"
#include "OPSObject.h"
#include "UserData.h"
#include <string>

namespace chat {



class UserDataPublisher : public ops::Publisher 
{
    
public:
    UserDataPublisher(ops::Topic t)
        : ops::Publisher(t)
    {


    }
    
    ~UserDataPublisher(void)
    {
    }
    
    void write(UserData* data)
    {
        ops::Publisher::write(data);

    }
    /*
    ops::AckData writeReliable(UserData* data, std::string destinationIdentity)
    {
        return ops::Publisher::writeReliable(data, destinationIdentity);

    }
    */
    

};


}


#endif