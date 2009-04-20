/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

import configlib.ArchiverInOut;
import configlib.XMLArchiverIn;
import configlib.exception.FormatException;
import java.io.FileInputStream;
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
    
    static OPSConfig theConfig = null;
    
    static OPSConfig getConfig() throws IOException, FormatException
    {        
        if(theConfig == null)
        {
            FileInputStream fis = new FileInputStream("ops_config.xml");
            XMLArchiverIn archiverIn = new XMLArchiverIn(fis, "root");
            archiverIn.add(OPSObjectFactory.getInstance());

            theConfig = (OPSConfig) archiverIn.inout("ops_config", theConfig);
            
            
        }
        return theConfig;
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
            if(domain.getDomainID().equals(domainID))
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



}
