/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package opsdebugger2.proxy;

import configlib.ArchiverInOut;
import configlib.Serializable;
import java.io.IOException;
import java.util.List;
import java.util.Observable;
import java.util.Observer;
import java.util.logging.Level;
import java.util.logging.Logger;
import ops.OPSObject;
import ops.Subscriber;
import opsreflection.OPSFactory;

/**
 *
 * @author angr
 */
public class OPSValueNotifier
{
    private Subscriber subscriber;
    private OPSValueListener listener;
    private String valuePath;


    public OPSValueNotifier(Subscriber subscriber, OPSValueListener listener, String valuePath)
    {
        this.subscriber = subscriber;
        setupObserver(subscriber);
        this.listener = listener;
        this.valuePath = valuePath;
    }

    private void onNewOPSObject(OPSObject data)
    {
        try
        {
            listener.onNewValue(subscriber, this, FieldLister.getFieldValue(data, valuePath));
        } catch (NoSuchFieldException ex)
        {
            listener.onError(subscriber, this, ex.getMessage());
        } catch (IllegalArgumentException ex)
        {
            listener.onError(subscriber, this, ex.getMessage());
        } catch (IllegalAccessException ex)
        {
            listener.onError(subscriber, this, ex.getMessage());
        }
    }

    private void setupObserver(Subscriber subscriber)
    {
        subscriber.addObserver(new Observer()
        {

            public void update(Observable o, Object arg)
            {
                onNewOPSObject((OPSObject) arg);
            }
        });
    }
}
