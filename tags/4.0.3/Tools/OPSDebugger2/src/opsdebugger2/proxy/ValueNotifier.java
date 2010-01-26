/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package opsdebugger2.proxy;

import java.util.ArrayList;
import java.util.TreeMap;
import java.util.Vector;

/**
 *
 * @author angr
 */
public class ValueNotifier
{
    Vector<ValueListener> listeners = new Vector<ValueListener>();
    
    

    public void notifyNewValue(String valueName, Object value)
    {
        try
        {
            Number val = (Number) value;
            for (ValueListener valueListener : listeners)
            {
                if (valueListener.valueOfInterest().equals(valueName))
                {
                    valueListener.onNewValue(val.doubleValue());
                }
            }
        }
        catch (ClassCastException e)
        {
            //This is not a number....
        }
    }
    public boolean remove(Object o)
    {
        return listeners.remove(o);
    }

    public synchronized boolean add(ValueListener e)
    {
        return listeners.add(e);
    }
    
}
