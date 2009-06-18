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

import ops.OPSObject;

public class HeartBeat extends OPSObject
{
public byte messageType;
    public byte endianness;
    public int highestSegment;
    public int port;
    public long qosMask;
    public long highestPublicationID;
    public String subscriberID;
    public String topicName;
    public String topLevelKey;
    public String address;
    

    public HeartBeat()
    {
messageType = 0;
        endianness = 0;
        highestSegment = 0;
        port = 0;
        qosMask = 0;
        highestPublicationID = 0;
        subscriberID = "";
        topicName = "";
        topLevelKey = "";
        address = "";
        
    }
   
}