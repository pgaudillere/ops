#include "TopicInterface.h"

namespace ops
{
	TopicInterface::TopicInterface(TopicInterfaceData iData) : data(iData)
    {
    	feedWatchdog();

    }
    TopicInterface::~TopicInterface()
    {

    }
    TopicInterfaceData TopicInterface::getData()
    {
    	return data;
    }
    void TopicInterface::setData(TopicInterfaceData data)
    {
     	this->data = data;
    }


}