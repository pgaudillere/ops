/**
* 
* Copyright (C) 2006-2009 Anton Gravestam.
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

#ifndef ops_topic_h
#define ops_topic_h

#include <string>
#include "OPSObject.h"
#include "OPSConstants.h"


namespace ops
{   /*template<class DataType = OPSObject>*/
	class Topic : public OPSObject
    {
    private:
        std::string name;
        
        
    public:
		int port;
		std::string typeID;
        std::string domainAddress;
		std::string localInterface;
		bool reliable;
		int sampleMaxSize;
		__int64 deadline;
		__int64 minSeparation;
        
        Topic(std::string namee, int portt, std::string typeIDd, std::string domainAddresss)
			: name(namee), 
			  port(portt), 
			  typeID(typeIDd), 
			  domainAddress(domainAddresss),
			  reliable(false),
			  sampleMaxSize(OPSConstants::PACKET_MAX_SIZE),
			  deadline(0x0fffffffffffffff),
			  minSeparation(0)
        {
			appendType(std::string("Topic"));

        }
		Topic()
			: name(""), 
			  port(0), 
			  typeID(""), 
			  domainAddress(""),
			  reliable(false),
			  sampleMaxSize(OPSConstants::PACKET_MAX_SIZE),
			  deadline(0x0fffffffffffffff),
			  minSeparation(0)
        {
			appendType(std::string("Topic"));

        }

        
        std::string getName()
        {
            return name;
        }
        std::string getTypeID()
        {
            return typeID;
        }
        std::string getDomainAddress()
        {
            return domainAddress;
        }
		int getSampleMaxSize()
        {
            return sampleMaxSize;
        }
		void setSampleMaxSize(int size)
        {
			if(size < OPSConstants::PACKET_MAX_SIZE)
			{
				sampleMaxSize = OPSConstants::PACKET_MAX_SIZE;
			}
			else
			{
				sampleMaxSize = size;
			}
        }
        int getPort()
        {
            return port;
        }
	private:
		void serialize(ArchiverInOut* archiver)
		{
			OPSObject::serialize(archiver);
			archiver->inout(std::string("name"), name);
			archiver->inout(std::string("dataType"), typeID);
			archiver->inout(std::string("port"), port);		
			archiver->inout(std::string("address"), domainAddress);
			
			//Limit this value 
			int tSampleMaxSize = getSampleMaxSize();
			archiver->inout(std::string("sampleMaxSize"), tSampleMaxSize);
			setSampleMaxSize(tSampleMaxSize);
		}
        
        
    };
}
#endif
