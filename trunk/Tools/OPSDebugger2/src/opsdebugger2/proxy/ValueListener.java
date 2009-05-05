/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package opsdebugger2.proxy;

/**
 *
 * @author angr
 */
public interface ValueListener
{
    public void onNewValue(Object value);
    public String valueOfInterest();
}
