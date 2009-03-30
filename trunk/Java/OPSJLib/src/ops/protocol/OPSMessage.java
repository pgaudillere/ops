/*
 * OPSMessage.java
 *
 * Created on den 29 september 2007, 12:16
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops.protocol;

import configlib.ArchiverInOut;
import java.io.IOException;
import ops.*;

/**
 *
 * @author Anton Gravestam
 */
public class OPSMessage extends OPSObject
{
    private byte messageType;
    private byte  endianness;
    private byte publisherPriority;
    private int port;
    private long qosMask;
    private long publicationID;
    private String publisherName = "";
    private String topicName = "";
    private String topLevelKey = "";
    private String address = "";
    private OPSObject data;

    /** Creates a new instance of OPSMessage */
    public OPSMessage()
    {
        super();
        appendType("ops.protocol.OPSMessage");
    }

    public String getAddress()
    {
        return address;
    }

    public void setAddress(String address)
    {
        this.address = address;
    }

    public OPSObject getData()
    {
        return data;
    }

    public void setData(OPSObject data)
    {
        this.data = data;
    }

    public byte getEndianness()
    {
        return endianness;
    }

    public void setEndianness(byte endianness)
    {
        this.endianness = endianness;
    }

    public byte getMessageType()
    {
        return messageType;
    }

    public void setMessageType(byte messageType)
    {
        this.messageType = messageType;
    }

    public int getPort()
    {
        return port;
    }

    public void setPort(int port)
    {
        this.port = port;
    }

    public long getPublicationID()
    {
        return publicationID;
    }

    public void setPublicationID(long publicationID)
    {
        this.publicationID = publicationID;
    }

    public String getPublisherName()
    {
        return publisherName;
    }

    public void setPublisherName(String publisherName)
    {
        this.publisherName = publisherName;
    }

    public byte getPublisherPriority()
    {
        return publisherPriority;
    }

    public void setPublisherPriority(byte publisherPriority)
    {
        this.publisherPriority = publisherPriority;
    }

    public long getQosMask()
    {
        return qosMask;
    }

    public void setQosMask(long qosMask)
    {
        this.qosMask = qosMask;
    }

    public String getTopLevelKey()
    {
        return topLevelKey;
    }

    public void setTopLevelKey(String topLevelKey)
    {
        this.topLevelKey = topLevelKey;
    }

    public String getTopicName()
    {
        return topicName;
    }

    public void setTopicName(String topicName)
    {
        this.topicName = topicName;
    }

    @Override
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
        messageType = archive.inout("messageType", messageType);
        publisherPriority = archive.inout("publisherPriority", publisherPriority);
        publicationID = archive.inout("publicationID", publicationID);
        publisherName = archive.inout("publisherName", publisherName);
        topicName = archive.inout("topicName", topicName);
        topLevelKey = archive.inout("topLevelKey", topLevelKey);
        address = archive.inout("address", address);
        data = (OPSObject) archive.inout("data", data);

    }
    
}
