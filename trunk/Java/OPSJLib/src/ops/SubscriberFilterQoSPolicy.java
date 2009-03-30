/*
 * SubscriberFilterQoSPolicy.java
 *
 * Created on den 7 oktober 2007, 21:10
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;

/**
 *
 * @author Anton Gravestam
 * SubscriberFilterQoSPolicies may be used to prevent data samples to be delivered to the application layer.
 */
public interface SubscriberFilterQoSPolicy
{
    /**
     * Should return true if the sample "passes the filter" and false if not.
     * Returning false will prevent the data to be made available to the application.
     */
    public boolean applyFilter(OPSObject data);
    
}
