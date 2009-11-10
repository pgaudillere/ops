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
    public static String SUB_CPP_PATH_REGEX = "__subCppPath";
    public static String PUB_CPP_PATH_REGEX = "__pubCppPath";
    public void compileVSCppExample(String projectDirectory, String projectName, OPSProjectProperties projProps)
    {
        String subCppPath = "";
        String pubCppPath = "";
        String subProjPath = "";
        String pubProjPath = "";
        String slnPath = "";
        String opsConfigPath = "";
        
//        System.out.println("Visual Studio Solution File: " + projectDirectory);
//
//        setOutputFileName(projectDirectory + "/" + "Generated/Visual Studio Examples/" + projectName + "_VS2008_Example.sln");
//        setTemplateFileName("templates/vs_sln.tpl");
//        setTabString("    ");//Default is "\t"
//
//        String result = getTemplateText();
//        result = result.replaceAll(PROJ_NAME_REGEX, projectName);
//        result = result.replaceAll(TOPIC_NAME_REGEX, projProps.vsExampleTopicName);
//        saveOutputText(result);
//
//
//        System.out.println("Visual Studio Subscriber Project File: " + projectDirectory);
//
//        setOutputFileName(projectDirectory + "/" + "Generated/Visual Studio Examples/" + projProps.vsExampleTopicName + "_Subscriber.vcproj");
//        setTemplateFileName("templates/vs_sub_proj.tpl");
//        setTabString("    ");//Default is "\t"
//
//        result = getTemplateText();
//        result = result.replaceAll(PROJ_NAME_REGEX, projectName);
//        result = result.replaceAll(TOPIC_NAME_REGEX, projProps.vsExampleTopicName);
//        result = result.replaceAll(DATA_TYPE_REGEX, projProps.vsExampleDataType);
//        saveOutputText(result);
//
//
//        System.out.println("Visual Studio Publisher Project File: " + projectDirectory);
//
//        setOutputFileName(projectDirectory + "/" + "Generated/Visual Studio Examples/" + projProps.vsExampleTopicName + "_Publisher.vcproj");
//        setTemplateFileName("templates/vs_pub_proj.tpl");
//        setTabString("    ");//Default is "\t"
//
//        result = getTemplateText();
//        result = result.replaceAll(PROJ_NAME_REGEX, projectName);
//        result = result.replaceAll(TOPIC_NAME_REGEX, projProps.vsExampleTopicName);
//        result = result.replaceAll(DATA_TYPE_REGEX, projProps.vsExampleDataType);
//        saveOutputText(result);
//
//
//        System.out.println("Visual Studio Subscriber cpp File: " + projectDirectory);
//
//        setOutputFileName(projectDirectory + "/" + "Generated/Visual Studio Examples/" + projProps.vsExampleTopicName + "_Subscriber.cpp");
//        setTemplateFileName("templates/vs_sub_cpp.tpl");
//        setTabString("    ");//Default is "\t"
//
//        result = getTemplateText();
//        result = result.replaceAll(PROJ_NAME_REGEX, projectName);
//        result = result.replaceAll(TOPIC_NAME_REGEX, projProps.vsExampleTopicName);
//        result = result.replaceAll(DATA_TYPE_REGEX, projProps.vsExampleDataType);
//        saveOutputText(result);
//
//        System.out.println("Visual Studio Publisher cpp File: " + projectDirectory);
//
//        setOutputFileName(projectDirectory + "/" + "Generated/Visual Studio Examples/" + projProps.vsExampleTopicName + "_Publisher.cpp");
//        setTemplateFileName("templates/vs_pub_cpp.tpl");
//        setTabString("    ");//Default is "\t"
//
//        result = getTemplateText();
//        result = result.replaceAll(PROJ_NAME_REGEX, projectName);
//        result = result.replaceAll(TOPIC_NAME_REGEX, projProps.vsExampleTopicName);
//        result = result.replaceAll(DATA_TYPE_REGEX, projProps.vsExampleDataType);
//        saveOutputText(result);



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
}
