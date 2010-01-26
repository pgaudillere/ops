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
