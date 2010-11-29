/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package configlib;

/**
 *
 * @author angr
 */
public interface SerializableFactory
{
    Serializable create(String type);
}
