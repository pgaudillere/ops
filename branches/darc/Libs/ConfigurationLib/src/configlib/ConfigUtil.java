/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package configlib;

import java.lang.reflect.Field;
import java.util.Vector;

/**
 *
 * @author angr
 */
public class ConfigUtil
{

    public static String toXMLNode(Object o, String name)
    {
        return "\n" + toXMLNode(o, name, 0);
    }

    public static String toXMLNode(Object o, String name, int indent)
    {
        String ret = "";

        try
        {
            ret += tabs(indent) + "<" + name + "\">\n";
            Field[] fields = o.getClass().getFields();

            indent++;
            for (Field field : fields)
            {
                if (field.get(o) instanceof Vector)
                {
                    for (Object ob : (Vector) field.get(o))
                    {
                        if (!ob.getClass().isPrimitive() && !ob.getClass().getName().equals("java.lang.String"))
                        {
                            ret += toXMLNode(ob, field.getName(), indent);
                        }
                        else
                        {
                            ret += tabs(indent) + "<" + field.getName() + ">" + ob + "</" + field.getName() + ">\n";
                        }
                    }
                }
                else
                {
                    if (!field.getType().isPrimitive() && !field.getType().getName().equals("java.lang.String"))
                    {
                        ret += toXMLNode(field.get(o), field.getName(), indent);
                    }
                    else
                    {
                        ret += tabs(indent) + "<" + field.getName() + ">" + field.get(o) + "</" + field.getName() + ">\n";
                    }
                }
            }
            indent--;
            ret += tabs(indent) + "</" + name + ">\n";

            return ret;
        }
        catch (SecurityException securityException)
        {
            return null;
        }
        catch (IllegalArgumentException illegalArgumentException)
        {
            return null;
        }
        catch (IllegalAccessException illegalAccessException)
        {
            return null;
        }

    }

    private static String tabs(int indent)
    {
        String ret = "";
        for (int i = 0; i < indent; i++)
        {
            ret += "\t";

        }
        return ret;
    }
}
