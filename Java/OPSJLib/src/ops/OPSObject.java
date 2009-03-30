/*
 * OPSObject.java
 *
 * Created on den 20 maj 2007, 20:58
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;

import configlib.ArchiverInOut;
import configlib.Serializable;
import java.io.IOException;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Anton Gravestam
 */
public class OPSObject implements Serializable
{
    protected String key = "k";
    protected String typesString = "";

    public OPSObject()
    {

    }

    protected void appendType(String type)
    {
        typesString = type + " " + typesString;
    }
  
    public void setKey(String key)
    {
        this.key = key;
    }
   
    public String getKey()
    {
        return key;
    }

    public String getTypesString()
    {
        return typesString;
    }

    @Override
    protected Object clone() 
    {
        return null;
    }

    public void serialize(ArchiverInOut archive) throws IOException
    {
        archive.inout("key", key);
    }
   
    

    
 
    
}
