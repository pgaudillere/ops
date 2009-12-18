#ifndef pizza_special_LHCDataPublisher_h
#define pizza_special_LHCDataPublisher_h

#include "Publisher.h"
#include "Topic.h"
#include "OPSObject.h"
#include "LHCData.h"
#include <string>

namespace pizza { namespace special {



class LHCDataPublisher : public ops::Publisher 
{
    
public:
    LHCDataPublisher(ops::Topic<LHCData> t)
        : ops::Publisher(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {


    }
    
    ~LHCDataPublisher(void)
    {
    }
    
    void write(LHCData* data)
    {
        ops::Publisher::write(data);

    }
    /*
    ops::AckData writeReliable(LHCData* data, std::string destinationIdentity)
    {
        return ops::Publisher::writeReliable(data, destinationIdentity);

    }
    */
    

};


}}


#endif