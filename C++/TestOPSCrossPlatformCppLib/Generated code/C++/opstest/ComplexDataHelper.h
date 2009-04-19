//Auto generated OPS-code. DO NOT MODIFY!
#ifndef opstestComplexDataHelperH
#define opstestComplexDataHelperH

#include "OPSObject.h"
#include "OPSObjectHelper.h"
#include "ByteBuffer.h"
#include <string>
#include <vector>
#include "ComplexDataHelper.h"
#include "ComplexData.h"


namespace opstest
{
class ComplexDataHelper :
	public ops::OPSObjectHelper
{
public:
	

    ComplexDataHelper()
    {
        

    }
    std::string GetTypeID()
    {
        return "opstest.ComplexData";
    }
    int getSize(ops::OPSObject* o)
    {
        //Not used yet
        int i = 0;
			ComplexData* oComplexData = (ComplexData*)o;i += GetOPSObjectFieldsSize(oComplexData);
			i += 8;
			i += 8;
			return i;
		
    }

    ~ComplexDataHelper(void)
    {
    }

    void serialize(ops::OPSObject* o, char* b)
    {
        ops::ByteBuffer buf(b);
        ComplexData* oComplexData = (ComplexData*)o;
        buf.WriteOPSObjectFields(o);
        buf.WriteDouble(oComplexData->real);
        buf.WriteDouble(oComplexData->imag);
        
    }
    ops::OPSObject* deserialize(char* b)
    {
        ops::ByteBuffer buf(b);
        ComplexData* o = new ComplexData();
        buf.ReadOPSObjectFields(o);
        o->real = buf.ReadDouble();
        o->imag = buf.ReadDouble();
        return o;
    }

};
}

#endif