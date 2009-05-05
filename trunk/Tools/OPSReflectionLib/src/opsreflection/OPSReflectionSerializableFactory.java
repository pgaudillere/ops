/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package opsreflection;

import configlib.Serializable;
import configlib.SerializableFactory;

/**
 *
 * @author angr
 */
public class OPSReflectionSerializableFactory implements SerializableFactory
{

    public Serializable create(String type)
    {
        if(type.equals("opsreflection.OPSFactoryConfig"))
        {
            return new OPSFactoryConfig();
        }
        if(type.equals("opsreflection.JarPathConfig"))
        {
            return new JarPathConfig("");
        }
        return null;
    }

}
