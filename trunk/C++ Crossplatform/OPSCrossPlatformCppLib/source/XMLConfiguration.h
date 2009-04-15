#ifndef ops_XMLConfiguration_h
#define ops_XMLConfiguration_h

#include <vector>
#include "Topic.h"
#include "Configuration.h"

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