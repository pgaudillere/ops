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

#ifndef ops_OPSObjectFactoryH
#define ops_OPSObjectFactoryH

#include "SerializableCompositeFactory.h"
#include "OPSMessage.h"
#include <string>
#include <boost/algorithm/string/split.hpp> 
#include <boost/algorithm/string/Classification.hpp>

namespace ops
{

class OPSMessageFactory : public SerializableFactory
{

public:
	Serializable* create(std::string& type)
    {
        if(type == ("ops.protocol.OPSMessage"))
        {
            return new OPSMessage();
        }
        return NULL;
    }
};

class OPSObjectFactory : public SerializableCompositeFactory
{
    
public:
    /**
     * Create singelton instance of OPSObjectFactory.
     * @return
     */
    static OPSObjectFactory* getInstance()
    {
		static OPSObjectFactory* instance = NULL;
        if(instance == NULL)
        {
            instance = new OPSObjectFactory();
            instance->add(new OPSMessageFactory());
        }
        return instance;
    }
    /**
     * Tries to construct the most specialized version of the given typeString
     */
	Serializable* create(std::string& typeString)
    {
		std::vector<std::string> types;
		boost::algorithm::split(types, typeString, boost::algorithm::is_any_of(" "));

        for(int i = 0; i < types.size(); i++)
        {
			Serializable* serializable = SerializableCompositeFactory::create(types[i]);
            if(serializable != NULL)
            {
                return serializable;
            }
        }

        return NULL;
    }

};
	

}

#endif