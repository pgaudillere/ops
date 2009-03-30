#ifndef SerializableH
#define SerializableH



namespace ops
{
	class ArchiverInOut;


	class Serializable
	{
	public:
		virtual void serialize(ArchiverInOut* archiver) = 0;


	};
}



#endif