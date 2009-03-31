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

#ifndef XMLArchiverInH
#define XMLArchiverInH

#include "ArchiverIn.h"
#include <iostream>
#include <sstream>
#include "xml/xmlParser.h"

namespace ops
{
//Pure virtual interface.
class XMLArchiverIn : ArchiverIn 
{
private:
	std::istream& is;
	xml::XMLNode currentNode;
	std::string xmlString;
	std::string parseString;
	std::stringstream ss;
public:
	XMLArchiverIn(std::istream& is_) : is(is_)
	{
		std::string tmp;
		is >> tmp;
		while(!is.eof())
		{
			xmlString += tmp + " ";
			is >> tmp;			
		}
		currentNode = xml::XMLNode::parseString(xmlString.c_str());
		int i = currentNode.nChildNode();
		
	}

	virtual char getByte(std::string name)
	{
		parseString = std::string(currentNode.getChildNode(name.c_str()).getText(0));
		ss.str(parseString);

		return 0;
	}
    virtual int getInt(std::string name)
	{
		return 1;
	}
    virtual short getShort(std::string name) 
	{
		return 1;
	}
    virtual __int64 getLong(std::string name) 
	{
		return 1;
	}
    virtual float getFloat(std::string name) 
	{
		return 1;
	}
    virtual double getDouble(std::string name)
	{
		return 1;
	}
    virtual std::string getString(std::string name)
	{
		return "";
	}
    virtual void getDeserializable(std::string name, Deserializable* deserializable) 
	{
		currentNode = currentNode.getChildNode(name.c_str());
		deserializable->deserialize(this);
		currentNode = currentNode.getParentNode();
		
	}
    virtual int getNrElements(std::string name) 
	{
		return 1;
	}
    virtual void getElement(std::string name, int i, Deserializable* d) 
	{
		
	}  
};
}

#endif