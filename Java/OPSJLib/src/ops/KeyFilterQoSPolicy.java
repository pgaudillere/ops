/*
 * KeyFilterQoSPolicy.java
 *
 * Created on den 30 november 2007, 10:20
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;

import java.util.Vector;

/**
 *
 * @author angr
 */
public class KeyFilterQoSPolicy implements FilterQoSPolicy
{
    
    private Vector<String> keys;
    
    /** Creates a new instance of KeyFilterQoSPolicy */
    public KeyFilterQoSPolicy()
    {
        this.setKeys(new Vector<String>());
        
    }
    public KeyFilterQoSPolicy(String key)
    {
        this.setKeys(new Vector<String>());
        this.getKeys().add(key);
    }
    public KeyFilterQoSPolicy(Vector<String> keys)
    {
        this.setKeys(keys);
        
    }
    
    public final Vector<String> getKeys()
    {
        return keys;
    }
    
    public synchronized void setKeys(Vector<String> keys)
    {
        this.keys = keys;
    }
    public synchronized void setKey(String key)
    {
        this.keys.clear();
        this.keys.add(key);
    }
    
    public boolean applyFilter(OPSObject o)
    {
        synchronized(this)
        {
            for (String key : keys)
            {
                if(o.getKey().equals(key))
                {
                    return true;
                }
            }
            return false;
        }
    }
    
}
