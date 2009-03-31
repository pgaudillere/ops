/**
* 
* Copyright (C) 2006-2009 Anton Gravestam.
*
* This notice apply to all source files, *.cpp, *.h, *.java, and *.cs in this directory 
* and all its subdirectories if nothing else is explicitly stated within the source file itself.
*
* This file is part of OPS (Open Publish Subscribe).
*
* OPS (Open Publish Subscribe) is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* OPS (Open Publish Subscribe) is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with OPS (Open Publish Subscribe).  If not, see <http://www.gnu.org/licenses/>.
*/

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