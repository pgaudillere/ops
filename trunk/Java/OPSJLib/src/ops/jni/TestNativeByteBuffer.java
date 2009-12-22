/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops.jni;

/**
 *
 * @author Anton Gravestam
 */
public class TestNativeByteBuffer
{
    public static void main(String[] args)
    {
        byte[] bytes = new byte[20000];
        byte[] bytes2 = new byte[20000];
        NativeByteBuffer buffer = new NativeByteBuffer(bytes, 2000);
        NativeByteBuffer buffer2 = new NativeByteBuffer(bytes, 2000);
        NativeByteBuffer buffer3 = new NativeByteBuffer(bytes2, 2000);

        buffer.writeByte((byte)1);
        buffer2.writeByte((byte)2);
        buffer3.writeByte((byte)3);

        
        System.out.println("" + buffer.getPosition());
        System.out.println("" + buffer2.getPosition());
        System.out.println("" + buffer3.getPosition());
    }

}
