#ifndef TopicInterfaceH
#define	TopicInterfaceH

#include "TopicInterfaceData.h"
#include "TimeHelper.h"
#include <stdio.h>

namespace ops
{
class TopicInterface
{

public:
	TopicInterface(TopicInterfaceData iData);
    virtual ~TopicInterface();
    TopicInterfaceData getData();
    void setData(TopicInterfaceData data);


	bool isActive()
	{
		if(TimeHelper::currentTimeMillis() - timeLastFed > timeout)
		{
			return false;
		}
		else
		{
			return true;
        }
	}
	bool dataEquals(const TopicInterfaceData& compData)
	{
		if(compData.port == data.port && compData.address == data.address && compData.topicName == data.topicName)
		{
			return true;
		}
		else
		{
			return false;
        }

	}
	void feedWatchdog()
	{
		timeLastFed = TimeHelper::currentTimeMillis();
	}
	char* getIP()
	{
		return (char*)data.address.c_str();
    }
	int getPort()
	{
        return data.port;
    }

private:
    TopicInterfaceData data;
    static const __int64 timeout = 3000;
	__int64 timeLastFed;


};

}
#endif
