/**
*
* Copyright (C) 2006-2009 Anton Gravestam.
*
* This file is part of OPS (Open Publish Subscribe).
*
* OPS (Open Publish Subscribe) is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* OPS (Open Publish Subscribe) is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with OPS (Open Publish Subscribe).  If not, see <http://www.gnu.org/licenses/>.
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
