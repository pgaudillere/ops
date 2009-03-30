

namespace opstest
{

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using OPS;

public class ByteArrayData : OPSObject
{
    public long timestamp;
	public List<byte> bytes;
	

    public ByteArrayData()
    {
        timestamp = 0;
	bytes = new List<byte>();
	

    }


}
}