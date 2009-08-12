
#include "Topic.h"
#include "OPSConstants.h"
#include "Participant.h"
#include "ConfigException.h"

namespace ops
{
	Topic::Topic(std::string namee, int portt, std::string typeIDd, std::string domainAddresss)
		: name(namee), 
		port(portt), 
		typeID(typeIDd), 
		domainAddress(domainAddresss),
		participantID("DEFAULT_PARTICIPANT"),
		reliable(false),
		sampleMaxSize(OPSConstants::PACKET_MAX_SIZE),
		deadline(OPSConstants::MAX_DEADLINE_TIMEOUT),
		minSeparation(0)
	{
		appendType(std::string("Topic"));

	}
	Topic::Topic()
		: name(""), 
		port(0), 
		typeID(""), 
		domainAddress(""),
		participantID("DEFAULT_PARTICIPANT"),
		reliable(false),
		sampleMaxSize(OPSConstants::PACKET_MAX_SIZE),
		deadline(OPSConstants::MAX_DEADLINE_TIMEOUT),
		minSeparation(0)
	{
		appendType(std::string("Topic"));

	}
	void Topic::setParticipantID(std::string partID)
	{
		participantID = partID;
	}

	std::string Topic::getParticipantID()
	{
		return participantID;
	}

	void Topic::setDomainID(std::string domID)
	{
		domainID = domID;
	}
	std::string Topic::getDomainID()
	{
		return domainID;
	}
	std::string Topic::getName()
	{
		return name;
	}
	std::string Topic::getTypeID()
	{
		return typeID;
	}
	void Topic::setDomainAddress(std::string domainAddr)
	{
		domainAddress = domainAddr;
	}
	std::string Topic::getDomainAddress()
	{
		return domainAddress;
	}
	int Topic::getSampleMaxSize()
	{
		return sampleMaxSize;
	}
	void Topic::setSampleMaxSize(int size)
	{
		if(size < OPSConstants::PACKET_MAX_SIZE)
		{
			sampleMaxSize = OPSConstants::PACKET_MAX_SIZE;
		}
		else
		{
			sampleMaxSize = size;
		}
	}
	int Topic::getPort()
	{
		return port;
	}
	std::string Topic::getTransport()
	{
		return transport;
	}

	void Topic::serialize(ArchiverInOut* archiver)
	{
		OPSObject::serialize(archiver);
		archiver->inout(std::string("name"), name);
		archiver->inout(std::string("dataType"), typeID);
		archiver->inout(std::string("port"), port);		
		archiver->inout(std::string("address"), domainAddress);

		//Limit this value 
		int tSampleMaxSize = getSampleMaxSize();
		archiver->inout(std::string("sampleMaxSize"), tSampleMaxSize);
		setSampleMaxSize(tSampleMaxSize);

		archiver->inout(std::string("transport"), transport);
		if(transport == "")
		{
			transport = TRANSPORT_MC;
		}
		else if (transport != TRANSPORT_TCP)
		{
			throw ops::ConfigException("Transport in topic must be either 'multicast', 'TCP' or left blank( = multicast).");
		}
	}

	std::string Topic::TRANSPORT_MC = "multicast";
	std::string Topic::TRANSPORT_TCP = "tcp";
	std::string Topic::TRANSPORT_UDP = "udp";


}
