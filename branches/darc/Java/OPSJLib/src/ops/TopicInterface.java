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
class TopicInterface 
{
    TopicInterfaceData data;
    long timeLastFed = 0;
    private static long timeout = 3000;

    public TopicInterface(TopicInterfaceData data)
    {
        this.data = data;
        feedWatchdog();
    }

    boolean dataEquals(TopicInterfaceData topicInterfaceData)
    {
        if(data.address.equals(topicInterfaceData.address) &&
           data.port == topicInterfaceData.port &&
           data.topicName.equals(topicInterfaceData.topicName))
        {
            return true;
        }
        return false;
    }

    void feedWatchdog()
    {
        timeLastFed = System.currentTimeMillis();
    }
    boolean isAlive()
    {
        if(System.currentTimeMillis() - timeLastFed < timeout)
        {
            return true;            
        }
        return false;
    }

    TopicInterfaceData getData()
    {
        return data;
    }

}
