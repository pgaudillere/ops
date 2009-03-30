//Auto generated OPS-code. DO NOT MODIFY!

#ifndef opstestComplexData_h
#define opstestComplexData_h

#include "OPSObject.h"
#include <string>
#include <vector>



namespace opstest
{
class ComplexData :
	public ops::OPSObject
{
public:
	
    double real;
    double imag;
    

    ComplexData()
        : ops::OPSObject()
    {
        
        real = 0;
        imag = 0;
        

    }
    std::string GetTypeID()
    {
        return "opstest.ComplexData";
    }

    ~ComplexData(void)
    {
        
    }
    
};
}

#endif
