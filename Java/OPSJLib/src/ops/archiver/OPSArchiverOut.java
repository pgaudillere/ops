/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops.archiver;

import configlib.ArchiverInOut;
import configlib.Serializable;
import configlib.SerializableCompositeFactory;
import configlib.SerializableFactory;
import java.io.IOException;
import java.util.List;
import ops.OPSObject;
import ops.WriteByteBuffer;

/**
 *
 * @author angr
 */
public class OPSArchiverOut implements ArchiverInOut
{
    WriteByteBuffer writeBuf;
//
//    public OPSArchiverOut()
//    {
//        writeBuf = new WriteByteBuffer();
//    }

    public OPSArchiverOut(WriteByteBuffer buf)
    {
        this.writeBuf = buf;
    }
    public byte[] getBytes()
    {
        return writeBuf.getBytes();
    }

    public int inout(String name, int v) throws IOException
    {
        writeBuf.write(v);
        return v;
    }

    public long inout(String name, long v) throws IOException
    {
        writeBuf.write(v);
        return v;
    }

    public byte inout(String name, byte v) throws IOException
    {
        writeBuf.write(v);
        return v;
    }

    public short inout(String name, short v) throws IOException
    {
        writeBuf.write(v);
        return v;
    }

    public float inout(String name, float v) throws IOException
    {
        writeBuf.write(v);
        return v;
    }

    public boolean inout(String name, boolean v) throws IOException
    {
        writeBuf.write(v);
        return v;
    }

    public String inout(String name, String v) throws IOException
    {
        writeBuf.write(v);
        return v;
    }

    public double inout(String name, double v) throws IOException
    {
        writeBuf.write(v);
        return v;
    }

    public Serializable inout(String name, Serializable v) throws IOException
    {
        writeBuf.write(((OPSObject)v).getTypesString());
        v.serialize(this);
        return v;
    }

   
    public List<Integer> inoutIntegerList(String name, List<Integer> v) throws IOException
    {
        writeBuf.writeintArr(v);
        return v;
    }

    public List<Long> inoutLongList(String name, List<Long> v) throws IOException
    {
        writeBuf.writelongArr(v);
        return v;
    }

    public List<Byte> inoutByteList(String name, List<Byte> v) throws IOException
    {
        writeBuf.writebyteArr(v);
        return v;
    }

    public List<Short> inoutShortList(String name, List<Short> v) throws IOException
    {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public List<Float> inoutFloatList(String name, List<Float> v) throws IOException
    {
        writeBuf.writefloatArr(v);
        return v;
    }

    public List<Boolean> inoutBooleanList(String name, List<Boolean> v) throws IOException
    {
        writeBuf.writebooleanArr(v);
        return v;
    }

    public List<String> inoutStringList(String name, List<String> v) throws IOException
    {
        writeBuf.writestringArr(v);
        return v;
    }

    public List<Double> inoutDoubleList(String name, List<Double> v) throws IOException
    {
        writeBuf.writedoubleArr(v);
        return v;
    }

    public List inoutSerializableList(String name, List v) throws IOException
    {
        writeBuf.write(v.size());
        for (int i = 0; i < v.size(); i++)
        {
            writeBuf.write(((OPSObject)v.get(i)).getTypesString());
            ((Serializable)v.get(i)).serialize(this);
        }
        return v;
    }

}
