/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package opsdebugger2.tabpanels.plotter;

import java.awt.Color;
import java.awt.Component;
import java.awt.Stroke;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.ListCellRenderer;
import opsdebugger2.OPSDebugger2App;
import opsdebugger2.proxy.TopicSubscriberProxy;
import opsdebugger2.proxy.ValueListener;

/**
 *
 * @author angr
 */
public class PlotValue extends JLabel implements ValueListener, ListCellRenderer
{
    private String valueName = "";
    private double currentValue = 0.0;
    private double lastValue = 0.0;
    
    private final PlotSettings settings;

    public PlotValue(String valueName, PlotSettings settings)
    {
        this.settings = settings;
        this.valueName = valueName;
        //OPSDebugger2App.getActiveSubscriberProxy().add(this);
        
        String topic = valueName;//OPSDebugger2App.getApplication().getActiveSubscriberProxy().getTopic().getName();
        //String domain = OPSDebugger2App.getActiveSubscriberProxy().getDomainAddress();
        TopicSubscriberProxy subPrx = new TopicSubscriberProxy(topic);
        
        subPrx.setKey(settings.keyVec);
        
        subPrx.add(this);
        
    }
    
    public Stroke getStroke()
    {
        return settings.stroke;
    }
    public Color getColor()
    {
        return settings.color;
        
    }
    

    public void onNewValue(Object value)
    {
        try
        {
            currentValue = (settings.scaleFactor * settings.transform * ((Double) value).doubleValue()) + settings.translatation;
            //System.out.println("" + currentValue);
        }
        catch (Exception e)
        {
            currentValue = 0;
        }
    }

    public String valueOfInterest()
    {
        return valueName;
    }

    public double getCurrentValue()
    {
        lastValue = currentValue;
        return currentValue;
    }

    public void setCurrentValue(double currentValue)
    {
        this.currentValue = currentValue;
    }

    public String getValueName()
    {
        
        return valueName;
    }

    public void setValueName(String valueName)
    {
        this.valueName = valueName;
    }

    public double getLastValue()
    {
        return lastValue;
    }

    public void setLastValue(double lastValue)
    {
        this.lastValue = lastValue;
    }
    
    public String toString()
    {
        return settings.nickname;
    }

    public Component getListCellRendererComponent(JList list, Object value, int index, boolean isSelected, boolean cellHasFocus)
    {
        setForeground(settings.color);
        this.setText(settings.nickname);
        return (Component)this;
        
    }
    
    
    
    
}
