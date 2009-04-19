#ifndef OPSTestTopicConfigH
#define OPSTestTopicConfigH

#include "ops.h"
#include "ComplexArrayData.h"
#include "ByteArrayData.h"
#include "ByteArrayData.h"
namespace opstest 
{
class OPSTestTopicConfig
{
	private:
	std::string domainAddress;
	public:
	OPSTestTopicConfig(std::string domainAddress)
	{
		this->domainAddress = domainAddress;
	}
	ops::Topic<ComplexArrayData> getComplexArrayTopic()
	{
		return ops::Topic<ComplexArrayData>("ComplexArrayTopic", 0, "ComplexArrayData", this->domainAddress);
	}
	ops::Topic<ByteArrayData> getByteArrayTopic()
	{
		return ops::Topic<ByteArrayData>("ByteArrayTopic", 0, "ByteArrayData", this->domainAddress);
	}
	ops::Topic<ByteArrayData> getByteArray2Topic()
	{
		return ops::Topic<ByteArrayData>("ByteArray2Topic", 0, "ByteArrayData", this->domainAddress);
	}
};
}
#endif
