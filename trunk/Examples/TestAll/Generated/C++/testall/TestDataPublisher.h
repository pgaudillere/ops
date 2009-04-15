#ifndef testall_TestDataPublisher_h
#define testall_TestDataPublisher_h

#include "Publisher.h"
#include "Topic.h"
#include "OPSObject.h"
#include "TestData.h"
#include <string>

namespace testall {



class TestDataPublisher : public ops::Publisher 
{
    
public:
    TestDataPublisher(ops::Topic<> t)
        : ops::Publisher(t)
    {


    }
    
    ~TestDataPublisher(void)
    {
    }
    
    void write(TestData* data)
    {
        ops::Publisher::write(data);

    }
    /*
    ops::AckData writeReliable(TestData* data, std::string destinationIdentity)
    {
        return ops::Publisher::writeReliable(data, destinationIdentity);

    }
    */
    

};


}


#endif