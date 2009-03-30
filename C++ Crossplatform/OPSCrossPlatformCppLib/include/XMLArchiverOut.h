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