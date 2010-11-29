/*
 * XMLConfigLoader.java
 *
 * Created on den 10 september 2007, 08:28
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */
package configlib;

import com.sun.org.apache.xerces.internal.parsers.DOMParser;
import java.io.File;
import java.lang.reflect.Field;
import java.net.MalformedURLException;
import java.net.URL;


import java.util.Vector;
import org.w3c.dom.DOMException;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;
import org.xml.sax.helpers.DefaultHandler;

public class XMLConfigLoader extends DefaultHandler
{
    private static NodeList nol;

    static public void main(String[] argv)
    {
        try
        {
            // Get an instance of the parser
            DOMParser parser = new DOMParser();

            // Generate a URL from the filename.
            String fileName = "TestXML.xml";

            // Parse the document.
            parser.parse(new InputSource(fileName));          

            // Obtain the document.
            Document doc = parser.getDocument();
            
            TestConfigClass t2 = new TestConfigClass();

            applyXMLNode(t2, null, doc);

            parser.reset();
        }
        catch (Exception e)
        {
            System.out.println(e.toString());
        }
    }

    static void printElements(Document doc)
    {
         nol = doc.getElementsByTagName("*");
//
//        Node n = nl.item(0);
//
//        for (int i = 0; i < nl.getLength(); i++)
//        {
//            n = nl.item(i);
//            System.out.print(n.getNodeName() + " ");
//        }
//
//        System.out.println();
    }

    public static String applyXMLNode(Object o, String name, Node node)
    {
        String ret = "";
        
            ret += "<" + name + "\">\n";
            
            try
        {
            NodeList nl = node.getChildNodes();
            for (int i = 0; i < nl.getLength(); i++)
            {
                Node n = nl.item(i);
                String fName = n.getTextContent();
                Field field = o.getClass().getField(fName);
                if (o instanceof String)
                {
                    field.set(o, n.getNodeValue());
                }
                
            }
            
            ret += "</" + name + ">\n";

            return ret;
        }
        catch (NoSuchFieldException noSuchFieldException)
        {
            return null;
        }
        catch (SecurityException securityException)
        {
            return null;
        }
        catch (DOMException dOMException)
        {
            return null;
        }
        catch (IllegalArgumentException illegalArgumentException)
        {
            return null;
        }
        catch (IllegalAccessException illegalAccessException)
        {
            return null;
        }
        

    }
}