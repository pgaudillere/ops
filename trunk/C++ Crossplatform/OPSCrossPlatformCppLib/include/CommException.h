#ifndef CommException_h
#define CommException_h

#include <string>
namespace ops
{
    namespace exceptions
    {
        class CommException
        {
            
        private:
            std::string message;
        public:
            CommException()
            {
                message = "CommException: empty" ;
            }
            CommException(std::string m)
            {
                message = "CommException: " + m ;
            }
            std::string GetMessage()
            {
                return message;
            }
        };
    }
}
#endif
