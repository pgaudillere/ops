/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops.netbeansmodules.idlsupport.godegenerator;

import java.util.ArrayList;
import ops.OPSConfig;

/**
 *
 * @author Anton Gravestam
 */
public interface OPSConfigCompiler
{
    public ArrayList<String> compileConfig(OPSConfig config, String projectDirectory);

}
