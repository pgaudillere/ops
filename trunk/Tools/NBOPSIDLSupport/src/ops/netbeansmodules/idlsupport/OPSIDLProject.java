/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.netbeansmodules.idlsupport;

import java.beans.PropertyChangeListener;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import org.netbeans.api.project.Project;
import org.netbeans.api.project.ProjectInformation;
import org.netbeans.spi.project.ActionProvider;
import org.netbeans.spi.project.ProjectState;
import org.netbeans.spi.project.ui.LogicalViewProvider;
import org.openide.filesystems.FileObject;
import org.openide.util.Exceptions;
import org.openide.util.ImageUtilities;
import org.openide.util.Lookup;
import org.openide.util.NbBundle;
import org.openide.util.lookup.Lookups;
import org.openide.windows.IOProvider;
import org.openide.windows.InputOutput;

/**
 *
 * @author angr
 */
public class OPSIDLProject implements Project
{

    public static final String SRC_DIR = "src";
    public static final String TOPIC_CONFIG_DIR = "topicconfig";
    private FileObject projectDir;
    private ProjectState state;
    LogicalViewProvider logicalView = new OPSIDLProjectLogicalView(this);
    ProjectIDLParser projectIDLParser = new ProjectIDLParser();
    ProjectIDLCompiler projectIDLCompiler = new ProjectIDLCompiler(this);

    public OPSIDLProject(FileObject projectDir, ProjectState state)
    {
        this.projectDir = projectDir;
        this.state = state;
    }

    FileObject getSourceFolder(boolean create)
    {
        FileObject result =
                projectDir.getFileObject(SRC_DIR);

        if (result == null && create)
        {
            try
            {
                result = projectDir.createFolder(SRC_DIR);
            } catch (IOException ioe)
            {
                Exceptions.printStackTrace(ioe);
            }
        }
        return result;
    }

    FileObject getTopicConfigFolder(boolean create)
    {
        FileObject result =
                projectDir.getFileObject(TOPIC_CONFIG_DIR);
        if (result == null && create)
        {
            try
            {
                result = projectDir.createFolder(TOPIC_CONFIG_DIR);
            } catch (IOException ioe)
            {
                Exceptions.printStackTrace(ioe);
            }
        }
        return result;
    }

    public FileObject getProjectDirectory()
    {
        return projectDir;
    }
    private Lookup lkp;

    public Lookup getLookup()
    {
        if (lkp == null)
        {
            lkp = Lookups.fixed(new Object[]
                    {
                        this, //project spec requires a project be in its own lookup
                        state, //allow outside code to mark the project as needing saving
                        new ActionProviderImpl(this), //Provides standard actions like Build and Clean
                        loadProperties(), //The project properties
                        new Info(), //Project information implementation
                        logicalView, //Logical view of project implementation
                    });
        }
        return lkp;
    }

    private String getName()
    {
        return new Info().getDisplayName();
    }

    private void iterateFileObject(FileObject sourceFolder)
    {
        for (FileObject fileObject : sourceFolder.getChildren())
        {
            if(fileObject.isFolder())
            {
                System.out.println("Folder " + fileObject.getName());
                iterateFileObject(fileObject);
            }
            else if(fileObject.getExt().toLowerCase().equals("idl"))
            {
                try
                {
                    int size = fileObject.getInputStream().available();
                    byte[] textBytes = new byte[size];
                    fileObject.getInputStream().read(textBytes);
                    projectIDLParser.parse(fileObject.getName(), new String(textBytes));
                    
                } catch (IOException ex)
                {
                    Exceptions.printStackTrace(ex);
                }
            }
        }
    }

    private void iterateFiles()
    {
        projectIDLParser.reset();
        iterateFileObject(getSourceFolder(false));
        if(projectIDLParser.getNrErrors() > 0)
        {
            InputOutput io = IOProvider.getDefault().getIO("OPS Build", false);
            io.getErr().println("Project parsing failed with " + projectIDLParser.getNrErrors() + " errors.");
        }
        else
        {
            InputOutput io = IOProvider.getDefault().getIO("OPS Build", false);
            io.getOut().println("Parsing successful.");
            projectIDLCompiler.compile(projectIDLParser.getIdlClasses());
        }
    }

    private Properties loadProperties()
    {
        FileObject fob = projectDir.getFileObject(OPSIDLProjectFactory.PROJECT_DIR +
                "/" + OPSIDLProjectFactory.PROJECT_PROPFILE);
        Properties properties = new NotifyProperties(state);
        if (fob != null)
        {
            try
            {
                properties.load(fob.getInputStream());
            } catch (Exception e)
            {
                Exceptions.printStackTrace(e);
            }
        }
        return properties;
    }

    private static class NotifyProperties extends Properties
    {

        private final ProjectState state;

        NotifyProperties(ProjectState state)
        {
            this.state = state;
        }

        @Override
        public Object put(Object key, Object val)
        {
            Object result = super.put(key, val);
            if (((result == null) != (val == null)) || (result != null &&
                    val != null && !val.equals(result)))
            {
                state.markModified();
            }
            return result;
        }
    }

    private final class ActionProviderImpl implements ActionProvider
    {
        private OPSIDLProject project;

        private ActionProviderImpl(OPSIDLProject project)
        {
            this.project = project;
        }



        public String[] getSupportedActions()
        {
            return new String[]
                    {
                        "build", "run", "CTL_GenerateCode"
                    };
        }

        public void invokeAction(String string, Lookup lookup) throws IllegalArgumentException
        {
            try
            {
                //do nothing
                InputOutput io = IOProvider.getDefault().getIO("OPS Build", false);
                io.getOut().reset();
                io.select();
                io.getOut().println("Starting build... of " + project.getName() );
                io.getErr().println("Build is not yet implemented.");

                project.iterateFiles();

            } catch (IOException ex)
            {
                Exceptions.printStackTrace(ex);
            }

        }

        /**
         *
         * @param string ska vara "hej"
         * @param lookup är en banan
         * @return
         * @throws java.lang.IllegalArgumentException
         */
        public boolean isActionEnabled(String string, Lookup lookup) throws IllegalArgumentException
        {
            return string.equals("build");
        }
    }

    /** Implementation of project system's ProjectInformation class */
    private final class Info implements ProjectInformation
    {

        public Icon getIcon()
        {
            return new ImageIcon(ImageUtilities.loadImage(
                    "ops/netbeansmodules/idlsupport/opsprojecticon.GIF"));
        }

        /**
         *
         * @return
         */
        public String getName()
        {
            return getProjectDirectory().getName();
        }

        public String getDisplayName()
        {
            return getName();
        }

        public void addPropertyChangeListener(PropertyChangeListener pcl)
        {
            //do nothing, won't change
        }

        /**
         * 
         * @param pcl
         */
        public void removePropertyChangeListener(PropertyChangeListener pcl)
        {
            //do nothing, won't change
        }

        public Project getProject()
        {
            return OPSIDLProject.this;
        }
    }
}
