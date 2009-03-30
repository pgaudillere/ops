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