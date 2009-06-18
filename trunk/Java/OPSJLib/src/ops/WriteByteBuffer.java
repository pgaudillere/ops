/**
*
* Copyright (C) 2006-2009 Anton Gravestam.
*
* This file is part of OPS (Open Publish Subscribe).
*
* OPS (Open Publish Subscribe) is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* OPS (Open Publish Subscribe) is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with OPS (Open Publish Subscribe).  If not, see <http://www.gnu.org/licenses/>.
*/

package ops;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.List;

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

    //private ByteArrayOutputStream baos;
    //private DataOutputStream dos;

    ByteBuffer outBuffer;

    /** Creates a new instance of WriteByteBuffer */
    public WriteByteBuffer(byte[] bytes)
    {
        outBuffer = ByteBuffer.wrap(bytes);
        outBuffer.order(ByteOrder.LITTLE_ENDIAN); //Only default value, this should be dynamic in future OPS
    }

    public static byte[] putSegmentInfo(byte[] bytes, int segmentSize, int headerSize) throws IOException
    {
        int nrOfSegments = bytes.length / segmentSize;
        if(bytes.length % segmentSize != 0) nrOfSegments++;
        byte[] result = new byte[bytes.length + nrOfSegments * headerSize];

        WriteByteBuffer buf = new WriteByteBuffer(result);
        for (int i = 0; i < nrOfSegments; i++)
        {
            buf.write(nrOfSegments);
            buf.write(i);
            buf.writeProtocol();
            buf.write(bytes, i*segmentSize, segmentSize - headerSize);
        }
        return result;
    }

    private void write(byte[] bytes, int start, int size)
    {
        outBuffer.put(bytes, start, size);
    }

    public final ByteBuffer order(ByteOrder bo)
    {
        return outBuffer.order(bo);
    }

    public final ByteOrder order()
    {
        return outBuffer.order();
    }


//    public WriteByteBuffer()
//    {
//        baos = new ByteArrayOutputStream();
//        setDos(new DataOutputStream(baos));
//        this.setDos(getDos());
//    }


    public void write(boolean v) throws IOException
    {
        //getDos().write((byte)(v ? 1 : 0));
        outBuffer.put((byte)(v ? 1 : 0));
    }
    public void writebooleanArr(List<Boolean> arr) throws IOException
    {
        write(arr.size());
        for (Boolean v : arr)
        {
            write(v);
        }       
    }
    
    public void write(int v) throws IOException
    {
        //getDos().writeInt(v);
        outBuffer.putInt(v);
    }
    public void writeintArr(List<Integer> arr) throws IOException
    {
        write(arr.size());
        for (Integer v : arr)
        {
            write(v);
        }

    }
    public void write(byte v) throws IOException
    {
        outBuffer.put(v);
    }
    public void writebyteArr(List<Byte> arr) throws IOException
    {
        write(arr.size());
        for (Byte v : arr)
        {
            write(v);
        }       
    }
    public void write(long v) throws IOException
    {
        //getDos().writeLong(v);
        outBuffer.putLong(v);
    }
    public void writelongArr(List<Long> arr) throws IOException
    {
        write(arr.size());
        for (Long v : arr)
        {
            write(v);
        }       
    }
    public void write(float v) throws IOException
    {
        outBuffer.putFloat(v);
    }
    public void writefloatArr(List<Float> arr) throws IOException
    {
        write(arr.size());
        for (Float v : arr)
        {
            write(v);
        }       
    }
    public void write(double v) throws IOException
    {
        outBuffer.putDouble(v);
    }
    public void writedoubleArr(List<Double> arr) throws IOException
    {
        write(arr.size());
        for (Double v : arr)
        {
            write(v);
        }       
    }
    public void write(String v) throws IOException
    {
        write(v.length());
        //getDos().writeBytes(v);
        outBuffer.put(v.getBytes());
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
        return outBuffer.array();
    }

//    public DataOutputStream getDos()
//    {
//        return dos;
//    }
//
//    public void setDos(DataOutputStream dos)
//    {
//        this.dos = dos;
//    }

    void writeProtocol() throws IOException
    {
        outBuffer.put(protocolID.getBytes());
        write(protocolVersionLow);
        write(protocolVersionHigh);
    }


    
}
