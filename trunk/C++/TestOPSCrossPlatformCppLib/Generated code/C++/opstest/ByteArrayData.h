//Auto generated OPS-code. DO NOT MODIFY!

#ifndef opstestByteArrayData_h
#define opstestByteArrayData_h

#include "OPSObject.h"
#include <string>
#include <vector>



namespace opstest
{
class ByteArrayData :
	public ops::OPSObject
{
public:
	
    __int64 timestamp;
    std::vector<char> bytes;
    

    ByteArrayData()
        : ops::OPSObject()
    {
        
        timestamp = 0;
        

    }
    std::string GetTypeID()
    {
        return "opstest.ByteArrayData";
    }

    ~ByteArrayData(void)
    {
                bytes.clear();

    }
    
};
}

#endif
