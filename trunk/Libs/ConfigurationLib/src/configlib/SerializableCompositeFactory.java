/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package configlib;

import java.util.ArrayList;

/**
 *
 * @author angr
 */
public class SerializableCompositeFactory implements SerializableFactory
{

    ArrayList<SerializableFactory> childFactories = new ArrayList<SerializableFactory>();

    public boolean remove(Object o)
    {
        return childFactories.remove(o);
    }

    public boolean add(SerializableFactory e)
    {
        return childFactories.add(e);
    }



    public Serializable create(String type)
    {
        Serializable obj = null;
        for (SerializableFactory inOutableFactory : childFactories)
        {
            obj = inOutableFactory.create(type);
            if(obj != null)
            {
                return obj;
            }
        }
        return obj;
    }
}
