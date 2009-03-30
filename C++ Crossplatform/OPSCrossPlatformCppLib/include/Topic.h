#ifndef topic_h
#define topic_h

#include <string>
#include "OPSObject.h"

namespace ops
{   template<class DataType = OPSObject>
    class Topic
    {
    private:
        std::string name;
        
        
    public:
		int port;
		std::string typeID;
        std::string domainAddress;
		std::string localInterface;
        
        Topic(std::string namee, int portt, std::string typeIDd, std::string domainAddresss)
        :name(namee), port(portt), typeID(typeIDd), domainAddress(domainAddresss)
        {

        }
        
        std::string GetName()
        {
            return name;
        }
        std::string GetTypeID()
        {
            return typeID;
        }
        std::string GetDomainAddress()
        {
            return domainAddress;
        }
        int GetPort()
        {
            return port;
        }
        
        
    };
}
#endif
