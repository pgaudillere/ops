
package ops;

/**
 *
 * @author Anton Gravestam
 */
public class Participant 
{
    //public final Event multicastNotAvailableEvent = new Event();
    public final Event networkLostEvent = new Event();
    //public final Event networkRestoredEvent = new Event();
    public final Event badHeaderReceivedEvent = new Event();
    public final Event unhandledExceptionEvent = new Event();

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
