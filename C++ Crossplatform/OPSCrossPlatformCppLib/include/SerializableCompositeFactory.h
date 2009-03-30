#ifndef ops_SerializableCompositeFactoryH
#define ops_SerializableCompositeFactoryH

#include "SerializableFactory.h"
#include <vector>

namespace ops
{

class SerializableCompositeFactory : SerializableFactory
{

	std::vector<SerializableFactory*> childFactories;

public:
	bool remove(SerializableFactory* o)
    {
		std::vector<SerializableFactory*>::iterator it = childFactories.begin();
		for(int i = 0; i < childFactories.size(); i++ )
		{
			if(childFactories[i] == o)
			{
				it += i;
				childFactories.erase(it);
				return true;
			}
		}
		return false;
    }

    void add(SerializableFactory* o)
    {
		return childFactories.push_back(o);
    }

	Serializable* create(std::string& type)
    {
        Serializable* obj = NULL;

		for(int i = 0; i < childFactories.size(); i++ )
		{
			obj = childFactories[i]->create(type);
			if(obj != NULL)
			{
				return obj;
			}
		}
		return obj;
    }
};

}

#endif