/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops.archiver;

import configlib.Serializable;
import configlib.SerializableCompositeFactory;
import configlib.SerializableFactory;
import ops.DefaultOPSConfigImpl;
import ops.MulticastDomain;
import ops.Topic;
import ops.protocol.OPSMessage;

/**
 *
 * @author angr
 */
public class OPSObjectFactory extends SerializableCompositeFactory
{
    static OPSObjectFactory instance = null;
    /**
     * Create singelton instance of OPSObjectFactory.
     * @return
     */
    public static OPSObjectFactory getInstance()
    {
        if(instance == null)
        {
            instance = new OPSObjectFactory();
            instance.add(new SerializableFactory() {

                public Serializable create(String type)
                {
                    if(type.equals("ops.protocol.OPSMessage"))
                    {
                        return new OPSMessage();
                    }
                    if(type.equals("DefaultOPSConfigImpl"))
                    {
                        return new DefaultOPSConfigImpl();
                    }
                    if(type.equals("MulticastDomain"))
                    {
                        return new MulticastDomain();
                    }
                    if(type.equals("Topic"))
                    {
                        return new Topic();
                    }

                    return null;
                }
            });
        }
        return instance;
    }
    /**
     * Tries to construct the most specialized version of the given typeString
     */
    @Override
    public Serializable create(String typeString)
    {
        String[] types = typeString.split(" ");
        for (String type : types)
        {
            Serializable serializable = super.create(type);
            if(serializable != null)
            {
                return serializable;
            }
        }

        return null;
    }



}
