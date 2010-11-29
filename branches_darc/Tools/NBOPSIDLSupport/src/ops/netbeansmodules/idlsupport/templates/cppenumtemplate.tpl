//Auto generated OPS-code. DO NOT MODIFY!

#ifndef __underscoredPackName___className_h
#define __underscoredPackName___className_h

#include "OPSObject.h"
#include "ArchiverInOut.h"
#include <string>

__packageDeclaration

__classComment
class __className :
	public ops::OPSObject
{
public:
   static std::string getTypeName(){return std::string("__packageName.__className");}

__declarations
    int value;

    ///Default constructor.
    __className()
        : ops::OPSObject()
    {
        OPSObject::appendType(getTypeName());
        value = 0;
    }

    ///This method acceptes an ops::ArchiverInOut visitor which will serialize or deserialize an
    ///instance of this class to a format dictated by the implementation of the ArchiverInOut.
    void serialize(ops::ArchiverInOut* archive)
    {
        ops::OPSObject::serialize(archive);
        archive->inout(std::string("value"), value);
    }



};

__packageCloser

#endif
