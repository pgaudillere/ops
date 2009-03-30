/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.archiver;

import configlib.ArchiverInOut;
import java.io.IOException;

/**
 *
 * @author angr
 */
public class ChildTestData extends BaseTestData
{
    float f;
    String childString;
    byte by;

    public ChildTestData()
    {
        super();
        appendType("ops.archiver.ChildTestData");
    }

    @Override
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
        archive.inout("f", f);
        archive.inout("childString", childString);
        archive.inout("by", by);
    }


}
