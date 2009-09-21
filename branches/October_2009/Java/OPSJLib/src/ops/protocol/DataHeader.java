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
package ops.protocol;

import ops.*;
import ops.OPSObject;

public class DataHeader extends OPSObject
{
public byte messageType;
    public byte endianness;
    public byte publisherPriority;
    public int nrOfSegments;
    public int segment;
    public int port;
    public int dataSize;
    public long qosMask;
    public long publicationID;
    public String publisherID;
    public String topicName;
    public String topLevelKey;
    public String address;
    

    public DataHeader()
    {
        messageType = 0;
        endianness = 0;
        publisherPriority = 0;
        nrOfSegments = 0;
        segment = 0;
        port = 0;
        dataSize = 0;
        qosMask = 0;
        publicationID = 0;
        publisherID = "";
        topicName = "";
        topLevelKey = "";
        address = "";
        
    }
    
}