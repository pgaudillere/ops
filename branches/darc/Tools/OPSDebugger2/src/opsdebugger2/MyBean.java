/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package opsdebugger2;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;

/**
 *
 * @author angr
 */
public class MyBean {

    protected String hatt = "Hatt";
    public static final String PROP_HATT = "hatt";

    /**
     * Get the value of hatt
     *
     * @return the value of hatt
     */
    public String getHatt()
    {
        return hatt;
    }

    /**
     * Set the value of hatt
     *
     * @param hatt new value of hatt
     */
    public void setHatt(String hatt)
    {
        String oldHatt = this.hatt;
        this.hatt = hatt;
        propertyChangeSupport.firePropertyChange(PROP_HATT, oldHatt, hatt);
    }
    private PropertyChangeSupport propertyChangeSupport = new PropertyChangeSupport(this);

    /**
     * Add PropertyChangeListener.
     *
     * @param listener
     */
    public void addPropertyChangeListener(PropertyChangeListener listener)
    {
        propertyChangeSupport.addPropertyChangeListener(listener);
    }

    /**
     * Remove PropertyChangeListener.
     *
     * @param listener
     */
    public void removePropertyChangeListener(PropertyChangeListener listener)
    {
        propertyChangeSupport.removePropertyChangeListener(listener);
    }

    protected String myName = "No name";

    /**
     * Get the value of myName
     *
     * @return the value of myName
     */
    public String getMyName()
    {
        return myName;
    }

    /**
     * Set the value of myName
     *
     * @param myName new value of myName
     */
    public void setMyName(String myName)
    {
        this.myName = myName;
    }

}
