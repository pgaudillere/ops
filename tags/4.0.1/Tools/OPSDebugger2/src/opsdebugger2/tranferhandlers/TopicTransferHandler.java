/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package opsdebugger2.tranferhandlers;

import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.UnsupportedFlavorException;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.TransferHandler;
import opsdebugger2.OPSDebugger2App;
import opsdebugger2.proxy.ValueListener;

/**
 *
 * @author angr
 */
public class TopicTransferHandler extends TransferHandler
{
    private ValueListener valueListener;
    
    public TopicTransferHandler()
    {
    }

    TopicTransferHandler(ValueListener vListener)
    {
        this.valueListener = vListener;
    }

    @Override
    public boolean canImport(TransferSupport support)
    {
        return true;
    }

    @Override
    public boolean importData(TransferSupport support)
    {
        try
        {
            String dropedName = (String) support.getTransferable().getTransferData(DataFlavor.stringFlavor);
            PropertyChangeEvent evt = new PropertyChangeEvent(this, "New drop", null, dropedName);

            propertyChangeSupport.firePropertyChange(evt);
            return true;
        }
        catch (UnsupportedFlavorException ex)
        {
            Logger.getLogger(TopicTransferHandler.class.getName()).log(Level.SEVERE, null, ex);
        }
        catch (IOException ex)
        {
            Logger.getLogger(TopicTransferHandler.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
        
        
    }
    
        protected String valueDroped;

    /**
     * Get the value of valueDroped
     *
     * @return the value of valueDroped
     */
    public String getValueDroped()
    {
        return valueDroped;
    }

    /**
     * Set the value of valueDroped
     *
     * @param valueDroped new value of valueDroped
     */
    public void setValueDroped(String valueDroped)
    {
        this.valueDroped = valueDroped;
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

    
    
    
}
