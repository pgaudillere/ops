/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

import configlib.ArchiverInOut;
import java.io.IOException;

/**
 *
 * @author Anton Gravestam
 */
public class Reply extends OPSObject
{

    public String requestId = "";
    public boolean requestAccepted = false;
    public String message = "";
    
    @Override
    public void serialize(ArchiverInOut archive) throws IOException
    {
        
        super.serialize(archive);
        requestId = archive.inout("requestId", requestId);
        requestAccepted = archive.inout("requestAccepted", requestAccepted);
        message = archive.inout("message", message);
    }



}
