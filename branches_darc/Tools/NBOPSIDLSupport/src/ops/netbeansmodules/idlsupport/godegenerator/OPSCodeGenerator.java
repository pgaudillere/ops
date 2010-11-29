/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops.netbeansmodules.idlsupport.godegenerator;

import java.util.Vector;
import ops.OPSConfig;
import parsing.IDLClass;

/**
 *
 * @author Anton Gravestam
 */
public interface OPSCodeGenerator
{
    public Vector<String> compileDataClasses(Vector<IDLClass> idlClasses, String projectOutputDirectory);
    public Vector<String> compileConfig(OPSConfig config, String projectOutputDirectory);
    public void build(String projectOutputDirectory);

}
