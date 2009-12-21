/**
 *
 * Copyright (C) 2006-2009 Anton Gravestam.
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
        if (!instances.containsKey(participantID))
        {
            Participant newInst = new Participant(domainID, participantID, file);
            Domain tDomain = newInst.config.getDomain(domainID);

            if (tDomain != null)
            {
                instances.put(participantID, newInst);
            } else
            {
                return null;
            }
        }
        return instances.get(participantID);
    }
    private String domainID;
    private String participantID;
    private OPSConfig config;
    private HashMap<String, ReceiveDataHandler> receiveDataHandlers = new HashMap<String, ReceiveDataHandler>();
    private HashMap<String, SendDataHandler> sendDataHandlers = new HashMap<String, SendDataHandler>();

    private Participant(String domainID, String participantID, File configFile)
    {
        this.domainID = domainID;
        this.participantID = participantID;
        try
        {
            if (configFile == null)
            {
                config = OPSConfig.getConfig();
            } else
            {
                config = OPSConfig.getConfig(configFile);
            }
        } catch (IOException ex)
        {
            config = null;
        } catch (FormatException ex)
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

    ///By Singelton, one ReceiveDataHandler per Topic (Name)
    //This instance map should be owned by Participant.
    ReceiveDataHandler getReceiveDataHandler(Topic top)
    {
        if (!receiveDataHandlers.containsKey(top.getName()))
        {
            receiveDataHandlers.put(top.getName(), new ReceiveDataHandler(top, this));

        }
        return receiveDataHandlers.get(top.getName());
    }

    SendDataHandler getSendDataHandler(Topic t) throws CommException
    {
        if(t.getTransport().equals(Topic.TRANSPORT_MC))
        {
            try
            {
                return new McSendDataHandler(t, config.getDomain(domainID).getLocalInterface());
            } catch (IOException ex)
            {
                throw new CommException("Error creating SendDataHndler. IOException -->" + ex.getMessage());
            }
        }
        throw new CommException("No such Transport " + t.getTransport());
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
