package opsdebugger2.proxy;

import java.lang.reflect.Field;
import java.util.Vector;
import sun.reflect.generics.reflectiveObjects.ParameterizedTypeImpl;

/**
 *
 * @author Anton Gravestam
 */
public class FieldLister
{

    public static Vector<String> listFields(String parentPath, Class cls)
    {
        Vector<String> ret = new Vector<String>();
        Field[] fields = cls.getFields();
        for (Field field : fields)
        {
            if (field.getType().isPrimitive())
            {
                ret.add(parentPath + field.getName());
            }
            if (field.getType().getName().equals("java.lang.String"))
            {
                ret.add(parentPath + field.getName());
            }
            if (field.getType().getName().equals("java.util.Vector"))
            {

                Class clazz = (Class) ((ParameterizedTypeImpl) field.getGenericType()).getActualTypeArguments()[0];
                System.out.println("Gen type " + field.getGenericType().getClass());

                ret.addAll(listFields(parentPath + field.getName() + "[element]->", clazz));
            } else
            {
                ret.addAll(listFields(parentPath + field.getName() + "->", field.getType()));
            }
        }

        return ret;


    }

    public static Object getFieldValue(Object o, String fieldPath) throws NoSuchFieldException, IllegalArgumentException, IllegalAccessException
    {
        Field field = null;
        String[] fieldArr = fieldPath.split("->");

        for (int i = 1; i < fieldArr.length; i++)
        {
            if (fieldArr[i].contains("["))
            {// o is a Vector we need to find the right element
                int startIndex = fieldArr[i].indexOf("[");
                int endIndex = fieldArr[i].indexOf("]");

                String elementString = fieldArr[i].substring(startIndex + 1, endIndex);

                int elementNr = Integer.parseInt(elementString);

                field = o.getClass().getField(fieldArr[i].substring(0, fieldArr[i].indexOf("[")));
                o = field.get(o);
                try
                {
                    field = ((Vector) o).get(elementNr).getClass().getField(fieldArr[i + 1]);

                    o = ((Vector) o).get(elementNr);
                } catch (ArrayIndexOutOfBoundsException ex)
                {
                    return "";
                }
            } else
            {
                field = o.getClass().getField(fieldArr[i]);
                o = field.get(o);
            }
        }

        //field = o.getClass().getField(fieldArr[fieldArr.length - 1]);

        return o;
    }
}
