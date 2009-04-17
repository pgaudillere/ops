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



namespace ops
{   /*template<class DataType = OPSObject>*/
	class Topic : public OPSObject
    {
		friend class Domain;
    
	public:
        Topic(std::string namee, int portt, std::string typeIDd, std::string domainAddresss);
		Topic();

        void setParticipantID(std::string partID);
		std::string getParticipantID();
		void setDomainID(std::string domID);
		std::string getDomainID();

        std::string getName();
        std::string getTypeID();
        std::string getDomainAddress();
		void setDomainAddress(std::string domainAddr);
		int getSampleMaxSize();
		void setSampleMaxSize(int size);
        int getPort();
		void serialize(ArchiverInOut* archiver);

	private:
        std::string name;

		int port;
		std::string typeID;
        std::string domainAddress;
		std::string localInterface;
		std::string participantID;
		std::string domainID;
		bool reliable;
		int sampleMaxSize;
		__int64 deadline;
		__int64 minSeparation;
        

		
        
        
    };
}
#endif
