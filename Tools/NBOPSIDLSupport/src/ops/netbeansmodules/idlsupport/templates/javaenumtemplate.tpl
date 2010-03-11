//Auto generated OPS-code. DO NOT MODIFY!

package __packageName;

public final class __className extends ops.OPSObject implements ops.OPSEnum
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
    public void setByValueString(String valueString)
    {
         for(Value val : Value.values())
         {
             if(val.name().equals(valueString))
                 value = val;
         }
    }
    public void serialize(configlib.ArchiverInOut archive) throws java.io.IOException
    {
        super.serialize(archive);
        value = fromInt(archive.inout("value", toInt(value)));
    }
    @Override
    public Object clone()
    {
        __className cloneResult = new __className();
        cloneResult.value = this.value;
        return cloneResult;
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

