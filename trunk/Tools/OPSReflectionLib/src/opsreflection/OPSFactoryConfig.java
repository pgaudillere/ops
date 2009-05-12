/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package opsreflection;

import configlib.ArchiverInOut;
import configlib.Serializable;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author angr
 */
public class OPSFactoryConfig implements Serializable
{
    
    ArrayList<JarPathConfig> jarFilePaths = new ArrayList<JarPathConfig>();
    String domainID = "";
    String opsConfigRelativePath = "";

    public ArrayList<File> getJarFiles()
    {
        ArrayList<File> jarFiles = new ArrayList<File>();
        for (JarPathConfig jarPathConfig : jarFilePaths)
        {
            jarFiles.add(new File(jarPathConfig.path));
        }
        return jarFiles;
    }

    public void serialize(ArchiverInOut archive) throws IOException
    {
        jarFilePaths = (ArrayList<JarPathConfig>) archive.inoutSerializableList("jarFilePaths", jarFilePaths);
        domainID = archive.inout("domainID", domainID);
        opsConfigRelativePath = archive.inout("opsConfigRelativePath", opsConfigRelativePath);
    }

}

