#ifndef ops_ArchiverInOutH
#define ops_ArchiverInOutH

#include "Serializable.h"
#include <vector>

namespace ops
{
//Pure virtual interface.
class ArchiverInOut
{
public:

	virtual ~ArchiverInOut(){}

	virtual	bool inout(std::string& name, bool value) = 0;
	virtual char inout(std::string& name, char value) = 0;
    virtual int	inout(std::string& name, int value) = 0;
    virtual short inout(std::string& name, short value) = 0;
    virtual __int64 inout(std::string& name, __int64 value) = 0;
    virtual float inout(std::string& name, float value) = 0;
    virtual double inout(std::string& name, double value) = 0;
	virtual std::string	inout(std::string& name, std::string value) = 0;
    virtual Serializable* inout(std::string& name, Serializable* value) = 0;

	virtual void inout(std::string& name, std::vector<bool>& value) = 0;
	virtual void inout(std::string& name, std::vector<char>& value) = 0;
    virtual void inout(std::string& name, std::vector<int>& value) = 0;
    virtual void inout(std::string& name, std::vector<short>& value) = 0;
    virtual void inout(std::string& name, std::vector<__int64>& value) = 0;
    virtual void inout(std::string& name, std::vector<float>& value) = 0;
    virtual void inout(std::string& name, std::vector<double>& value) = 0;
	virtual void inout(std::string& name, std::vector<std::string>& value) = 0;

	
	template <class SerializableType> void inout(std::string& name, std::vector<SerializableType>& vec)
	{
		int size = beginList(name, vec.size());
		if(vec.size() < size)
		{
			vec.clear();
			vec.reserve(size);
			for(unsigned int i = 0; i < size; i++)
			{
				vec.push_back((SerializableType)inout(name, (Serializable*)NULL));
			}
			
			//vec.resize(size, new SerializableType());
		}
		else
		{
			for(unsigned int i = 0; i < size; i++)
			{
				vec[i] = (SerializableType)inout(name, vec[i]);
			}
		}
		endList(name);
	}

	/*template <class SerializableTypeVector> void in(std::string name&, SerializableTypeVector& vec)
	{
		int size = beginList(name, size);
		vec.clear();
		for(unsigned int i = 0; i < size; i++)
		{
			vec.push_back(*inout((Serializable*)NULL));
		}
	}*/
protected:
	virtual int beginList(std::string& name, int i) = 0;
	virtual void endList(std::string& name) = 0;
 
};
}

#endif