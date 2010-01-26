
package configlib;

import java.io.IOException;

/**
 *
 * @author Anton Gravestam
 */
public class Driver extends Person implements SerializableOld, Deserializable
{
    int licensType = 1;
    public Driver(String name, int age)
    {
        super(name, age);
    }

    @Override
    public void serialize(ArchiverOut archive) throws IOException
    {
        super.serialize(archive);
        archive.put("licensType", licensType);
        
    }

    @Override
    public void desirialize(ArchiverIn archiverIn)
    {
        super.desirialize(archiverIn);
        licensType = archiverIn.getInt("licensType");
    }
    
    

    
}
