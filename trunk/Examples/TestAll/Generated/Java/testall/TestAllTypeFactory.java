/**
 *
 * OPS generated code, DO NOT MODIFY!
 */
package TestAll;

import configlib.Serializable;
import configlib.SerializableFactory;


public class TestAllTypeFactory implements SerializableFactory
{
    public Serializable create(String type)
    {
		if(type.equals("testall.TestData"))
		{
			return new testall.TestData();
		}
		if(type.equals("testall.ChildData"))
		{
			return new testall.ChildData();
		}
		if(type.equals("testall.BaseData"))
		{
			return new testall.BaseData();
		}
		return null;

    }
}
