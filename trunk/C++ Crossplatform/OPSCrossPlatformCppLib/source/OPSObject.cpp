
#include "OPSObject.h"

namespace ops
{
    OPSObject::OPSObject()
    {
        //publisherName = "d";
        key = "k";
        //publicationID = 0;
        //publicationPriority = 0;
		typesString = "";
        
    }
    /*
    std::string OPSObject::getPublisherName()
    {
        return publisherName;
    }*/
    std::string OPSObject::getKey()
    {
         return key;
    }
	const std::string& OPSObject::getTypeString()
	{
		return typesString;
	}
	void OPSObject::setKey(std::string k)
	{
		key = k;
	}

	void OPSObject::serialize(ArchiverInOut* archive)
	{
		archive->inout(std::string("key"), key);
	}

    //int OPSObject::getPublicationID()
    //{
    //    return publicationID;
    //}
    //char OPSObject::getPublicationPriority()
    //{
    //    return publicationPriority;
    //}
    //
    OPSObject::~OPSObject()
    {
    }
}
