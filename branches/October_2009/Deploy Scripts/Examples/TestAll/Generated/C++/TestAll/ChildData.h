//Auto generated OPS-code. DO NOT MODIFY!

#ifndef TestAll_ChildData_h
#define TestAll_ChildData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>

#include "TestData.h"
#include "BaseData.h"


namespace TestAll {


class ChildData :
	public BaseData
{
public:
   static std::string getTypeName(){return std::string("TestAll.ChildData");}
	
	///Comments like this will be generated to C++ and Java...
	bool bo;
	char b;
	int i;
	__int64 l;
	float f;
	double d;
	std::string s;
	TestData testData;
	std::vector<bool> bos;
	std::vector<char> bs;
	std::vector<int> is;
	std::vector<__int64> ls;
	std::vector<float> fs;
	std::vector<double> ds;
	std::vector<std::string> ss;
	std::vector<TestData> testDatas;

    ///Default constructor.
    ChildData()
        : BaseData()
		, bo(false), b(0), i(0), l(0), f(0), d(0)
    {
        OPSObject::appendType(std::string("TestAll.ChildData"));


    }
    ///Copy-constructor making full deep copy of a(n) ChildData object.
    ChildData(const ChildData& __c)
       : BaseData()
		, bo(false), b(0), i(0), l(0), f(0), d(0)
    {
        OPSObject::appendType(std::string("TestAll.ChildData"));

        __c.fillClone((ChildData*)this);

    }
    ///Assignment operator making full deep copy of a(n) ChildData object.
    ChildData& operator = (const ChildData& other)
    {
        other.fillClone(this);
        return *this;
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
		archive->inout(std::string("testData"), testData);
		archive->inout(std::string("bos"), bos);
		archive->inout(std::string("bs"), bs);
		archive->inout(std::string("is"), is);
		archive->inout(std::string("ls"), ls);
		archive->inout(std::string("fs"), fs);
		archive->inout(std::string("ds"), ds);
		archive->inout(std::string("ss"), ss);
		archive->inout<TestData>(std::string("testDatas"), testDatas, TestData());

    }
    //Returns a deep copy of this object.
    virtual ops::OPSObject* clone()
    {
		ChildData* ret = new ChildData;
		this->fillClone(ret);
		return ret;

    }

    virtual void fillClone(ops::OPSObject* obj) const
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
		narrRet->testData = testData;
		narrRet->bos = bos;
		narrRet->bs = bs;
		narrRet->is = is;
		narrRet->ls = ls;
		narrRet->fs = fs;
		narrRet->ds = ds;
		narrRet->ss = ss;
		narrRet->testDatas = testDatas;

    }

    ///Destructor: Note that all aggregated data and vectors are completely deleted.
    virtual ~ChildData(void)
    {

    }
    
};

}


#endif
