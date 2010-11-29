/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.debuggersupport;

import java.lang.reflect.Field;
import java.util.ArrayList;

/**
 *
 * @author Admin
 */
class NameValuePair
{

    public String name;
    public Object value;
    public boolean expanded;

    ArrayList<NameValuePair> children = new ArrayList<NameValuePair>();
    public Field field;

    public NameValuePair(String name, Object get, Field field)
    {
        this.name = name;
        this.value = get;
        this.field = field;
    }

    public boolean remove(Object o)
    {
        return children.remove(o);
    }

    public NameValuePair remove(int index)
    {
        return children.remove(index);
    }

    public void clear()
    {
        children.clear();
    }

    public boolean add(NameValuePair e)
    {
        return children.add(e);
    }

}
