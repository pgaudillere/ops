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
public class Request extends OPSObject
{

    public String requestId = "";

    @Override
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
        requestId = archive.inout("requestId" , requestId);
    }



}
