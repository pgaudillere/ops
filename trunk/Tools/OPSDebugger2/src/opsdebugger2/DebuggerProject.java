/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package opsdebugger2;

import configlib.exception.FormatException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import opsreflection.OPSFactory;

/**
 *
 * @author angr
 */
public class DebuggerProject
{
    private OPSFactory opsFactory;

    File projectHome = new File("");

    public DebuggerProject(File projectHome) throws FileNotFoundException, FormatException, IOException
    {
        this.projectHome = projectHome;
        opsFactory = new OPSFactory(projectHome);
    }

    public File getProjectHome()
    {
        return projectHome;
    }

    public void setProjectHome(File projectHome)
    {
        this.projectHome = projectHome;
    }




    String getDomainAddress()
    {
        return null;
    }
    public OPSFactory getOPSFactory()
    {
        return opsFactory;
    }

}
