/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

import java.util.Vector;

/**
 *
 * @author Anton Gravestam
 */
public class Notifier <T>
{
    Vector<Listener<T>> listeners = new Vector<Listener<T>>();

    void notifyListeners(T arg)
    {
        for (Listener<T> listener : listeners)
        {
            listener.onNewEvent(this, arg);
        }
    }

    public boolean removeListener(Listener<T> listener)
    {
        return listeners.remove(listener);
    }

    public synchronized boolean addListener(Listener<T> listener)
    {
        return listeners.add(listener);
    }


}
