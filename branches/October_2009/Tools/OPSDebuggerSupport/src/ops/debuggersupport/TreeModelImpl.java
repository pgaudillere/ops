/*
 * To change this template, choose Tools | Tmplates
 * and open the template in the editor.
 */
package ops.debuggersupport;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
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

    //private Object object;
    ArrayList<ModelListener> modelListeners = new ArrayList<ModelListener>();
    private NameValuePair root = new NameValuePair("Field", null, null);
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
        //this.object = object;

        if(root.value == null)
        {
            root.value = object;
            //root.clear();

            populateNode(root);
        }
        else
        {
            updateNode(root, object);
        }

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
        if(from == 0 && to == nvp.children.size() )
        {
            return nvp.children.toArray();
        }
        else
        {
            System.out.println("WARNING, list copy required!");
            return Arrays.copyOfRange(nvp.children.toArray(), from, to);
        }

    }

    public boolean isLeaf(Object node)
    {
        NameValuePair fvp = (NameValuePair) node;
        return fvp.children.size() == 0;
    }


    public int getChildrenCount(Object parent) throws UnknownTypeException
    {
        NameValuePair nvp = (NameValuePair) parent;
        return nvp.children.size();
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

    private void populateNode(NameValuePair parent)
    {
        NameValuePair nvp = (NameValuePair) parent;

        ArrayList<NameValuePair> children = new ArrayList();
        Field[] fields = nvp.value.getClass().getFields();

        if(parent == root)
        {
            parent.add(new NameValuePair("publicationID", subscriber.getMessage().getPublicationID(), null));
            parent.add(new NameValuePair("key", ((OPSObject)root.value).getKey(), null));
            parent.add(new NameValuePair("publisherName", subscriber.getMessage().getPublisherName(), null));
        }

        for (int i = 0; i < fields.length; i++)
        {
            Field field = fields[i];
            try
            {
                NameValuePair child = new NameValuePair(field.getName(), field.get(nvp.value), field);
                if(!isBasicType(child.value))
                    populateNode(child);
                parent.add(child);
            } catch (IllegalArgumentException ex)
            {
                Exceptions.printStackTrace(ex);
            } catch (IllegalAccessException ex)
            {
                Exceptions.printStackTrace(ex);
            }

        }

    }

    private void updateNode(NameValuePair node, Object value)
    {
        if(isBasicType(value))
        {
            node.value = value;
        }
        else
        {
            
            for (int i = 0; i < node.children.size(); i++)
            {
                NameValuePair child = node.children.get(i);
                try
                {
                    if(node == root)
                    {
                        switch(i)
                        {
                            case 0:
                                updateNode(child, subscriber.getMessage().getPublicationID());
                                break;
                            case 1:
                                updateNode(child, subscriber.getMessage().getTopLevelKey());
                                break;
                            case 2:
                                updateNode(child, subscriber.getMessage().getPublisherName());
                                break;
                            default:
                                updateNode(child, child.field.get(value));
                                
                        }
                    }
                    else
                    {
                        updateNode(child, child.field.get(value));
                    }
                     //Note, add field to each NmaeValuePair
                } catch (IllegalArgumentException ex)
                {
                    Exceptions.printStackTrace(ex);
                } catch (IllegalAccessException ex)
                {
                    Exceptions.printStackTrace(ex);
                }
                
            }

            
        }


    }
}
