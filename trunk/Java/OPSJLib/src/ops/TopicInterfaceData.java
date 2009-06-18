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

public class TopicInterfaceData extends OPSObject 
{
    public boolean hasReliableSubscribers;
    public int port;
    public int timebaseSeparation;
    public String address;
    public String topicName;
    public String participantName;
    public java.util.Vector<String> keys;
    public java.util.Vector<String> reliableIdentities;
    

    public TopicInterfaceData()
    {
        hasReliableSubscribers = false;
        port = 0;
        timebaseSeparation = 0;
        address = "";
        topicName = "";
        participantName = "";
        keys = new java.util.Vector<String>();
        reliableIdentities = new java.util.Vector<String>();
        

    }
    public Object clone(){return null;}


}