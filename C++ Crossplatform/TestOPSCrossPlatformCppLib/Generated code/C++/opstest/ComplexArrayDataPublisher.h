#ifndef opstestComplexArrayDataPublisher_h
#define opstestComplexArrayDataPublisher_h

#include "Publisher.h"
#include "Topic.h"
#include "Transport.h"
#include "OPSObject.h"
#include "ComplexArrayData.h"
#include "ComplexArrayDataHelper.h"
#include <string>

namespace opstest
{


class ComplexArrayDataPublisher : public ops::Publisher 
{
    
public:
    ComplexArrayDataPublisher(ops::Topic<ComplexArrayData> t)
        : ops::Publisher(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {
        setObjectHelper(new ComplexArrayDataHelper());   

    }
    
    ~ComplexArrayDataPublisher(void)
    {
    }
    
    void write(ComplexArrayData* data)
    {
        ops::Publisher::write(data);

    }
    ops::AckData writeReliable(ComplexArrayData* data, std::string destinationIdentity)
    {
        return ops::Publisher::writeReliable(data, destinationIdentity);

    }
    

};

}


#endif