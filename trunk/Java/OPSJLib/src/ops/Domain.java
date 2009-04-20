/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

import configlib.ArchiverInOut;
import java.io.IOException;
import java.util.Vector;

/**
 *
 * @author angr
 */
public class Domain extends OPSObject
{
    protected Vector<Topic> topics = new Vector<Topic>();
    private String domainID = "";

    public Domain()
    {
        appendType("Domain");
    }


    public Vector<Topic> getTopics()
    {
        return topics;
    }

    public String getDomainID()
    {
        return domainID;
    }

    public void setDomainID(String domainID)
    {
        this.domainID = domainID;
    }
    

    public Topic getTopic(String name)
    {
        for (Topic topic : topics)
        {
            if(topic.getName().equals(name))
            {
                return topic;
            }
        }
        return null;
    }
    public boolean existTopic(String name)
    {
        for (Topic topic : topics)
        {
            if(topic.getName().equals(name))
            {
                return true;
            }
        }
        return false;
    }

    @Override
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
        domainID = archive.inout("domainID", domainID);
        topics = (Vector<Topic>) archive.inoutSerializableList("topics", topics);
    }


}
