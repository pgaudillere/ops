#ifndef opstestComplexDataPublisher_h
#define opstestComplexDataPublisher_h

#include "Publisher.h"
#include "Topic.h"
#include "Transport.h"
#include "OPSObject.h"
#include "ComplexData.h"
#include "ComplexDataHelper.h"
#include <string>

namespace opstest
{


class ComplexDataPublisher : public ops::Publisher 
{
    
public:
    ComplexDataPublisher(ops::Topic<ComplexData> t)
        : ops::Publisher(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {
        setObjectHelper(new ComplexDataHelper());   

    }
    
    ~ComplexDataPublisher(void)
    {
    }
    
    void write(ComplexData* data)
    {
        ops::Publisher::write(data);

    }
    ops::AckData writeReliable(ComplexData* data, std::string destinationIdentity)
    {
        return ops::Publisher::writeReliable(data, destinationIdentity);

    }
    

};

}


#endif