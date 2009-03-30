//Auto generated OPS-code. DO NOT MODIFY!

#ifndef opsAckData_h
#define opsAckData_h

#include "OPSObject.h"
#include <string>
#include <vector>



namespace ops
{
class AckData :
	public ops::OPSObject
{
public:
	
    bool dataAccepted;
    std::string message;
    std::string id;
    

    AckData()
        : ops::OPSObject()
    {
        
        dataAccepted = 0;
        message = "";
        id = "";
        

    }
    std::string GetTypeID()
    {
        return "ops.AckData";
    }

    ~AckData(void)
    {
        
    }
    
};
}

#endif
