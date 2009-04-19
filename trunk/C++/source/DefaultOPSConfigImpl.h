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
		
		void serialize(ArchiverInOut* archiver)
		{
			OPSConfig::serialize(archiver);
		}
	

	};
}

#endif