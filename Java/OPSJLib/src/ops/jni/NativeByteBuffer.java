/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops.jni;

/**
 *
 * @author Anton Gravestam
 */
public class NativeByteBuffer
{
    private final int segmentSize;


    public NativeByteBuffer(byte[] buffer, int segmentSize)
    {
        this.segmentSize = segmentSize;
        initialize(buffer, segmentSize);
    }
    private native int getPosition();
    private native void initialize(byte[] buffer, int segmentSize);
    
    public native void writeByte(byte b);
    public native void writeInt(int i);
    public native void writeLong(long i);
    public native void writeShort(short s);
    public native void writeFloat(float f);
    public native void writeDouble(double d);
    public native void writeString(byte[] b);

    public native void writeBytes(byte[] b);
    public native void writeInts(int[] i);
    public native void writeLongs(long[] i);
    public native void writeShorts(short[] s);
    public native void writeFloats(float[] f);
    public native void writeDoubles(double[] d);

    public native byte readByte();
    public native int readInt();
    public native short readShort();
    public native long readLong();
    public native float readFloat();
    public native double readDouble();

    public native void readBytes(byte[] b);
    public native void readInts(int[] i);
    public native void readLongs(long[] i);
    public native void readShorts(short[] s);
    public native void readFloats(float[] f);
    public native void readDoubles(double[] d);
    public native void readString(byte[] d);

}
