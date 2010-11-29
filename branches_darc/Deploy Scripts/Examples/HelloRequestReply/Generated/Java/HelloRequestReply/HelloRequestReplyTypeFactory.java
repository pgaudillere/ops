/**
 *
 * OPS generated code, DO NOT MODIFY!
 */
package HelloRequestReply;

import configlib.Serializable;
import configlib.SerializableFactory;


public class HelloRequestReplyTypeFactory implements SerializableFactory
{
    public Serializable create(String type)
    {
		if(type.equals("hello.HelloData"))
		{
			return new hello.HelloData();
		}
		if(type.equals("hello.RequestHelloData"))
		{
			return new hello.RequestHelloData();
		}
		return null;

    }
}
