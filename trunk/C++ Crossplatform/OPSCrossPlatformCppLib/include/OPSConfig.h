#ifndef ops_OPSConfig_h
#define ops_OPSConfig_h

#include <vector>
#include "Topic.h"

namespace ops
{
	class OPSConfig : public OPSObject
	{
	public:
		static OPSConfig* getConfig();

		private:
		std::vector<Domain* > domains;
		/*virtual std::vector<Topic* > getTopics() = 0;

		///throws ops::NoSuchTopicException.
		virtual Topic getTopic(std::string name) = 0;

		virtual bool existsTopic(std::string name) = 0;*/

	};
}

#endif