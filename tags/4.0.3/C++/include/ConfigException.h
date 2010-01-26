#ifndef ops_ConfigException_h
#define ops_ConfigException_h

#include <exception> 

namespace ops
{
	class ConfigException : std::exception
	{
	public:
		ConfigException(std::string mess) 
			: message(mess)
		{

		}
		const char* what()
		{
			return message.c_str();
		}
	private:
		std::string message;

	};

}
#endif