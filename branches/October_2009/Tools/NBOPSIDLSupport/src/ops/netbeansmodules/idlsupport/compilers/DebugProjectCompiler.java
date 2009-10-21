/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.netbeansmodules.idlsupport.compilers;

import java.util.Vector;
import ops.netbeansmodules.idlsupport.projectproperties.JarDependency;
import ops.netbeansmodules.idlsupport.projectproperties.OPSProjectProperties;
import parsing.AbstractTemplateBasedIDLCompiler;
import parsing.IDLClass;
import parsing.TopicInfo;

/**
 *
 * @author angr
 */
public class DebugProjectCompiler extends AbstractTemplateBasedIDLCompiler
{
    final static String DOMAIN_ID_REGEX = "__DomainID";
    final static String JAR_PATHS_REGEX = "__jarPaths";

    public void compileDataClasses(Vector<IDLClass> arg0, String arg1)
    {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public void compileTopicConfig(Vector<TopicInfo> arg0, String arg1, String arg2, String arg3)
    {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public void createDebugProjectFile(String projectDirectory, String projectName, OPSProjectProperties projProps)
    {
        System.out.println("Creating Debug Project File: " + projectDirectory);

        setOutputFileName(projectDirectory + "/" + "DebugProject.xml");
        setTemplateFileName("templates/debugproj.tpl");
        setTabString("    ");//Default is "\t"
        //setEndlString("\n");//Default is "\r\n"

        String result = getTemplateText();

        result = result.replaceAll(DOMAIN_ID_REGEX, projProps.debugProjDomainID);
        result = result.replaceAll(JAR_PATHS_REGEX, createJarPaths(projProps, projectName));

        saveOutputText(result);

    }

    public String getName()
    {
        return "DebugProjectCompiler";
    }

    private String createJarPaths(OPSProjectProperties projProps, String projectName)
    {
        String ret = "";
        ret += "<path>Generated/" + projectName + ".jar</path>" + endl();

        for (JarDependency jarDependency : projProps.javaBuildJarDependencies)
        {
            ret += "<path>" + jarDependency.path + "</path>" + endl();
        }

        return ret;
    }
}
