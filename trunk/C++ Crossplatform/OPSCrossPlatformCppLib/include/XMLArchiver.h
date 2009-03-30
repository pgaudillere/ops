#ifndef XMLArchiverH
#define XMLArchiverH

#include <string>

namespace ops 
{
	template <class Type>
	class nvp
	{
	public:
		std::string name;
		Type value;
		nvp(std::string name_, Type v) : name(name_), value(v)
		{
			
		}		
	};
	template <class Serializable>
	class nop
	{
	public:
		std::string name;
		Serializable value;
		nop(std::string name_, Serializable v) : name(name_), value(v)
		{		
		}
		template <class Archiver>
		void serialize(Archiver& archive)
		{
			archive << std::cout << "<" << n.name << ">"; 
			value.serialize(archive);			
		}
	};
	class XMLArchiver 
	{
	public:
		void operator<<(int v)
		{
			std::cout << v;
		}
		void operator<<(char v)
		{
			std::cout << v;
		}
		void operator<<(short v)
		{
			std::cout  << v;
		}
		void operator<<(__int64 v)
		{
			std::cout << v;
		}
		void operator<<(float v)
		{
			std::cout << v;
		}
		void operator<<(double v)
		{
			std::cout << v;
		}
				
		
		void operator<<(nvp& n)
		{
			std::cout << "<" << n.name << ">" << n.value << "</" << n.name << ">\n";		
		}
		template <class Nop>
		void operator<<(Nop& n)
		{
			std::cout << "<" << n.name << ">";
			n.serialize(this);
		}

	};


}
#endif