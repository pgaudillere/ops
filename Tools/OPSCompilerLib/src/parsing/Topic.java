/*
 * Class reflecting a Topic element from a topic config file 
 */
package parsing;

/**
 *
 * @author angr
 */
public class Topic
{
    private String name;
    private int port;
    private String typeID;

    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public int getPort()
    {
        return port;
    }

    public void setPort(int port)
    {
        this.port = port;
    }

    public String getTypeID()
    {
        return typeID;
    }

    public void setTypeID(String typeID)
    {
        this.typeID = typeID;
    }
    
    
}
