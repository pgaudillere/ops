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
#ifndef ops_Domain_h
#define	ops_Domain_h

#include "OPSObject.h"
#include "NoSuchTopicException.h"

namespace ops
{
	class Domain : public OPSObject
	{
	public:
		Domain()
		{
			appendType(std::string("Domain"));
		}

		std::vector<Topic* > getTopics()
		{
			return topics;
		}
		Topic getTopic(std::string name)
		{
			for(unsigned int i = 0 ; i < topics.size(); i++)
			{
				if(topics[i]->getName() == name)
				{
					return *topics[i];
				}
			}
			throw NoSuchTopicException("Topic " + name + " does not exist in ops config file.");
			
		}
		bool existsTopic(std::string name)
		{
			for(unsigned int i = 0 ; i < topics.size(); i++)
			{
				if(topics[i]->getName() == name)
				{
					return true;
				}
			}
			return false;
		}
		std::string getDomainID()
		{
			return domainID;
		}

		void serialize(ArchiverInOut* archiver)
		{
			OPSObject::serialize(archiver);
			archiver->inout(std::string("domainID"), domainID);
			archiver->inout(std::string("topics"), topics);
		}
		virtual ~Domain(){}

	private:
		std::vector<Topic* > topics;
		std::string domainID;
		
	};


}

#endif