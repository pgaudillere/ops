/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package opsdebugger2.proxy;

import ops.Subscriber;

/**
 *
 * @author angr
 */
public interface OPSValueListener
{

    public void onError(Subscriber subscriber, OPSValueNotifier notifier, String message);
    public void onNewValue(Subscriber sub, OPSValueNotifier notifier, Object value);

}
