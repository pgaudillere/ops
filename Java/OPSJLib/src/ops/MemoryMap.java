/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

/**
 *
 * @author angr
 */
public class MemoryMap
{
    private int width;
	private int height;
	private boolean dataCreator;
	private byte[][] bytes;

    public MemoryMap(int width, int height)
    {
        this.width = width;
        this.height = height;
        bytes = new byte[width][height];
    }
    public MemoryMap(byte[] segment)
    {
        this.width = 1;
        this.height = segment.length;
        bytes = new byte[1][segment.length];

    }
    public byte[] getSegment(int i)
	{
		return bytes[i];
	}
	public int getSegmentSize()
	{
		return height;
	}
	public int getNrOfSegments()
	{
		return width;
	}
	public int getTotalSize()
	{
		return width*height;
	}





}
