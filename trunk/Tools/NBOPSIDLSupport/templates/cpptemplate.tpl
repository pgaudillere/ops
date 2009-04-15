//Auto generated OPS-code. DO NOT MODIFY!

#ifndef __underscoredPackName___className_h
#define __underscoredPackName___className_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>

__imports

__packageDeclaration

__classComment
class __className :
	public __baseClassName
{
public:
	
__declarations

    __className()
        : __baseClassName()
__constructorHead
    {
        OPSObject::appendType(std::string("__packageName.__className"));
__constructorBody

    }

    ///This method acceptes an ops::ArchiverInOut visitor which will serialize or deserialize an
    ///instance of this class to a format dictated by the implementation of the ArchiverInout.
    void serialize(ops::ArchiverInOut* archive)
    {
__serialize
    }

    ///Destructor: Note that all aggregated data and vectors are completely deleted.
    virtual ~__className(void)
    {
__destructorBody
    }
    
};

__packageCloser

#endif
