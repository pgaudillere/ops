#ifndef ops_TransactionH
#define ops_TransactionH

class Transaction
{
public:
	Transaction(DataHeader header)
	{
		this->header = header;
	}
	void addSegment(int segNr, char* segData, int segDataSize)
	{
		if(dataMap.find(segNr) != dataMap.end())
		{
			dataMap[segNr] = segData;
			dataSizeMap[segData] = segDataSize;
		}
	}
	char* createArray()
	{
		int totalNrBytes = 0;
		for(int i = 0 ; i < header.nrOfSegments)
		{
			totalNrBytes += dataSizeMap[i + 1];
		}
		char* ret = new char[totalNrBytes];
		for(int j = 0 ; j < header.nrOfSegments)
		{
			memcpy(ret + ((j+1) * dataSizeMap[j+1]), dataMap[j+1]
		}
		

	}
	DataHeader header;
	std::map<int, char*> dataMap;
	std::map<int, int> dataSizeMap;


}



#endif