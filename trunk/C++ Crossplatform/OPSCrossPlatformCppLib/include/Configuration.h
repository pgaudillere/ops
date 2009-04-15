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

	};
}

#endif