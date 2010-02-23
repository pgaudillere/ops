//Auto generated OPS-code. DO NOT MODIFY!

package __packageName;

public final class __className extends ops.OPSObject
{
    public static String getTypeName(){return "__packageName.__className";}

    public static enum Value {__declarations UNDEFINED};
    public Value value = Value.values()[0];

    public __className()
    {
        super();
        appendType(getTypeName());
    }
    public __className(Value value)
    {
        super();
        appendType(getTypeName());
    }
    public void serialize(configlib.ArchiverInOut archive) throws java.io.IOException
    {
        super.serialize(archive);
        value = fromInt(archive.inout("value", toInt(value)));
    }
    static Value fromInt(int i)
    {
        if(i < Value.values().length)
        {
            return Value.values()[i];
        }
        return Value.UNDEFINED;
    }
    static int toInt(Value value)
    {
        return value.ordinal();

    }
}

