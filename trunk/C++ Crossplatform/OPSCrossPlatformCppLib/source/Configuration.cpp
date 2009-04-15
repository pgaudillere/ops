#include "Configuration.h"
#include "XMLConfiguration.h"
#include "XMLArchiverIn.h"
#include <fstream>

namespace ops
{

	Configuration* Configuration::getConfiguration()
	{

		static Configuration* theConfiguration = NULL;

		if(theConfiguration == NULL)
		{
			std::ifstream inStream("ops_config.xml");
			if(inStream.is_open())
			{
				XMLArchiverIn archiver(inStream, "ops");
				theConfiguration = (Configuration*)archiver.inout(std::string("config"), theConfiguration);
				if(theConfiguration == NULL)
				{
					theConfiguration = new XMLConfiguration();
				}
			}
			else
			{
				theConfiguration = new XMLConfiguration();
			}
			
		}

		return theConfiguration;

	}

}