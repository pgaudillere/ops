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
#ifndef ops_MulticastDomain_h
#define	ops_MulticastDomain_h

#include "Domain.h"

namespace ops
{
	class MulticastDomain : public Domain
	{
		std::string domainAddress;
	public:
		MulticastDomain()
		{
			appendType(std::string("MulticastDomain"));
		}
		virtual std::vector<Topic* > getTopics()
		{
			for(unsigned int i = 0 ; i < topics.size(); i++)
			{
				if(topics[i]->getDomainAddress() == "")
				{
					topics[i]->setDomainAddress(domainAddress);
				}
			}
			return topics;
		}
		virtual Topic getTopic(std::string name)
		{
			for(unsigned int i = 0 ; i < topics.size(); i++)
			{
				if(topics[i]->getDomainAddress() == "")
				{
					topics[i]->setDomainAddress(domainAddress);
				}
				if(topics[i]->getName() == name)
				{
					return *topics[i];
				}
			}
			throw NoSuchTopicException("Topic " + name + " does not exist in ops config file.");
			
		}
		
		void serialize(ArchiverInOut* archiver)
		{
			Domain::serialize(archiver);
			archiver->inout(std::string("domainAddress"), domainAddress);
		}
		
		virtual ~MulticastDomain(){}

		
	};


}

#endif