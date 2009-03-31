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

#ifndef XMLArchiverOutH
#define XMLArchiverOutH

#include "ArchiverOut.h"
#include <iostream>


namespace ops
{
//Pure virtual interface.
	class XMLArchiverOut : public ArchiverOut
{
	std::ostream& os;
	int currentTabDepth;
	const static int tabSize = 3; 
private:
	std::string tab()
	{
		std::string ret("");
		for(int i = 0; i < currentTabDepth; i++)
			ret += ("   ");
		return ret;
	}
public:
	XMLArchiverOut(std::ostream& os_): os(os_),currentTabDepth(0)
	{
		
	}

	virtual void put(std::string& name, Serializable* v)
	{
		
		os << tab() << "<" << name << ">"  << "\n";
		currentTabDepth++;
		v->serialize(this);
		currentTabDepth--;
		os << tab() << "</" << name << ">"  << "\n";
		
	}
    virtual void put(std::string& name, std::string v)
	{
		os << tab() << "<" << name << ">" << v << "</" << name << ">\n";
	}
    virtual void put(std::string& name, char v) 
	{
		os << tab() << "<" << name << ">" << v << "</" << name << ">\n";
	}
    virtual void put(std::string& name, double v)
	{
		os << tab() << "<" << name << ">" << v << "</" << name << ">\n";
	}
    virtual void put(std::string& name, float v)
	{
		os << tab() << "<" << name << ">" << v << "</" << name << ">\n";
	}
    virtual void put(std::string& name, int v) 
	{
		os << tab() << "<" << name << ">" << v << "</" << name << ">\n";
	}
    virtual void put(std::string& name, long v)
	{
		os << tab() << "<" << name << ">" << v << "</" << name << ">\n";
	}
    virtual void put(std::string& name, short v)
	{
		os << tab() << "<" << name << ">" << v << "</" << name << ">\n";
	}
	virtual void putStartList(std::string& name, int size)
	{
		os << tab() << "<" << name << ">"  << "\n";
		currentTabDepth++;
	}
	virtual void putElement(std::string& listName, Serializable* v)
	{

	}
	virtual void putEndList(std::string& listName)
	{
		currentTabDepth--;
		os << tab() << "</" << listName << ">"  << "\n";
	}
	//template <class ElementType>
	//virtual void put(std::string name, std::vector<ElementType> collection) = 0;
};

}
#endif