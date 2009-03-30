#ifndef ops_SerializableFactoryH
#define ops_SerializableFactoryH

#include "Serializable.h"
#include <string>

namespace ops
{
class SerializableFactory
{
public:
	~SerializableFactory(){}
	virtual Serializable* create(std::string& type) = 0;
};
}

#endif