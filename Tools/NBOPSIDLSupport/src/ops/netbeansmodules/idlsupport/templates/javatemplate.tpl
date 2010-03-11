//Auto generated OPS-code. DO NOT MODIFY!

package __packageName;

import ops.OPSObject;
import configlib.ArchiverInOut;
import configlib.SerializableFactory;
import configlib.Serializable;
import java.io.IOException;

public class __className extends __baseClassName
{
__declarations

    private static SerializableFactory factory = new TypeFactory();

    public static String getTypeName(){return "__packageName.__className";}

    public static SerializableFactory getTypeFactory()
    {
        return factory;
    }

    public __className()
    {
        super();
        appendType(getTypeName());
__constructorBody
    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
__serialize
    }
    @Override
    public Object clone()
    {
        __className cloneResult = (__className)super.clone();
__cloneBody
        return cloneResult;
    }

    private static class TypeFactory implements SerializableFactory
    {
        public Serializable create(String type)
        {
            if (type.equals(__className.getTypeName()))
            {
                return new __className();
            }
            else
            {
                return null;
            }
        }
    }
}

