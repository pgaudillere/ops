/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.netbeansmodules.idlsupport;

import configlib.XMLArchiverIn;

import configlib.XMLArchiverOut;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import org.netbeans.api.project.Project;
import org.netbeans.spi.project.ProjectFactory;
import org.netbeans.spi.project.ProjectState;
import org.openide.filesystems.FileObject;

/**
 *
 * @author angr
 */
public class OPSIDLProjectFactory implements ProjectFactory
{
    public static final String PROJECT_DIR = "opsproject";
    public static final String PROJECT_PROPFILE = "project.properties";

    public boolean isProject(FileObject projectDirectory)
    {
        return projectDirectory.getFileObject(PROJECT_DIR) != null;
    }

    public Project loadProject(FileObject dir, ProjectState state) throws IOException
    {
        return isProject (dir) ? new OPSIDLProject(dir, state) : null;

    }

    public void saveProject(Project project) throws IOException, ClassCastException
    {
        File outFile = new File(project.getProjectDirectory().getPath() +  "/" + PROJECT_DIR + "/" + PROJECT_PROPFILE);
        XMLArchiverOut archiver = new XMLArchiverOut(new FileOutputStream(outFile));

        archiver.inout("properties", ((OPSIDLProject)project).getProperties());

        
    }
}
