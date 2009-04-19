//Auto generated OPS-code. DO NOT MODIFY!
#ifndef opstest_OPSTestOPSFactoryH
#define opstest_OPSTestOPSFactoryH

#include <string>

#include "KeyFilterQoSPolicy.h"
#include "OPSFactory.h"

#include "opstest/OPSTestTopicConfig.h"
#include "ComplexArrayDataSubscriber.h"
#include "ComplexArrayDataPublisher.h"
#include "ByteArrayDataSubscriber.h"
#include "ByteArrayDataPublisher.h"
#include "ByteArrayDataSubscriber.h"
#include "ByteArrayDataPublisher.h"


namespace opstest
{
    ///Factory for creating OPSTest IDL-Project specific Publishers and Subscribers
    class OPSTestOPSFactory : public ops::OPSFactory
    {
        std::string domainAddress;
        public:

        ///Default empty constructor
        OPSTestOPSFactory()
        {

        }

        ///Constructor taking and setting domainAddress of this factory.
        OPSTestOPSFactory(std::string domainAddr)
        {
            this->domainAddress = domainAddr;
        }

        ///Sets the domainAddress of this factory.
        void setDomainAddress(std::string domainAddr)
        {
            this->domainAddress = domainAddr;
        }

        ///Creates a Subscriber* for the specified topicName, returns NULL if no Subscriber exists for topicName.
        ops::Subscriber* createSubscriber(std::string topicName, std::string keyFilter = "", int deadlineQoS = 999999999, int timebasedQoS = 0)
        {
            opstest::OPSTestTopicConfig topicConfig(domainAddress);

			ops::Subscriber* sub = NULL;
			if(topicName == "ComplexArrayTopic")
			{
				sub = new ComplexArrayDataSubscriber(topicConfig.getComplexArrayTopic());
			}
			if(topicName == "ByteArrayTopic")
			{
				sub = new ByteArrayDataSubscriber(topicConfig.getByteArrayTopic());
			}
			if(topicName == "ByteArray2Topic")
			{
				sub = new ByteArrayDataSubscriber(topicConfig.getByteArray2Topic());
			}


            if(sub != NULL)
            {
                sub->setDeadlineQoS(deadlineQoS);
                sub->setTimeBasedFilterQoS(timebasedQoS);
                if(keyFilter != "")
                {
                    sub->addFilterQoSPolicy(new ops::KeyFilterQoSPolicy(keyFilter));
                }
            }
            return sub;
        }

        ///Creates a Publisher* for the specified topicName, returns NULL if no Publisher exists for topicName.
        ops::Publisher* createPublisher(std::string topicName, std::string publisherName = "")
        {
            opstest::OPSTestTopicConfig topicConfig(domainAddress);

			ops::Publisher* pub = NULL;
			if(topicName == "ComplexArrayTopic")
			{
				pub = new ComplexArrayDataPublisher(topicConfig.getComplexArrayTopic());
			}
			if(topicName == "ByteArrayTopic")
			{
				pub = new ByteArrayDataPublisher(topicConfig.getByteArrayTopic());
			}
			if(topicName == "ByteArray2Topic")
			{
				pub = new ByteArrayDataPublisher(topicConfig.getByteArray2Topic());
			}


            if(pub != NULL)
            {
                pub->setName(publisherName);
            }
            return pub;
        }

    };

}



#endif