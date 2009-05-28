//Auto generated OPS-code. DO NOT MODIFY!

#ifndef TestAll_ChildData_h
#define TestAll_ChildData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>

#include "BaseData.h"
#include "TestData.h"
#include "TestData.h"
#include "TestData.h"
#include "TestData.h"


namespace TestAll {


class ChildData :
	public BaseData
{
public:
	
	bool bo;
	char b;
	int i;
	__int64 l;
	float f;
	double d;
	///This string shall hold the word World
	std::string s;
	TestData test2;
	TestData* testPointer;
		std::vector<bool> bos;
		std::vector<char> bs;
		std::vector<int> is;
		std::vector<__int64> ls;
		std::vector<float> fs;
		std::vector<double> ds;
		std::vector<std::string> ss;
		std::vector<TestData*> test2s;
		std::vector<TestData> test2s2;


    ChildData()
        : BaseData()
		, bo(false), b(0), i(0), l(0), f(0), d(0)
    {
        OPSObject::appendType(std::string("TestAll.ChildData"));
		testPointer = new TestData;


    }

    ///This method acceptes an ops::ArchiverInOut visitor which will serialize or deserialize an
    ///instance of this class to a format dictated by the implementation of the ArchiverInout.
    void serialize(ops::ArchiverInOut* archive)
    {
		BaseData::serialize(archive);
		archive->inout(std::string("bo"), bo);
		archive->inout(std::string("b"), b);
		archive->inout(std::string("i"), i);
		archive->inout(std::string("l"), l);
		archive->inout(std::string("f"), f);
		archive->inout(std::string("d"), d);
		archive->inout(std::string("s"), s);
		archive->inout(std::string("test2"), test2);
		testPointer = (TestData*) archive->inout(std::string("testPointer"), testPointer);
		archive->inout(std::string("bos"), bos);
		archive->inout(std::string("bs"), bs);
		archive->inout(std::string("is"), is);
		archive->inout(std::string("ls"), ls);
		archive->inout(std::string("fs"), fs);
		archive->inout(std::string("ds"), ds);
		archive->inout(std::string("ss"), ss);
		archive->inout<TestData>(std::string("test2s"), test2s);
		archive->inout<TestData>(std::string("test2s2"), test2s2, TestData());

    }
    //Returns a deep copy of this object.
    virtual ops::OPSObject* clone()
    {
		ChildData* ret = new ChildData;
		this->fillClone(ret);
		return ret;

    }

    virtual void fillClone(ops::OPSObject* obj)
    {
		ChildData* narrRet = (ChildData*)obj;
		BaseData::fillClone(narrRet);
		narrRet->bo = bo;
		narrRet->b = b;
		narrRet->i = i;
		narrRet->l = l;
		narrRet->f = f;
		narrRet->d = d;
		narrRet->s = s;
		narrRet->test2 = test2;
		if(narrRet->testPointer) delete narrRet->testPointer;
		narrRet->testPointer = (TestData*)testPointer->clone();
		narrRet->bos = bos;
		narrRet->bs = bs;
		narrRet->is = is;
		narrRet->ls = ls;
		narrRet->fs = fs;
		narrRet->ds = ds;
		narrRet->ss = ss;
		for(unsigned int __i = 0; __i < test2s.size(); __i++)
			{ narrRet->test2s.push_back(test2s[__i]); }
		narrRet->test2s2 = test2s2;

    }

    ///Destructor: Note that all aggregated data and vectors are completely deleted.
    virtual ~ChildData(void)
    {
		if(testPointer) delete testPointer;
		for(unsigned int __i = 0; __i < test2s.size(); __i++){ if(test2s[__i]) delete test2s[__i];}

    }
    
};

}


#endif
