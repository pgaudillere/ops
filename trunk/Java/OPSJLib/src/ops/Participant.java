
package ops;

import configlib.exception.FormatException;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Anton Gravestam
 */
public class Participant 
{
    public final Event multicastNotAvailableEvent = new Event();
    public final Event networkLostEvent = new Event();
    public final Event networkRestoredEvent = new Event();
    public final Event badHeaderReceivedEvent = new Event();
    public final Event unhandledExceptionEvent = new Event();

    private OPSConfig config;

    private static Participant theParticipant = null;
    public static Participant getParticipant()
    {
        if(theParticipant == null)
        {
            theParticipant = new Participant();
        }
        return theParticipant;
        
    }
    private Participant()
    {
        try
        {
            config = OPSConfig.getConfig();
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

    public OPSConfig getConfig()
    {
        return config;
    }

    

    protected void handleMulticastNotAvailableError()
    {
        networkLostEvent.fireEvent("Multicast Error, possible loss of IP address.");
    }
    protected void handleNoRouteToUDPDestination(String destination)
    {
        networkLostEvent.fireEvent(destination);
    }
    protected void handleInvalidHeader(String reason)
    {
        badHeaderReceivedEvent.fireEvent(reason);
    }
    protected void handleUnhandledException(Exception e, String threadName)
    {
        unhandledExceptionEvent.fireEvent("Exception:" + e.getClass().getName() + " Thread:" + threadName);

    }

}
