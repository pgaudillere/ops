#ifndef ops_DefaultOPSConfigImpl_h
#define ops_DefaultOPSConfigImpl_h

#include <vector>
#include "Topic.h"
#include "OPSConfig.h"
#include "NoSuchTopicException.h"

namespace ops
{
	class DefaultOPSConfigImpl : public OPSConfig 
	{

	public:
		DefaultOPSConfigImpl()
		{
			appendType(std::string("DefaultOPSConfigImpl"));
		}
		
		std::vector<Topic* > getTopics()
		{
			return topics;
		}
		Topic getTopic(std::string name)
		{
			for(unsigned int i = 0 ; i < topics.size(); i++)
			{
				if(topics[i]->getName() == name)
				{
					return *topics[i];
				}
			}
			throw NoSuchTopicException("Topic " + name + " does not exist in ops config file.");
			
		}
		bool existsTopic(std::string name)
		{
			for(unsigned int i = 0 ; i < topics.size(); i++)
			{
				if(topics[i]->getName() == name)
				{
					return true;
				}
			}
			return false;
		}

		void serialize(ArchiverInOut* archiver)
		{
			OPSObject::serialize(archiver);
			archiver->inout(std::string("topics"), topics);
		}

		~DefaultOPSConfigImpl()
		{
			for(unsigned int i = 0; i < topics.size(); i++)
			{
				if(topics[i]) delete topics[i];
			}
		}

	private:
		std::vector<Topic* > topics;

	};
}

#endif