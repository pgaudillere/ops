/**
*
* Copyright (C) 2006-2009 Anton Gravestam.
*
* This file is part of OPS (Open Publish Subscribe).
*
* OPS (Open Publish Subscribe) is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* OPS (Open Publish Subscribe) is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with OPS (Open Publish Subscribe).  If not, see <http://www.gnu.org/licenses/>.
*/
package ops;

import configlib.ArchiverInOut;
import configlib.XMLArchiverIn;
import configlib.exception.FormatException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Vector;
import ops.archiver.OPSObjectFactory;

/**
 *
 * @author angr
 */
public class OPSConfig extends OPSObject
{
    //Static------------------------

    //static OPSConfig theConfig = null;
    public static OPSConfig getConfig() throws IOException, FormatException
    {

        FileInputStream fis = new FileInputStream("ops_config.xml");
        XMLArchiverIn archiverIn = new XMLArchiverIn(fis, "root");
        archiverIn.add(OPSObjectFactory.getInstance());

        OPSConfig newConfig = null;
        newConfig = (OPSConfig) archiverIn.inout("ops_config", newConfig);

        return newConfig;
    }

    public static OPSConfig getConfig(File configFile) throws IOException, FormatException
    {

        FileInputStream fis = new FileInputStream(configFile);
        XMLArchiverIn archiverIn = new XMLArchiverIn(fis, "root");
        archiverIn.add(OPSObjectFactory.getInstance());
        OPSConfig newConfig = null;
        newConfig = (OPSConfig) archiverIn.inout("ops_config", newConfig);

        return newConfig;
    }
    //------------------------------
    private Vector<Domain> domains = new Vector<Domain>();

    public OPSConfig()
    {
        appendType("OPSConfig");
    }

    public Domain getDomain(String domainID)
    {
        for (Domain domain : domains)
        {
            if (domain.getDomainID().equals(domainID))
            {
                return domain;
            }
        }
        return null;
    }

    @Override
    public void serialize(ArchiverInOut archive) throws IOException
    {
        super.serialize(archive);
        domains = (Vector<Domain>) archive.inoutSerializableList("domains", domains);
    }

    public Vector<Domain> getDomains()
    {
        return domains;
    }


}
