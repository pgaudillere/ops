//Auto generated OPS-code. DO NOT MODIFY!

#ifndef testall_ChildData_h
#define testall_ChildData_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>

#include "BaseData.h"
#include "TestData.h"
#include "TestData.h"
#include "TestData.h"


namespace testall {


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
	TestData* test2;
	std::vector<bool> bos;
	std::vector<char> bs;
	std::vector<int> is;
	std::vector<__int64> ls;
	std::vector<float> fs;
	std::vector<double> ds;
	std::vector<std::string> ss;
	std::vector<TestData*> test2s;
	std::vector<TestData*> test2s2;


    ChildData()
        : BaseData()
		, bo(false), b(0), i(0), l(0), f(0), d(0)
    {
        OPSObject::appendType(std::string("testall.ChildData"));
		test2 = new TestData();


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
		test2 = (TestData*) archive->inout(std::string("test2"), test2);
		archive->inout(std::string("bos"), bos);
		archive->inout(std::string("bs"), bs);
		archive->inout(std::string("is"), is);
		archive->inout(std::string("ls"), ls);
		archive->inout(std::string("fs"), fs);
		archive->inout(std::string("ds"), ds);
		archive->inout(std::string("ss"), ss);
		archive->inout<TestData*>(std::string("test2s"), test2s);
		archive->inout<TestData*>(std::string("test2s2"), test2s2);

    }

    ///Destructor: Note that all aggregated data and vectors are completely deleted.
    virtual ~ChildData(void)
    {
		if(test2) delete test2;
		for(unsigned int __i = 0; __i < test2s.size(); __i++){ if(test2s[__i]) delete test2s[__i];}
		for(unsigned int __i = 0; __i < test2s2.size(); __i++){ if(test2s2[__i]) delete test2s2[__i];}

    }
    
};

}


#endif
