/*
 * XMLConfigLoader.java
 *
 * Created on den 10 september 2007, 08:28
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;

import java.io.FileReader;
import java.io.IOException;
import java.util.Vector;
import javax.xml.parsers.SAXParser;
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