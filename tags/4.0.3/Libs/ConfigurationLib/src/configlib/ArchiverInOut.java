/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package configlib;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author angr
 */
public interface ArchiverInOut
{
    int inout(String name, int v) throws IOException;
    long inout(String name, long v) throws IOException;
    byte inout(String name, byte v) throws IOException;
    short inout(String name, short v) throws IOException;
    float inout(String name, float v) throws IOException;
    boolean inout(String name, boolean v) throws IOException;
    String inout(String name, String v) throws IOException;
    double inout(String name, double v) throws IOException;
    Serializable inout(String name, Serializable v) throws IOException;
    
    List<Integer> inoutIntegerList(String name, List<Integer> v) throws IOException;
    List<Long> inoutLongList(String name, List<Long> v) throws IOException;
    List<Byte> inoutByteList(String name, List<Byte> v) throws IOException;
    List<Short> inoutShortList(String name, List<Short> v) throws IOException;
    List<Float> inoutFloatList(String name, List<Float> v) throws IOException;
    List<Boolean> inoutBooleanList(String name, List<Boolean> v) throws IOException;
    List<String> inoutStringList(String name, List<String> v) throws IOException;
    List<Double> inoutDoubleList(String name, List<Double> v) throws IOException;
    List inoutSerializableList(String name, List v) throws IOException;

}
