#ifndef pizza_special_CheesePublisher_h
#define pizza_special_CheesePublisher_h

#include "Publisher.h"
#include "Topic.h"
#include "OPSObject.h"
#include "Cheese.h"
#include <string>

namespace pizza { namespace special {



class CheesePublisher : public ops::Publisher 
{
    
public:
    CheesePublisher(ops::Topic<Cheese> t)
        : ops::Publisher(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {


    }
    
    ~CheesePublisher(void)
    {
    }
    
    void write(Cheese* data)
    {
        ops::Publisher::write(data);

    }
    /*
    ops::AckData writeReliable(Cheese* data, std::string destinationIdentity)
    {
        return ops::Publisher::writeReliable(data, destinationIdentity);

    }
    */
    

};


}}


#endif