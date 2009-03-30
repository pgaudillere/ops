//
// File:   KeyFilterQoSPolicy.h
// Author: Anton Gravestam
//
// Created on den 28 november 2007, 19:59
//

#ifndef _KEYFILTERQOSPOLICY_H
#define	_KEYFILTERQOSPOLICY_H

#include "FilterQoSPolicy.h"
#include "Lockable.h"
#include <string>
#include <vector>


namespace ops
{
    //Forward declaration//////
    class OPSObject;///////////
    ///////////////////////////
    
    class KeyFilterQoSPolicy
		: public FilterQoSPolicy, public Lockable
	{
        
    public:
		KeyFilterQoSPolicy(std::string keyString);
		KeyFilterQoSPolicy(std::vector<std::string> keyStrings);
		void setKeys(std::vector<std::string> keyStrings);
		void setKey(std::string key);
		std::vector<std::string> getKeys();

		virtual ~KeyFilterQoSPolicy();


        //Overides applyFilterQoSPolicy(OPSObject* o) in FilterQoSPolicy
        bool applyFilter(OPSObject* o);
	private:
		std::vector<std::string> keyStrings;
		std::string keyString;
        
    };
    
}

#endif	/* _KEYFILTERQOSPOLICY_H */

