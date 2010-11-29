
package configlib;

import java.io.IOException;
import java.util.Collection;
import java.util.List;

/**
 *
 * @author Anton Gravestam
 */
public interface ArchiverOut 
{
    void put(String name, SerializableOld v) throws IOException;
    void put(String name, String v) throws IOException;
    void put(String name, byte v) throws IOException;
    void put(String name, boolean v) throws IOException;
    void put(String name, double v) throws IOException;
    void put(String name, float v) throws IOException;
    void put(String name, int v) throws IOException;
    void put(String name, long v) throws IOException;
    void put(String name, short v) throws IOException;
    void put(String name, List<? extends SerializableOld> collection) throws IOException;
    void putBytes(String name, List<Byte> collection) throws IOException;
    void putInts(String name, List<Integer> collection) throws IOException;
    void putDoubles(String name, List<Double> collection) throws IOException;
    void putFloats(String name, List<Float> collection) throws IOException;
    void putShorts(String name, List<Short> collection) throws IOException;
    void putLongs(String name, List<Long> collection) throws IOException;
    void putStrings(String name, List<String> collection) throws IOException;

}
