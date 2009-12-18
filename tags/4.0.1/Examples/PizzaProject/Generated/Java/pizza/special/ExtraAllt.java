//Auto generated OPS-code. DO NOT MODIFY!

package pizza.special;

import ops.OPSObject;
import configlib.ArchiverInOut;
import java.io.IOException;

public class ExtraAllt extends LHCData
{
	////*Does the order include extra cheese???*/
	public boolean extraCheese;
	////*@limits(0,INFINITY)*/
	public byte nrOfMushRooms;
	public int meetQuality;
	public long timestamp;
	public float timeBakedHours;
	public double timeBakedSeconds;
	public String description = "";
	public pizza.special.Cheese cheese = new pizza.special.Cheese();
	public java.util.Vector<Boolean> bools = new java.util.Vector<Boolean>();
	public java.util.Vector<Byte> bytes = new java.util.Vector<Byte>();
	public java.util.Vector<Integer> ints = new java.util.Vector<Integer>();
	public java.util.Vector<Long> longs = new java.util.Vector<Long>();
	public java.util.Vector<Float> floats = new java.util.Vector<Float>();
	public java.util.Vector<Double> doubles = new java.util.Vector<Double>();
	public java.util.Vector<String> strings = new java.util.Vector<String>();
	public java.util.Vector<pizza.special.Cheese> cheeses = new java.util.Vector<pizza.special.Cheese>();


    public ExtraAllt()
    {
        super();
        appendType("pizza.special.ExtraAllt");

    }
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
		extraCheese = archive.inout("extraCheese", extraCheese);
		nrOfMushRooms = archive.inout("nrOfMushRooms", nrOfMushRooms);
		meetQuality = archive.inout("meetQuality", meetQuality);
		timestamp = archive.inout("timestamp", timestamp);
		timeBakedHours = archive.inout("timeBakedHours", timeBakedHours);
		timeBakedSeconds = archive.inout("timeBakedSeconds", timeBakedSeconds);
		description = archive.inout("description", description);
		cheese = (pizza.special.Cheese) archive.inout("cheese", cheese);
		bools = (java.util.Vector<Boolean>) archive.inoutBooleanList("bools", bools);
		bytes = (java.util.Vector<Byte>) archive.inoutByteList("bytes", bytes);
		ints = (java.util.Vector<Integer>) archive.inoutIntegerList("ints", ints);
		longs = (java.util.Vector<Long>) archive.inoutLongList("longs", longs);
		floats = (java.util.Vector<Float>) archive.inoutFloatList("floats", floats);
		doubles = (java.util.Vector<Double>) archive.inoutDoubleList("doubles", doubles);
		strings = (java.util.Vector<String>) archive.inoutStringList("strings", strings);
		cheeses = (java.util.Vector<pizza.special.Cheese>) archive.inoutSerializableList("cheeses", cheeses);

    }
}