/*
 * WriteByteBuffer.java
 *
 * Created on den 5 november 2007, 09:23
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.List;
import java.util.Vector;

/**
 *
 * @author angr
 */
public class WriteByteBuffer
{
    //private final byte[] buffer;
    final static byte protocolVersionLow  = 5;
    final static byte protocolVersionHigh  = 0;
    final static String protocolID = "opsp";

    private ByteArrayOutputStream baos;
    private DataOutputStream dos;
    /** Creates a new instance of WriteByteBuffer */
    public WriteByteBuffer(DataOutputStream dos)
    {
        this.setDos(dos);
    }
    public WriteByteBuffer()
    {
        baos = new ByteArrayOutputStream();
        setDos(new DataOutputStream(baos));
        this.setDos(getDos());
    }

//    public void writeOPSObjectFields(OPSObject o) throws IOException
//    {
//        dos.writeInt(o.publisherName.length());
//        dos.writeBytes(o.publisherName);
//        dos.writeInt(o.key.length());
//        dos.writeBytes(o.key);
//        dos.writeInt(o.publicationID);
//        dos.writeByte(o.publicationPriority);
//        dos.writeInt(o.typesString.length());
//        dos.writeBytes(o.typesString);
//
//    }
//
//    public void write(OPSObject o, OPSObjectHelper oh) throws IOException
//    {
//        getDos().writeInt(oh.getSize(o));
//        getDos().write(oh.serialize(o));
//
//    }
//    public void writeOPSArr(Vector vec, OPSObjectHelper oh) throws IOException
//    {
//        getDos().writeInt(vec.size());
//        for (int i = 0; i < vec.size(); i++)
//        {
//            write((OPSObject) vec.get(i), oh);
//        }
//
//    }
    public void write(boolean v) throws IOException
    {
        getDos().write((byte)(v ? 1 : 0));     
    }
    public void writebooleanArr(List<Boolean> arr) throws IOException
    {
        write(arr.size());
        for (Boolean v : arr)
        {
            getDos().write((byte)(v.booleanValue() ? 1 : 0));
        }       
    }
    
    public void write(int v) throws IOException
    {
        getDos().writeInt(v);     
    }
    public void writeintArr(List<Integer> arr) throws IOException
    {
        write(arr.size());
        for (Integer v : arr)
        {
            getDos().writeInt(v);
        }       
    }
    public void write(byte v) throws IOException
    {
        getDos().writeByte(v);     
    }
    public void writebyteArr(List<Byte> arr) throws IOException
    {
        write(arr.size());
        for (Byte v : arr)
        {
            getDos().write(v);
        }       
    }
    public void write(long v) throws IOException
    {
        getDos().writeLong(v);     
    }
    public void writelongArr(List<Long> arr) throws IOException
    {
        write(arr.size());
        for (Long v : arr)
        {
            getDos().writeLong(v);
        }       
    }
    public void write(float v) throws IOException
    {
        getDos().writeFloat(v);     
    }
    public void writefloatArr(List<Float> arr) throws IOException
    {
        write(arr.size());
        for (Float v : arr)
        {
            getDos().writeFloat(v);
        }       
    }
    public void write(double v) throws IOException
    {
        getDos().writeDouble(v);     
    }
    public void writedoubleArr(List<Double> arr) throws IOException
    {
        write(arr.size());
        for (Double v : arr)
        {
            getDos().writeDouble(v);
        }       
    }
    public void write(String v) throws IOException
    {
        write(v.length());
        getDos().writeBytes(v);    
    }
    public void writestringArr(List<String> arr) throws IOException
    {
        write(arr.size());
        for (String v : arr)
        {
            write(v);
        }       
    }
    public byte[] getBytes()
    {
        return baos.toByteArray();
    }

    public DataOutputStream getDos()
    {
        return dos;
    }

    public void setDos(DataOutputStream dos)
    {
        this.dos = dos;
    }

    void writeProtocol() throws IOException
    {
        dos.write(protocolID.getBytes());
        dos.writeByte(protocolVersionLow);
        dos.writeByte(protocolVersionHigh);
    }
    
}
