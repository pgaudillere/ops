/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops.archiver;

import configlib.ArchiverInOut;
import java.io.IOException;
import ops.OPSObject;

/**
 *
 * @author angr
 */
public class BaseTestData extends OPSObject
{

    int i;
    double d;

    public BaseTestData()
    {
        super();
        appendType("ops.archiver.BaseTestData");
    }



    @Override
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
        archive.inout("i", i);
        archive.inout("d", d);
    }


}
