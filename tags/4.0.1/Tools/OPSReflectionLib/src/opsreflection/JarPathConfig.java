/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package opsreflection;

import configlib.ArchiverInOut;
import configlib.Serializable;
import java.io.IOException;

/**
 *
 * @author angr
 */
class JarPathConfig implements Serializable
{
    String path = "";

    JarPathConfig(String path)
    {
        this.path = path;
    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        path = archive.inout("path", path);
    }

}
