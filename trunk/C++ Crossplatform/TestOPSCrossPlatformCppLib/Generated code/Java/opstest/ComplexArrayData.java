//Auto generated OPS-code. DO NOT MODIFY!

package opstest;

import ops.OPSObject;

public class ComplexArrayData extends OPSObject
{
	public long timestamp;
	public java.util.Vector<ComplexData> values = new java.util.Vector<ComplexData>();


    public ComplexArrayData()
    {

    }
    public Object clone()
    {
       return ComplexArrayDataHelper.copy(this);
    }
}