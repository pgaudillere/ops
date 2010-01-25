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
        archive.inout("requestId", requestId);
        archive.inout("requestAccepted", requestAccepted);
        archive.inout("message", message);
    }



}
