/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.netbeansmodules.idlsupport.compilers;

import java.io.IOException;
import java.io.InputStream;
import java.util.Vector;
import javax.swing.JOptionPane;
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
        String vsExampleTopicName = projProps.getPropertyValue("vsExampleTopicName", "");

        String subCppPath = projectDirectory + "/" + "Generated/Visual Studio Examples/" + vsExampleTopicName  + "/" + vsExampleTopicName + "_sub.cpp";
        String pubCppPath = projectDirectory + "/" + "Generated/Visual Studio Examples/" + vsExampleTopicName  + "/" + vsExampleTopicName + "_pub.cpp";
        String subProjPath = projectDirectory + "/" + "Generated/Visual Studio Examples/" + vsExampleTopicName  + "/" + vsExampleTopicName + "_sub.vcproj";
        String pubProjPath = projectDirectory + "/" + "Generated/Visual Studio Examples/" + vsExampleTopicName  + "/" + vsExampleTopicName + "_pub.vcproj";
        String slnPath = projectDirectory + "/" + "Generated/Visual Studio Examples/" + vsExampleTopicName + "/" + vsExampleTopicName + "_example.sln";
        String opsConfigPath = "";
        

        try
        {
            createFile(slnPath, "/ops/netbeansmodules/idlsupport/templates/vs_sln.tpl", projectName, projProps);
            createFile(pubProjPath, "/ops/netbeansmodules/idlsupport/templates/vs_pub_proj.tpl", projectName, projProps);
            createFile(subProjPath, "/ops/netbeansmodules/idlsupport/templates/vs_sub_proj.tpl", projectName, projProps);
            createFile(pubCppPath, "/ops/netbeansmodules/idlsupport/templates/vs_pub_cpp.tpl", projectName, projProps);
            createFile(subCppPath, "/ops/netbeansmodules/idlsupport/templates/vs_sub_cpp.tpl", projectName, projProps);
        } catch (IOException iOException)
        {
            JOptionPane.showMessageDialog(null, "Generating Visual Studio Example failed with the following exception: " + iOException.getMessage());
        }

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

    private void createFile(String slnPath, String tplPath, String projectName, OPSProjectProperties projProps) throws IOException
    {
        setOutputFileName(slnPath);
        String resource = tplPath;
        setTemplateTextFromResource(resource);
        //setTemplateFileName(tplPath);
        setTabString("    "); //Default is "\t"

        String vsExampleTopicName = projProps.getPropertyValue("vsExampleTopicName", "");
        String vsExampleDataType = projProps.getPropertyValue("vsExampleDataType", "");
        String vsExampleDomainID = projProps.getPropertyValue("vsExampleDomainID", "");
        

        String result = getTemplateText();
        result = result.replaceAll(TOPIC_NAME_REGEX, vsExampleTopicName);
        result = result.replaceAll(DATA_TYPE_REGEX, vsExampleDataType.replace(".", "::"));
        result = result.replaceAll(INCLUDE_DATA_TYPE_PATH_REGEX, vsExampleDataType.replace(".", "/"));
        result = result.replaceAll(DOMAIN_ID_REGEX, vsExampleDomainID);
        result = result.replaceAll(PROJ_NAME_REGEX, projectName);
        saveOutputText(result);

    }

    protected void setTemplateTextFromResource(String resource) throws IOException
    {
        InputStream templateStream = this.getClass().getResourceAsStream(resource);
        byte[] templateBytes = new byte[templateStream.available()];
        templateStream.read(templateBytes);
        setTemplateText(new String(templateBytes));
    }
}
