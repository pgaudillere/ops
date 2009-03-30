#ifndef ArchiverInH
#define ArchiverInH

#include "Deserializable.h"

namespace ops
{
//Pure virtual interface.
class ArchiverIn
{
public:
	virtual char getByte(std::string name) = 0;
    virtual int getInt(std::string name) = 0;
    virtual short getShort(std::string name) = 0;
    virtual __int64 getLong(std::string name) = 0;
    virtual float getFloat(std::string name) = 0;
    virtual double getDouble(std::string name) = 0;
    virtual std::string getString(std::string name) = 0;
    virtual void getDeserializable(std::string name, Deserializable* deserializable) = 0;
    virtual int getNrElements(std::string name) = 0;
    virtual void getElement(std::string name, int i, Deserializable* d) = 0;   
};
}

#endif