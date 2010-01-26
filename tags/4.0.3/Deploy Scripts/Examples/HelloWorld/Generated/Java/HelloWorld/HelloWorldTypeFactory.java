/**
 *
 * OPS generated code, DO NOT MODIFY!
 */
package HelloWorld;

import configlib.Serializable;
import configlib.SerializableFactory;


public class HelloWorldTypeFactory implements SerializableFactory
{
    public Serializable create(String type)
    {
		if(type.equals("hello.HelloData"))
		{
			return new hello.HelloData();
		}
		return null;

    }
}
