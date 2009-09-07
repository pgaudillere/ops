/*
 * To change this template, choose Tools | Tmplates
 * and open the template in the editor.
 */
package ops.debuggersupport;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Observable;
import java.util.Observer;
import ops.OPSObject;
import ops.Subscriber;
import org.netbeans.spi.viewmodel.ModelEvent;
import org.netbeans.spi.viewmodel.ModelListener;
import org.netbeans.spi.viewmodel.TreeModel;
import org.netbeans.spi.viewmodel.UnknownTypeException;
import org.openide.util.Exceptions;

/**
 *
 * @author Admin
 */
public class TreeModelImpl implements TreeModel
{

    private Object object;
    ArrayList<ModelListener> modelListeners = new ArrayList<ModelListener>();
    private NameValuePair root = new NameValuePair("Field", "");
    private Subscriber subscriber;



    public TreeModelImpl(Subscriber subscriber)
    {
      
        this.subscriber = subscriber;
        subscriber.setTimeBasedFilterQoS(200);
        subscriber.addObserver(new Observer() {

            public void update(Observable o, Object arg)
            {
                setObject(arg);
            }
        });
        subscriber.start();
    }

    public void setObject(Object object)
    {
        this.object = object;
        root.value = object;
        ModelEvent event = new ModelEvent.NodeChanged(this, root);
        for (ModelListener modelListener : modelListeners)
        {
            modelListener.modelChanged(event);
        }
    }



    public Object getRoot()
    {
        return root;
    }

    public Object[] getChildren(Object parent, int from, int to)
    {

        NameValuePair nvp = (NameValuePair) parent;

        ArrayList children = new ArrayList();
        Field[] fields = nvp.value.getClass().getFields();

        if(parent == root)
        {
            children.add(new NameValuePair("publicationID", subscriber.getMessage().getPublicationID()));
            children.add(new NameValuePair("key", ((OPSObject)root.value).getKey()));
            children.add(new NameValuePair("publisherName", subscriber.getMessage().getPublisherName()));
        }

        for (int i = from; i < to; i++)
        {
            Field field = fields[i];
            try
            {
                children.add(new NameValuePair(field.getName(), field.get(nvp.value)));
            } catch (IllegalArgumentException ex)
            {
                Exceptions.printStackTrace(ex);
            } catch (IllegalAccessException ex)
            {
                Exceptions.printStackTrace(ex);
            }

        }
           
        return children.toArray();
    }

    public boolean isLeaf(Object node)
    {
        NameValuePair fvp = (NameValuePair) node;
        return isBasicType(fvp.value);
    }


    public int getChildrenCount(Object parent) throws UnknownTypeException
    {
        NameValuePair nvp = (NameValuePair) parent;
        return nvp.value.getClass().getFields().length;
    }

    public void addModelListener(ModelListener modelListener)
    {
        //throw new UnsupportedOperationException("Not supported yet.");
        modelListeners.add(modelListener);
    }

    public void removeModelListener(ModelListener modelListener)
    {
        //throw new UnsupportedOperationException("Not supported yet.");
        modelListeners.remove(modelListener);
    }
    private boolean isBasicType(Object o)
    {

        if (o instanceof Integer ||
                o instanceof Byte ||
                o instanceof String ||
                o instanceof Float ||
                o instanceof Double ||
                o instanceof Long ||
                o instanceof Short ||
                o instanceof Boolean)
        {
            return true;
        } else
        {
            return false;
        }
    }
}
