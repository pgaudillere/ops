/*
 * ReliabilityQoS.java
 *
 * Created on den 21 september 2007, 11:24
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;

/**
 *
 * @author xangr
 */
public class ReliabilityQoS extends QualityOfService
{
    private int replyPort;
    private int nrOfResends = 1;
    private long resendInterval = 100;
    /** Creates a new instance of ReliabilityQoS */
    public ReliabilityQoS()
    {
        
    }
    public String getQoSID()
    {
        return "reliability";
    }
    
}
