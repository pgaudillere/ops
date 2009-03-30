/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops;

import java.util.Observable;

/**
 *
 * @author Anton Gravestam
 */
public class Event extends Observable
{
    
    public void fireEvent(Object args)
    {
        setChanged();
        notifyObservers(args);
    }
    public void fireEvent()
    {
        setChanged();
        notifyObservers();
    }
}
