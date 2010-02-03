/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

/**
 *
 * @author Anton Gravestam
 */
public interface Listener<T>
{
    public void onNewEvent(Notifier<T> notifier, T arg);

}
