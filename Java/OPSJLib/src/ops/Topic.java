/*
 * Topic.java
 *
 * Created on den 1 februari 2007, 19:07
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;

import configlib.ArchiverInOut;
import java.io.IOException;

/**
 *
 * @author Owe
 */
public class Topic<T> extends OPSObject
{
   
    private String name = "";
    private int port = -1;
    private int replyPort = 0;
    private String typeID = "";
    private String domainAddress = "";
    private int sampleMaxSize = StaticManager.MAX_SIZE;

    

    /** Creates a new instance of Topic */
    public Topic(String name, int port, String typeID, String domainAddress)
    {
        this.name = name;
        this.port = port;
        this.typeID = typeID;
        this.domainAddress = domainAddress;
        this.sampleMaxSize = StaticManager.MAX_SIZE;
        appendType("Topic");
        
    }
    public Topic()
    {
        appendType("Topic");
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
    public String toString()
    {
        return name;
    }

    public int getReplyPort()
    {
        return replyPort;
    }

    public int getPort()
    {
        return port;
    }

    public String getName()
    {
        return name;
    }

    public String getTypeID()
    {
        return typeID;
    }

    protected void setReplyPort(int replyPort)
    {
        this.replyPort = replyPort;
    }

    public void setTypeID(String typeID)
    {
        this.typeID = typeID;
    }

    public void setPort(int port)
    {
        this.port = port;
    }

    public void setName(String name)
    {
        this.name = name;
    }


    @Override
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
        name = archive.inout("name", name);
        typeID = archive.inout("dataType", typeID);
        port = archive.inout("port", port);
        domainAddress = archive.inout("address", domainAddress);

        //sampleMaxSize will be ignored for now.


    }

    
};
