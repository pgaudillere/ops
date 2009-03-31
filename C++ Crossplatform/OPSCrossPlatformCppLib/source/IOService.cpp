#include "IOService.h"

#include "BoostIOServiceImpl.h"


namespace ops
{
	
	//static create method
	IOService* IOService::getInstance()
	{
		static IOService* theIOService = NULL;
		
		if(theIOService == NULL)
		{
			theIOService = new BoostIOServiceImpl();
		}
		return theIOService;

	}

}