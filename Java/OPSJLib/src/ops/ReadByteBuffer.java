/*
 * ReadByteBuffer.java
 *
 * Created on den 5 november 2007, 09:50
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;

import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.util.List;
import java.util.Vector;

/**
 *
 * @author angr
 */
public class ReadByteBuffer
{
    final static byte protocolVersionLow  = 5;
    final static byte protocolVersionHigh  = 0;
    final static String protocolID = "opsp";

    private DataInputStream dis;

    
    
    /** Creates a new instance of ReadByteBuffer */
    public ReadByteBuffer(DataInputStream dis)
    {
        this.setDis(dis);
    }
    public ReadByteBuffer(byte[] buf)
    {
        ByteArrayInputStream bais = new ByteArrayInputStream(buf);
        this.setDis(new DataInputStream(bais));
    }
        
    
//    public OPSObject readOPSObject(OPSObjectHelper oh) throws IOException
//    {
//        int size = getDis().readInt();
//        byte[] bytes = new byte[size];
//        getDis().read(bytes);
//        return oh.deserialize(bytes);
//    }
//    public void readOPSObjectArr(Vector vec, OPSObjectHelper oh) throws IOException
//    {
//        int size = getDis().readInt();
//        for (int i = 0; i <size; i++)
//        {
//            vec.add(readOPSObject(oh));
//
//        }
//    }
    public boolean readboolean() throws IOException
    {
        return getDis().readByte() > 0;
    }
    public List<Boolean> readbooleanArr() throws IOException
    {
        int size = readint();
        Vector<Boolean> ret = new Vector<Boolean>();
        for (int i = 0; i < size ; i++)
        {
            ret.add(new Boolean(readboolean()));            
        }
        return ret;
    }
    public byte readbyte() throws IOException
    {
        return getDis().readByte();
    }
    public List<Byte> readbyteArr() throws IOException
    {
        int size = readint();
        Vector<Byte> ret = new Vector<Byte>();
        for (int i = 0; i < size ; i++)
        {
            ret.add(new Byte(readbyte()));            
        }
        return ret;
    }
    public int readint() throws IOException
    {
        return getDis().readInt();
    }
    public List<Integer> readintArr() throws IOException
    {
        int size = readint();
        Vector<Integer> ret = new Vector<Integer>();
        for (int i = 0; i < size ; i++)
        {
            ret.add(new Integer(readint()));            
        }
        return ret;
    }
    public long readlong() throws IOException
    {
        return getDis().readLong();
    }
    public List<Long> readlongArr() throws IOException
    {
        int size = readint();
        Vector<Long> ret = new Vector<Long>();
        for (int i = 0; i < size ; i++)
        {
            ret.add(new Long(readlong()));            
        }
        return ret;
    }
    public float readfloat() throws IOException
    {
        return getDis().readFloat();
    }
    public List<Float> readfloatArr() throws IOException
    {
        int size = readint();
        Vector<Float> ret = new Vector<Float>();
        for (int i = 0; i < size ; i++)
        {
            ret.add(new Float(readfloat()));            
        }
        return ret;
    }
    public double readdouble() throws IOException
    {
        return getDis().readDouble();
    }
    public List<Double> readdoubleArr() throws IOException
    {
        int size = readint();
        Vector<Double> ret = new Vector<Double>();
        for (int i = 0; i < size ; i++)
        {
            ret.add(new Double(readdouble()));            
        }
        return ret;
    }
    public String readstring() throws IOException
    {
        int size = readint();
        byte[] bytes = new byte[size];
        getDis().read(bytes);
        return new String(bytes); 
    }
    public List<String> readstringArr() throws IOException
    {
        int size = readint();
        Vector<String> ret = new Vector<String>();
        for (int i = 0; i < size ; i++)
        {
            ret.add(readstring());            
        }
        return ret;
    }

    public DataInputStream getDis()
    {
        return dis;
    }

    public void setDis(DataInputStream dis)
    {
        this.dis = dis;
    }

    boolean checkProtocol() throws IOException
    {
        byte[] prtIDBytes = new byte[4];
        dis.read(prtIDBytes);
        String prtID = new String(prtIDBytes);
        if(prtID.equals(protocolID))
        {
            byte verLow = dis.readByte();
            byte verHigh = dis.readByte();
            if(verHigh == protocolVersionHigh && verLow == protocolVersionLow)
            {
                return true;
            }
            return false;
        }
        return false;

    }
    
}
