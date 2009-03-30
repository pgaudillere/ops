
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
