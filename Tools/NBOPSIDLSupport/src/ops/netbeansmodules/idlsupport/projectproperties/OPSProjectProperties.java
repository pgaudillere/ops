/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.netbeansmodules.idlsupport.projectproperties;

import configlib.ArchiverInOut;
import configlib.Serializable;
import configlib.SerializableFactory;
import java.io.IOException;
import java.util.Vector;

/**
 *
 * @author angr
 */
public class OPSProjectProperties implements Serializable
{

    public boolean generateCpp = true;
    public boolean generateJava = true;
    public boolean buildJava = true;
    public String defaultOPSTopicConfigFile = "src/ops_config.xml";
    public Vector<String> javaBuildJarDependencies = new Vector();
    public boolean generateOPSConfigClass = false;
    public boolean opsConfigClassNamespace = false;
    public boolean generateOPSConfigXMLFileFromSourceComments = false;
    public boolean addChecksumToConfig = false;

    public void serialize(ArchiverInOut archiver) throws IOException
    {
        generateCpp = archiver.inout("generateCpp", generateCpp);
        generateJava = archiver.inout("generateJava", generateJava);
        buildJava = archiver.inout("buildJava", buildJava);
        defaultOPSTopicConfigFile = archiver.inout("defaultOPSTopicConfigFile", defaultOPSTopicConfigFile);
        generateOPSConfigClass = archiver.inout("generateOPSConfigClass", generateOPSConfigClass);
        javaBuildJarDependencies = (Vector<String>) archiver.inoutSerializableList("javaBuildJarDependencies", javaBuildJarDependencies);
    }

    static SerializableFactory getSerializableFactory()
    {
        return new OPSProjectPropertiesFactory();
    }


    static class OPSProjectPropertiesFactory implements SerializableFactory
    {

        public Serializable create(String type)
        {
            if (type.equals("ops.netbeansmodules.idlsupport.projectproperties.OPSProjectProperties"))
            {
                return new OPSProjectProperties();
            }
            return null;
        }
    }
}
