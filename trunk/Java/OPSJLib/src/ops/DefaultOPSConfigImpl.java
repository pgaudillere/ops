/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

import configlib.ArchiverInOut;
import java.io.IOException;

/**
 *
 * @author angr
 */
public class DefaultOPSConfigImpl extends OPSConfig
{

    public DefaultOPSConfigImpl()
    {
        appendType("DefaultOPSConfigImpl");
    }

    @Override
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
    }
    
}
