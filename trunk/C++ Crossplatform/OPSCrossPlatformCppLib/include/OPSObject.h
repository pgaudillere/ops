#ifndef ops_OPSObject_h
#define ops_OPSObject_h

#include <string>
#include "Serializable.h"
#include "ArchiverInOut.h"


namespace ops
{
    ///Interface that tags an object as being an OPSObject.
    ///
    //TODO: Put functionalities common for all OPSObjects here, e.g. ID's sizes etc...
	class OPSObject : public Serializable
    {
        
        friend class ByteBuffer;
        //friend class OPSObjectHelper;
        friend class Publisher;
        
    protected:
        //Should only be set by the Publisher at publication time and by ByteBuffer at deserialization time.
        //std::string publisherName;
        std::string key;
        //int publicationID;
        //char publicationPriority;
        std::string typesString;

		void appendType(std::string& type)
		{
			typesString = type + " " + typesString;
		}
        
       
    public:
        //std::string getPublisherName();
        std::string getKey();
		const std::string& getTypeString();
		void setKey(std::string k);
        //int getPublicationID();
        //char getPublicationPriority();
		virtual void serialize(ArchiverInOut* archive);
        
    public:
        OPSObject();
        virtual ~OPSObject();
        
    };
}

#endif