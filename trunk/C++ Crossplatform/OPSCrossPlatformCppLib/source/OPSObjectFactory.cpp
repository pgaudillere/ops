#include "OPSObjectFactory.h"

#include "Topic.h"
#include "DefaultOPSConfigImpl.h"
#include "MulticastDomain.h"

#include <boost/algorithm/string/split.hpp> 
#include <boost/algorithm/string/Classification.hpp>

namespace ops
{

class BuiltInFactory : public SerializableFactory
{

public:
	Serializable* create(std::string& type)
    {
        if(type == ("ops.protocol.OPSMessage"))
        {
            return new OPSMessage();
        }
		if(type == ("Topic"))
        {
            return new Topic();
        }
		if(type == ("DefaultOPSConfigImpl"))
        {
            return new DefaultOPSConfigImpl();
        }
		if(type == ("MulticastDomain"))
        {
            return new MulticastDomain();
        }
        return NULL;
    }
};

class OPSObjectFactoryImpl : public OPSObjectFactory
{
    
public:
    
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
	~OPSObjectFactoryImpl()
	{

	}

};


	/**
     * Create singelton instance of OPSObjectFactory.
     * @return
     */
	//static
    OPSObjectFactory* OPSObjectFactory::getInstance()
    {
		static OPSObjectFactory* instance = NULL;
        if(instance == NULL)
        {
            instance = new OPSObjectFactoryImpl();
            instance->add(new BuiltInFactory());
        }
        return instance;
    }
	

}