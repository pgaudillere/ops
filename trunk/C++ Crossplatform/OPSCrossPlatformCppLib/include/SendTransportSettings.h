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

#ifndef SendTransportSettingsH
#define SendTransportSettingsH

#include <vector>
#include "ArchiverOut.h"
namespace ops
{


class IPInterfaceSetting : public Serializable
{
public:
	std::string ip;
	int port;

	std::vector<int> ints;

	IPInterfaceSetting()
	{
		ints.push_back(1);
		ints.push_back(2);
		ints.push_back(3);
	}


	void serialize(ArchiverOut* archiver)
	{
		archiver->put(std::string("ip"), ip);
		archiver->put(std::string("port"), port);

		archiver->putStartList(std::string("ints"), 3);
			archiver->put(std::string("element"), ints[0]);
			archiver->put(std::string("element"), ints[1]);
			archiver->put(std::string("element"), ints[2]);
		archiver->putEndList(std::string("ints"));
	}
};

class SendTransportSettings : public Serializable
{
    public:

		SendTransportSettings(){}

		IPInterfaceSetting localInterface;
		IPInterfaceSetting domainInterface;


		void serialize(ArchiverOut* archiver)
		{
			archiver->put(std::string("localInterface"), &localInterface);
			archiver->put(std::string("domainInterface"), &domainInterface);

		}


};
}
#endif

