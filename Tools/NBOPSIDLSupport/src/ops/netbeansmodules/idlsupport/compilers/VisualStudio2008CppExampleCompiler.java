/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.netbeansmodules.idlsupport.compilers;

import java.util.Vector;
import ops.netbeansmodules.idlsupport.projectproperties.OPSProjectProperties;
import parsing.AbstractTemplateBasedIDLCompiler;
import parsing.IDLClass;
import parsing.TopicInfo;

/**
 *
 * @author angr
 */
public class VisualStudio2008CppExampleCompiler extends AbstractTemplateBasedIDLCompiler
{
    public static String PROJ_NAME_REGEX = "__projectName";
    public static String TOPIC_NAME_REGEX = "__topicName";
    public static String DATA_TYPE_REGEX = "__dataType";
    public static String DOMAIN_ID_REGEX = "__domainName";
    public static String INCLUDE_DATA_TYPE_PATH_REGEX = "__includeDataTypePath";

    public void compileVSCppExample(String projectDirectory, String projectName, OPSProjectProperties projProps)
    {
        String subCppPath = projectDirectory + "/" + "Generated/Visual Studio Examples/" + projProps.vsExampleTopicName  + "/" + projProps.vsExampleTopicName + "_sub.cpp";
        String pubCppPath = projectDirectory + "/" + "Generated/Visual Studio Examples/" + projProps.vsExampleTopicName  + "/" + projProps.vsExampleTopicName + "_pub.cpp";
        String subProjPath = projectDirectory + "/" + "Generated/Visual Studio Examples/" + projProps.vsExampleTopicName  + "/" + projProps.vsExampleTopicName + "_sub.vcproj";
        String pubProjPath = projectDirectory + "/" + "Generated/Visual Studio Examples/" + projProps.vsExampleTopicName  + "/" + projProps.vsExampleTopicName + "_pub.vcproj";
        String slnPath = projectDirectory + "/" + "Generated/Visual Studio Examples/" + projProps.vsExampleTopicName + "/" + projProps.vsExampleTopicName + "_example.sln";
        String opsConfigPath = "";
        

        createFile(slnPath, "templates/vs_sln.tpl", projectName, projProps);
        createFile(pubProjPath, "templates/vs_pub_proj.tpl", projectName, projProps);
        createFile(subProjPath, "templates/vs_sub_proj.tpl", projectName, projProps);
        createFile(pubCppPath, "templates/vs_pub_cpp.tpl", projectName, projProps);
        createFile(subCppPath, "templates/vs_sub_cpp.tpl", projectName, projProps);


    }

    public void compileDataClasses(Vector<IDLClass> arg0, String arg1)
    {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public void compileTopicConfig(Vector<TopicInfo> arg0, String arg1, String arg2, String arg3)
    {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public String getName()
    {
        return "VisualStudio2008CppExampleCompiler";
    }

    private void createFile(String slnPath, String tplPath, String projectName, OPSProjectProperties projProps)
    {
        setOutputFileName(slnPath);
        setTemplateFileName(tplPath);
        setTabString("    "); //Default is "\t"
        String result = getTemplateText();
        result = result.replaceAll(TOPIC_NAME_REGEX, projProps.vsExampleTopicName);
        result = result.replaceAll(DATA_TYPE_REGEX, projProps.vsExampleDataType.replace(".", "::"));
        result = result.replaceAll(INCLUDE_DATA_TYPE_PATH_REGEX, projProps.vsExampleDataType.replace(".", "/"));
        result = result.replaceAll(DOMAIN_ID_REGEX, projProps.vsExampleDomainID);
        result = result.replaceAll(PROJ_NAME_REGEX, projectName);
        saveOutputText(result);

    }
}
