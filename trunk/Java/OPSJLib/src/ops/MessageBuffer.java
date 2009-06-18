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
public class MessageBuffer
{
    private byte[] messageBytes;
    private boolean[] fragmentComplete;

    static int fragmentSize = StaticManager.MAX_SIZE;

    public MessageBuffer(int nrFragments)
    {
        messageBytes = new byte[nrFragments * fragmentSize];
        fragmentComplete = new boolean[nrFragments];
    }

    public void addFragment(int fragmentNr, byte[] fragBytes, int dataStart)
    {
        if(!fragmentComplete[fragmentNr])
        {
            int index = fragmentSize * fragmentNr;
            System.arraycopy(fragBytes, dataStart, messageBytes, index, fragBytes.length - dataStart);
            fragmentComplete[fragmentNr] = true;
        }
    }
    public boolean isComplete()
    {
        for (boolean b : fragmentComplete)
        {
            if(!b)
            {
                return false;
            }
        }
        return true;
    }

    public byte[] getBytes()
    {
        return messageBytes;

    }



}
