

namespace opstest
{

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using OPS;

public class ComplexArrayData : OPSObject
{
    public long timestamp;
	public List<ComplexData> values;
	

    public ComplexArrayData()
    {
        timestamp = 0;
	values = new List<ComplexData>();
	

    }


}
}