

#ifndef FilterQoSPolicyH
#define FilterQoSPolicyH

namespace ops
{
//ForwardDeclaration/////
    class OPSObject;/////////
/////////////////////////
    
    class FilterQoSPolicy
    {
        ///Applies a filter in the receiving process in Subscribers.
        ///Returning false from a filter indicates that this data sample (OPSObject)
        ///shall not be propagated to the application layer.
    public:
        virtual bool applyFilter(OPSObject* o) = 0;
        
    };
}

#endif
