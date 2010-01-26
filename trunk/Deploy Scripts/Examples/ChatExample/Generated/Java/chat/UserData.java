//Auto generated OPS-code. DO NOT MODIFY!

package chat;

import ops.OPSObject;
import configlib.ArchiverInOut;
import java.io.IOException;

public class UserData extends OPSObject
{
	public String name = "";


    public UserData()
    {
        super();
        appendType("chat.UserData");

    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
		name = archive.inout("name", name);

    }
}