/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

/**
 *
 * @author angr
 */
public class TransportFactory
{

    public static Transport getTransport(Topic t)
    {
        return new MulticastTransport(t.getDomainAddress(), t.getPort());
    }

}
