/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.netbeansmodules.idlsupport;

import java.util.Vector;
import ops.netbeansmodules.idlsupport.compilers.CppCompiler;
import ops.netbeansmodules.idlsupport.compilers.JavaCompiler;
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
        javaCompiler.compileDataClasses(idlClasses, project.getProjectDirectory().getPath() + "/Generated/");
        cppCompiler.compileDataClasses(idlClasses, project.getProjectDirectory().getPath() + "/Generated/");

    }
}
