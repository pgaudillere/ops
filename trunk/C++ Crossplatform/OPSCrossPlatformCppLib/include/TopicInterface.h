/**
* 
* Copyright (C) 2006-2009 Anton Gravestam.
*
* This notice apply to all source files, *.cpp, *.h, *.java, and *.cs in this directory 
* and all its subdirectories if nothing else is explicitly stated within the source file itself.
*
* This file is part of OPS (Open Publish Subscribe).
*
* OPS (Open Publish Subscribe) is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* OPS (Open Publish Subscribe) is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with OPS (Open Publish Subscribe).  If not, see <http://www.gnu.org/licenses/>.
*/

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
