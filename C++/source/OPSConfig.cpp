#include "OPSConfig.h"
#include "DefaultOPSConfigImpl.h"
#include "XMLArchiverIn.h"
#include <fstream>

namespace ops
{
	OPSConfig* OPSConfig::getConfig()
	{
		static OPSConfig* theConfig = NULL;

		if(theConfig == NULL)
		{
			std::ifstream iStream("ops_config.xml");
			XMLArchiverIn archiver(iStream, "root");

			theConfig = (OPSConfig*)archiver.inout(std::string("ops_config"), theConfig);
		}
		return theConfig;

	}


}