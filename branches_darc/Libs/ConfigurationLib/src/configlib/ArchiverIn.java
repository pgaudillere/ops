/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package configlib;

import java.util.List;

/**
 *
 * @author angr
 */
public interface ArchiverIn
{
    byte    getByte(String name);
    boolean getBoolean(String name);
    int     getInt(String name);
    short   getShort(String name);
    long    getLong(String name);
    float   getFloat(String name);
    double  getDouble(String name);
    String  getString(String name);
    void    getDeserializable(String name, Deserializable deserializable);
    int     getNrElements(String name);
    Deserializable getElement(String name, int i, Deserializable des);
   
}
