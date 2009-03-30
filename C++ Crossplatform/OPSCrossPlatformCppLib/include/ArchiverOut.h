#ifndef ArchiverOutH
#define ArchiverOutH

#include "Serializable.h"

namespace ops
{
//Pure virtual interface.
class ArchiverOut
{
public:
	virtual void put(std::string& name, Serializable* v) = 0;
    virtual void put(std::string& name, std::string v) = 0;
    virtual void put(std::string& name, char v) = 0;
    virtual void put(std::string& name, double v) = 0;
    virtual void put(std::string& name, float v) = 0;
    virtual void put(std::string& name, int v) = 0;
    virtual void put(std::string& name, long v) = 0;
    virtual void put(std::string& name, short v) = 0;
	virtual void putStartList(std::string& name, int size) = 0;
	virtual void putElement(std::string& listName, Serializable* v) = 0;
	virtual void putEndList(std::string& listName) = 0;
	//template <class ElementType>
	//virtual void put(std::string name, std::vector<ElementType> collection) = 0;
};

}
#endif