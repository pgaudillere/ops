/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.debuggersupport;

import java.util.ArrayList;

/**
 *
 * @author Admin
 */
class NameValuePair
{

    public String name;
    public Object value;

    ArrayList<NameValuePair> children = new ArrayList();

    public NameValuePair(String name, Object get)
    {
        this.name = name;
        this.value = get;
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
