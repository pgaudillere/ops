#ifndef ops_XMLConfiguration_h
#define ops_XMLConfiguration_h

#include <vector>
#include "Topic.h"
#include "Configuration.h"
#include "NoSuchTopicException.h"

namespace ops
{
	class XMLConfiguration : public Configuration 
	{

	public:
		XMLConfiguration()
		{
			appendType(std::string("XMLConfiguration"));

		}
		std::vector<Topic<>* > getTopics()
		{
			return topics;
		}
		Topic<> getTopic(std::string name)
		{
			for(unsigned int i = 0 ; i < topics.size(); i++)
			{
				if(topics[i]->GetName() == name)
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
				if(topics[i]->GetName() == name)
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

	private:
		std::vector<Topic<>* > topics;

	};
}

#endif