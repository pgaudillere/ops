
package configlib;

import java.io.IOException;

/**
 *
 * @author Anton Gravestam
 */
public class Passanger extends Person implements SerializableOld, Deserializable
{
    String destination;

    public Passanger()
    {
        super("", 0);
    }
    
    public Passanger(String name, int age, String desttination)
    {
        super(name, age);
        this.destination = desttination;
    }
    

    public void serialize(ArchiverOut archive) throws IOException
    {
        super.serialize(archive);
        archive.put("destination", destination);
    }

    public void desirialize(ArchiverIn archiverIn)
    {
        super.desirialize(archiverIn);
        destination = archiverIn.getString("destination");
    }
    

}
