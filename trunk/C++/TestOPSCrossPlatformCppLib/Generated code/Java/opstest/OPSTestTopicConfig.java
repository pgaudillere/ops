package opstest;
public class OPSTestTopicConfig
{
	private String domainAddress = null;
	public OPSTestTopicConfig(String domainAddress)
	{
		this.domainAddress = domainAddress;
	}
	public ops.Topic<ComplexArrayData> getComplexArrayTopic()
	{
		return new ops.Topic<ComplexArrayData>("ComplexArrayTopic", 0, "ComplexArrayData", this.domainAddress);
	}
	public ops.Topic<ByteArrayData> getByteArrayTopic()
	{
		return new ops.Topic<ByteArrayData>("ByteArrayTopic", 0, "ByteArrayData", this.domainAddress);
	}
	public ops.Topic<ByteArrayData> getByteArray2Topic()
	{
		return new ops.Topic<ByteArrayData>("ByteArray2Topic", 0, "ByteArrayData", this.domainAddress);
	}
}
