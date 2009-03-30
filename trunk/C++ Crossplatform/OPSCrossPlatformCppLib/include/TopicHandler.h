#ifndef ops_TopicHandler_h
#define ops_TopicHandler_h

#include <string>
#include <map>
#include "Topic.h"
#include "ByteBuffer.h"
#include "OPSArchiverIn.h"
#include "MulticastReceiver.h"
#include "OPSMessage.h"
#include "Notifier.h"
#include "Listener.h"



namespace ops
{
	class TopicHandler : public Notifier<OPSMessage*>, Listener<char*>
	{
	public:
		///By Singelton, one TopicHandler per Topic (Name)
		static TopicHandler* getTopicHandler(Topic<> top)
		{
			if(instances.find(top.GetName()) == instances.end())
			{
				instances[top.GetName()] = new TopicHandler(top);
			}
			return instances[top.GetName()];
		}
		///Destructor
		virtual ~TopicHandler()
		{

		}

	protected:
		///Override from Listener
		///Called whenever the receiver has new data.
		void onNewEvent(Notifier<char*>* sender, char* bytes)
		{
			//Deserialize data
			ByteBuffer buf(bytes);

			//Check protocol
			if(buf.checkProtocol())
			{

				//Read of message ID and fragmentation info, this is ignored so far.
				std::string messageID = buf.ReadString();
				int nrOfFragments = buf.ReadInt();
				int currentFragment = buf.ReadInt();
				
				//Read of the actual OPSMessage
				OPSArchiverIn archiver(&buf);

				OPSMessage* message = NULL;
				message = dynamic_cast<OPSMessage*>(archiver.inout(std::string("message"), message));
				if(message)
				{
					//Send it to Subscribers
					notifyNewEvent(message);
				}
				else
				{
					//Inform participant that invalid data is on the network.
				}
			}
			else
			{
				//Inform participant that invalid data is on the network.
			}
			
		}

	private:
		///By Singelton, one TopicHandler per Topic (Name)
		static std::map<std::string, TopicHandler*> instances;
		
		///Constructor is private, use static getTopicHandler(Topic)
		TopicHandler(Topic<> top) :
			receiver(top.GetDomainAddress(), top.GetPort())
		{
			receiver.addListener(this);
			
		}

		///The receiver used for this topic. 
		///TODO: make independent of implemntation through factory. Transport::getTransport(Topic t), see java implementation.
		MulticastReceiver receiver;

		///Preallocated bytebuffer for receiving data
		char bytes[Participant::MESSAGE_MAX_SIZE];

	};

	
}
#endif