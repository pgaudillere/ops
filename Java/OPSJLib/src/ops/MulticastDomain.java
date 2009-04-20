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
public class MulticastDomain extends Domain
{
    private String domainAddress = "";

    public MulticastDomain()
    {
        appendType("MulticastDomain");
    }



    public String getDomainAddress()
    {
        return domainAddress;
    }

    public void setDomainAddress(String domainAddress)
    {
        this.domainAddress = domainAddress;
    }

   
    @Override
    public Vector<Topic> getTopics()
    {
        for (Topic topic : topics)
        {
            if(topic.getDomainAddress().equals(""))
            {
                topic.setDomainAddress(domainAddress);
            }
        }
        return super.getTopics();
    }

    @Override
    public Topic getTopic(String name)
    {
        for (Topic topic : topics)
        {
            if(topic.getDomainAddress().equals(""))
            {
                topic.setDomainAddress(domainAddress);
            }
            if(topic.getName().equals(name))
            {
                return topic;
            }
        }
        return null;
    }

    @Override
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
        domainAddress = archive.inout("domainAddress", domainAddress);
    }




}
