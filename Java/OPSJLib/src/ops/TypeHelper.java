/*
 * TypeHelper.java
 *
 * Created on den 24 november 2007, 15:22
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;

/**
 *
 * @author Anton Gravestam
 */
public class TypeHelper
{
    
    /** Creates a new instance of TypeHelper */
    public TypeHelper()
    {
    }
    
    public int sizeOf(boolean v)
    {
        return 1;
    }
    public int sizeOf(byte v)
    {
        return 1;
    }
    public int sizeOf(int v)
    {
        return 4;
    }
    public int sizeOf(long v)
    {
        return 8;
    }
    public int sizeOf(float v)
    {
        return 4;
    }
    public int sizeOf(double v)
    {
        return 8;
    }
    public int sizeOf(String v)
    {
        return 4 + v.length();
    }
    
}
