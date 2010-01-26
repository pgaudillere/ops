/**
 *
 * OPS generated code, DO NOT MODIFY!
 */
package ChatExample;

import configlib.Serializable;
import configlib.SerializableFactory;


public class ChatExampleTypeFactory implements SerializableFactory
{
    public Serializable create(String type)
    {
		if(type.equals("chat.ExtendedChatData"))
		{
			return new chat.ExtendedChatData();
		}
		if(type.equals("chat.ExtendedUserData"))
		{
			return new chat.ExtendedUserData();
		}
		if(type.equals("chat.ChatData"))
		{
			return new chat.ChatData();
		}
		if(type.equals("chat.MessageData"))
		{
			return new chat.MessageData();
		}
		if(type.equals("chat.UserData"))
		{
			return new chat.UserData();
		}
		return null;

    }
}
