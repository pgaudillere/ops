
package configlib;

import java.io.IOException;
import java.util.Vector;

/**
 *
 * @author Anton Gravestam
 */
public class Bus implements SerializableOld, Deserializable
{
    Driver driver = null;
    Vector<Passanger> passangers = new Vector<Passanger>();
    String name = "";
    double weight = 0;
    Vector<Byte> seatIDs = new Vector<Byte>();
    
    public Bus()
    {
        driver = new Driver("Ake Svensson", 55);
        name = "Saab";
        weight = 20000.5;
        
        passangers.add(new Passanger("Tossman", 53, "Dinner with..."));
        passangers.add(new Passanger("Sven-Inge", 27, "Fikarummet"));

        for (int i = 0; i < 5; i++)
        {
            seatIDs.add((byte)(Math.random()*100));
        }
        
    }
    public Bus(boolean empty)
    {
        
    }

    public void serialize(ArchiverOut archive) throws IOException
    {
        archive.put("driver", driver);
        archive.put("passangers", passangers);
        archive.put("name", name);
        archive.put("weight", weight);
        archive.putBytes("seatIDs", seatIDs);
        
    }

    public void desirialize(ArchiverIn archiverIn)
    {
        driver = new Driver("", 0);
        archiverIn.getDeserializable("driver", driver);
        int size = archiverIn.getNrElements("passangers");
        for (int i = 0; i < size; i++)
        {
            Passanger newPassanger = new Passanger();
            archiverIn.getElement("passangers", i, newPassanger);
            passangers.add(newPassanger);            
        }
        name = archiverIn.getString("name");
        weight = archiverIn.getDouble("weight");

    }
    
    

}
