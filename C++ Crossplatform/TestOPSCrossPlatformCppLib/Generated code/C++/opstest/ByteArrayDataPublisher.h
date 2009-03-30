#ifndef opstestByteArrayDataPublisher_h
#define opstestByteArrayDataPublisher_h

#include "Publisher.h"
#include "Topic.h"
#include "OPSObject.h"
#include "ByteArrayData.h"
#include "ByteArrayDataHelper.h"
#include <string>

namespace opstest
{


class ByteArrayDataPublisher : public ops::Publisher 
{
    
public:
    ByteArrayDataPublisher(ops::Topic<ByteArrayData> t)
        : ops::Publisher(ops::Topic<>(t.GetName(), t.GetPort(), t.GetTypeID(), t.GetDomainAddress()))
    {
        setObjectHelper(new ByteArrayDataHelper());   

    }
    
    ~ByteArrayDataPublisher(void)
    {
    }
    
    void write(ByteArrayData* data)
    {
        ops::Publisher::write(data);

    }
    
    

};

}


#endif