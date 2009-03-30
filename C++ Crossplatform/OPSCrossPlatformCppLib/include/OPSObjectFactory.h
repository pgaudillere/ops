#ifndef ops_OPSObjectFactoryH
#define ops_OPSObjectFactoryH

#include "SerializableCompositeFactory.h"
#include "OPSMessage.h"
#include <string>
#include <boost/algorithm/string/split.hpp> 
#include <boost/algorithm/string/Classification.hpp>

namespace ops
{

class OPSMessageFactory : public SerializableFactory
{

public:
	Serializable* create(std::string& type)
    {
        if(type == ("ops.protocol.OPSMessage"))
        {
            return new OPSMessage();
        }
        return NULL;
    }
};

class OPSObjectFactory : public SerializableCompositeFactory
{
    
public:
    /**
     * Create singelton instance of OPSObjectFactory.
     * @return
     */
    static OPSObjectFactory* getInstance()
    {
		static OPSObjectFactory* instance = NULL;
        if(instance == NULL)
        {
            instance = new OPSObjectFactory();
            instance->add(new OPSMessageFactory());
        }
        return instance;
    }
    /**
     * Tries to construct the most specialized version of the given typeString
     */
	Serializable* create(std::string& typeString)
    {
		std::vector<std::string> types;
		boost::algorithm::split(types, typeString, boost::algorithm::is_any_of(" "));

        for(int i = 0; i < types.size(); i++)
        {
			Serializable* serializable = SerializableCompositeFactory::create(types[i]);
            if(serializable != NULL)
            {
                return serializable;
            }
        }

        return NULL;
    }

};
	

}

#endif