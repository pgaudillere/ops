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

