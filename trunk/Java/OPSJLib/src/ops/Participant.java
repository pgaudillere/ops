
package ops;

import configlib.SerializableFactory;
import configlib.exception.FormatException;
import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;
import ops.archiver.OPSObjectFactory;

/**
 *
 * @author Anton Gravestam
 */
public class Participant 
{
    public static HashMap<String, Participant> instances = new HashMap<String, Participant>();
	public static Participant getInstance(String domainID)
    {
        return getInstance(domainID, "DEFAULT_PARTICIPANT");

    }
	public static Participant getInstance(String domainID, String participantID)
    {
        return getInstance(domainID, participantID, null);
    }

    public static Participant getInstance(String domainID, String participantID, File file)
    {
        if(!instances.containsKey(participantID))
		{
			Participant newInst = new Participant(domainID, participantID, file);
			Domain tDomain = newInst.config.getDomain(domainID);

			if(tDomain != null)
			{
				instances.put(participantID, newInst);
			}
			else
			{
				return null;
			}
		}
		return instances.get(participantID);
    }
    private String domainID;
    private String participantID;


    private OPSConfig config;
    private HashMap<String, TopicHandler> topicHandlerInstances = new HashMap<String, TopicHandler>();

    private Participant(String domainID, String participantID, File configFile)
    {
        this.domainID = domainID;
        this.participantID = participantID;
        try
        {
            if(configFile == null)
            {
                config = OPSConfig.getConfig();
            }
            else
            {
                config = OPSConfig.getConfig(configFile);
            }
        }
        catch (IOException ex)
        {
            config = null;
        }
        catch (FormatException ex)
        {
            config = null;
        }
        
    }

    public void addTypeSupport(SerializableFactory typeSupport)
	{
		OPSObjectFactory.getInstance().add(typeSupport);
	}

	public Topic createTopic(String name)
	{
		Topic topic = config.getDomain(domainID).getTopic(name);
		topic.setParticipantID(participantID);
		topic.setDomainID(domainID);

		return topic;
	}

	///By Singelton, one TopicHandler per Topic (Name)
	//This instance map should be owned by Participant.
	TopicHandler getTopicHandler(Topic top)
	{
		if(!topicHandlerInstances.containsKey(top.getName()))
		{
			topicHandlerInstances.put(top.getName(), new TopicHandler(top, this));

		}
		return topicHandlerInstances.get(top.getName());
	}

    public OPSConfig getConfig()
    {
        return config;
    }

//     public final Event multicastNotAvailableEvent = new Event();
//    public final Event networkLostEvent = new Event();
//    public final Event networkRestoredEvent = new Event();
//    public final Event badHeaderReceivedEvent = new Event();
//    public final Event unhandledExceptionEvent = new Event();
//
//    protected void handleMulticastNotAvailableError()
//    {
//        networkLostEvent.fireEvent("Multicast Error, possible loss of IP address.");
//    }
//    protected void handleNoRouteToUDPDestination(String destination)
//    {
//        networkLostEvent.fireEvent(destination);
//    }
//    protected void handleInvalidHeader(String reason)
//    {
//        badHeaderReceivedEvent.fireEvent(reason);
//    }
//    protected void handleUnhandledException(Exception e, String threadName)
//    {
//        unhandledExceptionEvent.fireEvent("Exception:" + e.getClass().getName() + " Thread:" + threadName);
//
//    }

}
