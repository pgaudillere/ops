/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

import configlib.ArchiverInOut;
import java.io.IOException;
import java.util.UUID;

/**
 *
 * @author Anton Gravestam
 */
public class Reply extends OPSObject
{

    public String requestId = "";
    public boolean requestAccepted = false;
    public String message = "";
    

    static UUID uuid = UUID.randomUUID();
    @Override
    public void serialize(ArchiverInOut archive) throws IOException
    {
        
        super.serialize(archive);
        archive.inout("requestId", requestId);
        archive.inout("requestAccepted", requestAccepted);
        archive.inout("message", message);
    }



}
