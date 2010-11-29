//Auto generated OPS-code. DO NOT MODIFY!

package chat;

import ops.OPSObject;
import configlib.ArchiverInOut;
import java.io.IOException;

public class ExtendedUserData extends UserData
{
	public String nickname = "";
	public String email = "";
	public String telephone = "";
	public String profileImageUrl = "";


    public ExtendedUserData()
    {
        super();
        appendType("chat.ExtendedUserData");

    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
		nickname = archive.inout("nickname", nickname);
		email = archive.inout("email", email);
		telephone = archive.inout("telephone", telephone);
		profileImageUrl = archive.inout("profileImageUrl", profileImageUrl);

    }
}