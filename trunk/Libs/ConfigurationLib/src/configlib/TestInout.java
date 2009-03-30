/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package configlib;

import configlib.exception.FormatException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author angr
 */
public class TestInout
{
    public static void main(String[] args)
    {
        //readOut();
        readIn();

    }

    private static void readOut()
    {
        FileOutputStream baos = null;
        try
        {
            TestClass2 test2 = new TestClass2();
            boolean writeXMLHeader = true;
            baos = new FileOutputStream(new File("TestInOut.xml"));
            XMLArchiverOut xMLArchiver = new XMLArchiverOut(baos, writeXMLHeader);
            xMLArchiver.setWriteTypes(false);

            xMLArchiver.inout("test2", test2);

        }
        catch (IOException ex)
        {
            Logger.getLogger(TestInout.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static void readIn()
    {
        FileOutputStream baos = null;
        try
        {
            FileInputStream fis = new FileInputStream(new File("TestInOut.xml"));
            XMLArchiverIn archiverIn = new XMLArchiverIn(fis);
            
            //Add typesupport for TestClass1 and TestClass2
            archiverIn.add(new SerializableFactory() {

                public Serializable create(String type)
                {
                    if(type.equals("configlib.TestClass1"))
                    {
                        return new TestClass1();
                    }
                    if(type.equals("configlib.TestClass2"))
                    {
                        return new TestClass2(false);
                    }
                    return null;
                }
            });


            TestClass2 testRead = new TestClass2(false);
            archiverIn.inout("test2", testRead);
            System.out.println("stop");
        } catch (FormatException ex)
        {
            Logger.getLogger(TestInout.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex)
        {
            Logger.getLogger(TestInout.class.getName()).log(Level.SEVERE, null, ex);
        }
        //finally
//        {
//            try
//            {
//                //baos.close();
//            } catch (IOException ex)
//            {
//                Logger.getLogger(TestInout.class.getName()).log(Level.SEVERE, null, ex);
//            }
//        }
    }

}
