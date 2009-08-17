/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.netbeansmodules.idlsupport;

import java.io.IOException;
import java.util.Vector;
import ops.netbeansmodules.idlsupport.compilers.CppCompiler;
import ops.netbeansmodules.idlsupport.compilers.JavaCompiler;
import org.openide.util.Exceptions;
import parsing.IDLClass;

/**
 *
 * @author angr
 */
public class ProjectIDLCompiler
{

    JavaCompiler javaCompiler = new JavaCompiler();
    CppCompiler cppCompiler = new CppCompiler();
    OPSIDLProject project;

    public ProjectIDLCompiler(OPSIDLProject project)
    {
        this.project = project;
    }

    public void compile(Vector<IDLClass> idlClasses)
    {
        cppCompiler.compileDataClasses(idlClasses, project.getProjectDirectory().getPath() + "/Generated/");
        javaCompiler.compileDataClasses(idlClasses, project.getProjectDirectory().getPath() + "/Generated/");

        if (project.getProperties().buildJava)
        {
            try
            {
                javaCompiler.buildAndJar(project.getProjectDirectory().getPath());
            } catch (IOException ex)
            {
                Exceptions.printStackTrace(ex);
            } catch (InterruptedException ex)
            {
                Exceptions.printStackTrace(ex);
            }
        }
        

    }
}
