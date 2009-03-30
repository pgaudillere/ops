
package ops;

/**
 *
 * @author Anton Gravestam
 */
public class DefaultDataValidator implements DataValidator 
{

    public AckData validateData(OPSObject o)
    {
        return getDefaultAck();
    }
   

    protected AckData getDefaultAck()
    {
        AckData ack = new AckData();
        ack.dataAccepted = true;
        ack.message = "Unchecked validation";
        return ack;
    }

}
