//Auto generated OPS-code. DO NOT MODIFY!

#ifndef opstestComplexArrayData_h
#define opstestComplexArrayData_h

#include "OPSObject.h"
#include <string>
#include <vector>

#include "ComplexData.h" 
#include "ComplexDataHelper.h"


namespace opstest
{
class ComplexArrayData :
	public ops::OPSObject
{
public:
	
    __int64 timestamp;
    std::vector<ComplexData> values;
    

    ComplexArrayData()
        : ops::OPSObject()
    {
        
        timestamp = 0;
        

    }
    std::string GetTypeID()
    {
        return "opstest.ComplexArrayData";
    }

    ~ComplexArrayData(void)
    {
                values.clear();

    }
    
};
}

#endif
