//Auto generated OPS-code. DO NOT MODIFY!

#ifndef __underscoredPackName___className_h
#define __underscoredPackName___className_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>
#include <vector>

__imports

//Nested namespaces opener.
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
    virtual ~__className(void)
    {
__destructorBody
    }
    void serialize(ops::ArchiverInOut* archive)
    {
__serialize
    }
    
};

//Close nested namespace
__packageCloser

#endif
