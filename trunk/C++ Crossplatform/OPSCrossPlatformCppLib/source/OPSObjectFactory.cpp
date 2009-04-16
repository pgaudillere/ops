#include "OPSObjectFactory.h"
#include "OPSObjectFactoryImpl.h"

namespace ops
{

	/**
     * Create singelton instance of OPSObjectFactory.
     * @return
     */
	//static
    OPSObjectFactory* OPSObjectFactory::getInstance()
    {
		static OPSObjectFactory* instance = NULL;
        if(instance == NULL)
        {
            instance = new OPSObjectFactoryImpl();
            instance->add(new BuiltInFactory());
        }
        return instance;
    }
	

}