/*
 * FilterQoSPolicy.java
 *
 * Created on den 10 oktober 2007, 10:30
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;

/**
 *
 * @author angr
 */
public interface FilterQoSPolicy
{
    
    /** Creates a new instance of FilterQoSPolicy */
    public boolean applyFilter(OPSObject o);
    
}
