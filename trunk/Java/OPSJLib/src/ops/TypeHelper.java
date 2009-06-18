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
 * @author Anton Gravestam
 */
public class TypeHelper
{
    
    /** Creates a new instance of TypeHelper */
    public TypeHelper()
    {
    }
    
    public int sizeOf(boolean v)
    {
        return 1;
    }
    public int sizeOf(byte v)
    {
        return 1;
    }
    public int sizeOf(int v)
    {
        return 4;
    }
    public int sizeOf(long v)
    {
        return 8;
    }
    public int sizeOf(float v)
    {
        return 4;
    }
    public int sizeOf(double v)
    {
        return 8;
    }
    public int sizeOf(String v)
    {
        return 4 + v.length();
    }
    
}
