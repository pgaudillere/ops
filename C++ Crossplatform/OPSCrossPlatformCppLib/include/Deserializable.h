#ifndef DeserializableH
#define DeserializableH


namespace ops
{
	class ArchiverIn;



	class Deserializable
	{
	public:
		virtual void deserialize(ArchiverIn* archiver) = 0;


	};
}



#endif