#ifndef ops_Configuration_h
#define ops_Configuration_h

#include <vector>
#include "Topic.h"

namespace ops
{
	class Configuration : public OPSObject
	{
	public:
		static Configuration* getConfiguration();
		virtual std::vector<Topic<>* > getTopics() = 0;

		///throws ops::NoSuchTopicException.
		virtual Topic<> getTopic(std::string name) = 0;

		virtual bool existsTopic(std::string name) = 0;

	};
}

#endif