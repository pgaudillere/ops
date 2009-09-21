#ifndef ops_BasicError_h
#define ops_BasicError_h

#include <string>
#include "Error.h"

namespace ops
{
	///Basic implementaion of an error for OPS.
	class BasicError : public Error
	{
	public:
		static const int ERROR_CODE = 1;
		BasicError(std::string mess)
		{
			message = mess;
		}
		virtual int getErrorCode()
		{
			return ERROR_CODE;
		}
		virtual std::string getMessage()
		{
			return message;
		}
		virtual ~BasicError(){}
	private:
		std::string message;
	};


}
#endif