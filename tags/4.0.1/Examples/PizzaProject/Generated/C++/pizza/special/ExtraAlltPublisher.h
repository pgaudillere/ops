#ifndef pizza_special_ExtraAlltPublisher_h
#define pizza_special_ExtraAlltPublisher_h

#include "Publisher.h"
#include "Topic.h"
#include "OPSObject.h"
#include "ExtraAllt.h"
#include <string>

namespace pizza { namespace special {



class ExtraAlltPublisher : public ops::Publisher 
{
    
public:
    ExtraAlltPublisher(ops::Topic<ExtraAllt> t)
        : ops::Publisher(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {


    }
    
    ~ExtraAlltPublisher(void)
    {
    }
    
    void write(ExtraAllt* data)
    {
        ops::Publisher::write(data);

    }
    /*
    ops::AckData writeReliable(ExtraAllt* data, std::string destinationIdentity)
    {
        return ops::Publisher::writeReliable(data, destinationIdentity);

    }
    */
    

};


}}


#endif