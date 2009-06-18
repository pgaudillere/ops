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

import java.io.IOException;
import java.util.Vector;
import org.xml.sax.SAXException;

import org.xml.sax.XMLReader;
import org.xml.sax.Attributes;
import org.xml.sax.InputSource;
import org.xml.sax.helpers.XMLReaderFactory;
import org.xml.sax.helpers.DefaultHandler;


public class XMLConfigLoader extends DefaultHandler
{

    
    private Vector<Topic> topics = new Vector<Topic>();
    private String baseAddress = null;
    public XMLConfigLoader(String fileName) throws SAXException, IOException
    {
	super();
        
        XMLReader xr = XMLReaderFactory.createXMLReader();
	//SAXParser xr = SAXParser();

        //com.sun.org.apache.xerces.internal.parsers.SAXParser xr = new com.sun.org.apache.xerces.internal.parsers.SAXParser();
	xr.setContentHandler(this);
	xr.setErrorHandler(this);
        
        xr.parse(new InputSource(fileName));
    }

    public String getBaseAddress()
    {
        return baseAddress;
    }

    public Vector<Topic> getTopics()
    {

        return topics;
    }


    ////////////////////////////////////////////////////////////////////
    // Event handlers.
    ////////////////////////////////////////////////////////////////////

    public void startElement (String uri, String name,
			      String qName, Attributes atts)
    {
        if(name.equals("manager"))
        {
            baseAddress = atts.getValue("domainAddress");
        }
        
        else if(name.equals("topic"))
        {
            Topic t = new Topic();
            t.setName(atts.getValue("name"));
            t.setTypeID(atts.getValue("type"));
            t.setPort(Integer.parseInt(atts.getValue("portID")));
            t.setDomainAddress(baseAddress);
            try
            {
                t.setReplyPort(Integer.parseInt(atts.getValue("replyPortID")));
            } 
            catch (NumberFormatException ex)
            {
                //ex.printStackTrace();
            }
            catch (NullPointerException ex)
            {
                
            }
            topics.add(t);
        }
    }
    
    public void startDocument ()
    {
	
    }


    public void endDocument ()
    {
	
    }


    


    public void endElement (String uri, String name, String qName)
    {
	
    }


    public void characters (char ch[], int start, int length)
    {
	
    }

}