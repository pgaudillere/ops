/*
 * Topic.java
 *
 * Created on den 1 februari 2007, 19:07
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;

/**
 *
 * @author Owe
 */
public class Topic<T>
{
    public static final int MC_UDP = 0;
    public static final int MC_TCP = 1;
    public static final int MC = 2;
    public static final int UDP = 3;
    public static final int TCP = 4;
    
    private String name;
    private int port;
    private int replyPort = 0;
    private String typeID;
    private String domainAddress;
    private int transport = MC_UDP;

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


    /** Creates a new instance of Topic */
    public Topic(String name, int port, String typeID, String domainAddress)
    {
        this.name = name;
        this.port = port;
        this.typeID = typeID;
        this.domainAddress = domainAddress;
        
    }
    public Topic()
    {
        
    }

    public String getDomainAddress()
    {
        return domainAddress;
    }

    public void setDomainAddress(String domainAddress)
    {
        this.domainAddress = domainAddress;
    }
    public String toString()
    {
        return name;
    }

    public int getTransport()
    {
        return transport;
    }

    public void setTransport(int transport)
    {
        this.transport = transport;
    }
    
};
