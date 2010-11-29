/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops.netbeansmodules.idlsupport.godegenerator;

import java.util.Vector;
import parsing.IDLClass;

/**
 *
 * @author Anton Gravestam
 */
public interface OPSDataClassCompiler
{
    public Vector<String> compileDataClasses(Vector<IDLClass> idlClasses, String projectOutputDirectory);
}
