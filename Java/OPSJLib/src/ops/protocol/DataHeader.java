//Auto generated OPS-code. DO NOT MODIFY!

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