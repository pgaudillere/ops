/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package configlib;

import java.io.IOException;

/**
 *
 * @author angr
 */
public interface Serializable
{
    void serialize(ArchiverInOut archive) throws IOException;

}
