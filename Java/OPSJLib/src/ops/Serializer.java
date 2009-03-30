
/*
 * Serializer.java
 *
 * Created on den 11 maj 2007, 18:35
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;



/**
 *
 * @author Anton Gravestam
 */
public interface Serializer
{
    public byte[] serialize(OPSObject o);
    public OPSObject deserialize(byte[] b);
    
    
    
}
