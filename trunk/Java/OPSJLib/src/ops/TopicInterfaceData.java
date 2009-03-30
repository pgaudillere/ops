//Auto generated OPS-code. DO NOT MODIFY!

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