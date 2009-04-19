//Auto generated OPS-code. DO NOT MODIFY!
#ifndef opstestComplexArrayDataHelperH
#define opstestComplexArrayDataHelperH

#include "OPSObject.h"
#include "OPSObjectHelper.h"
#include "ByteBuffer.h"
#include <string>
#include <vector>
#include "Manager.h"
#include "ComplexArrayDataHelper.h"
#include "ComplexArrayData.h"
#include "ComplexData.h" 
#include "ComplexDataHelper.h"


namespace opstest
{
class ComplexArrayDataHelper :
	public ops::OPSObjectHelper
{
public:
	

    ComplexArrayDataHelper()
    {
        

    }
    std::string GetTypeID()
    {
        return "opstest.ComplexArrayData";
    }
    int getSize(ops::OPSObject* o)
    {
        //Not used yet
        int i = 0;
			ComplexArrayData* oComplexArrayData = (ComplexArrayData*)o;i += GetOPSObjectFieldsSize(oComplexArrayData);
			i += 8;
			i += 4;
			ComplexDataHelper valuesHelper;
			for(unsigned int j = 0 ; j < oComplexArrayData->values.size(); j ++)
			{
				i += valuesHelper.getSize(&oComplexArrayData->values[j]) + 4; 
			}
			return i;
		
    }

    ~ComplexArrayDataHelper(void)
    {
    }

    void serialize(ops::OPSObject* o, char* b)
    {
        ops::ByteBuffer buf(b);
        ComplexArrayData* oComplexArrayData = (ComplexArrayData*)o;
        buf.WriteOPSObjectFields(o);
        buf.WriteLong(oComplexArrayData->timestamp);
        ComplexDataHelper valuesHelper ;
		buf.WriteInt((int)oComplexArrayData->values.size()); 
		for(unsigned int j = 0; j <oComplexArrayData->values.size() ; j++)
		{
			buf.WriteOPSObject(&oComplexArrayData->values[j], &ComplexDataHelper());
		}

	
    }
    ops::OPSObject* deserialize(char* b)
    {
        ops::ByteBuffer buf(b);
        ComplexArrayData* o = new ComplexArrayData();
        buf.ReadOPSObjectFields(o);
        o->timestamp = buf.ReadLong();
        int sizevalues = buf.ReadInt();
		o->values.reserve(sizevalues);o->values.resize(sizevalues, ComplexData());for(int __i = 0 ; __i < sizevalues; __i++)
		{
		ComplexData* ovalues = (ComplexData*)buf.ReadOPSObject( &ComplexDataHelper());
		o->values[__i] = *ovalues;
			delete ovalues;
		}

	return o;
    }

};
}

#endif