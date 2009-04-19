
#include "Topic.h"

namespace ops
{
    
    
    Topic::Topic(std::string namee, int portt, std::string typeIDd, std::string domainAddresss)
    :name(namee), port(portt), typeID(typeIDd), domainAddress(domainAddresss)
    {
        
    }
    
    
    
    Topic::~Topic()
    {
    }
}
