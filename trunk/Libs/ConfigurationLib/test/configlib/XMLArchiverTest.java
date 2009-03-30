/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package configlib;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author angr
 */
public class XMLArchiverTest {

    public XMLArchiverTest() {
    }

    @BeforeClass
    public static void setUpClass() throws Exception
    {
    }

    @AfterClass
    public static void tearDownClass() throws Exception
    {
    }

    @Before
    public void setUp() {
    }

    @After
    public void tearDown() {
    }

    /**
     * Test of put method, of class XMLArchiverOut.
     */
    @Test
    public void testPut_String_byte()
    {
        System.out.println("put");
        String name = "myByte";
        byte v = 1;
        XMLArchiverOut instance = null;
        instance.put(name, v);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of put method, of class XMLArchiverOut.
     */
    @Test
    public void testPut_String_short()
    {
        System.out.println("put");
        String name = "";
        short v = 0;
        XMLArchiverOut instance = null;
        instance.put(name, v);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of put method, of class XMLArchiverOut.
     */
    @Test
    public void testPut_String_int()
    {
        System.out.println("put");
        String name = "";
        int v = 0;
        XMLArchiverOut instance = null;
        instance.put(name, v);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of put method, of class XMLArchiverOut.
     */
    @Test
    public void testPut_String_long()
    {
        System.out.println("put");
        String name = "";
        long v = 0L;
        XMLArchiverOut instance = null;
        instance.put(name, v);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of put method, of class XMLArchiverOut.
     */
    @Test
    public void testPut_String_float()
    {
        System.out.println("put");
        String name = "";
        float v = 0.0F;
        XMLArchiverOut instance = null;
        instance.put(name, v);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of put method, of class XMLArchiverOut.
     */
    @Test
    public void testPut_String_double()
    {
        System.out.println("put");
        String name = "";
        double v = 0.0;
        XMLArchiverOut instance = null;
        instance.put(name, v);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of put method, of class XMLArchiverOut.
     */
    @Test
    public void testPut_String_String()
    {
        System.out.println("put");
        String name = "";
        String v = "";
        XMLArchiverOut instance = null;
        instance.put(name, v);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of put method, of class XMLArchiverOut.
     */
    @Test
    public void testPut_String_Serializable()
    {
        System.out.println("put");
        String name = "";
        SerializableOld v = null;
        XMLArchiverOut instance = null;
        instance.put(name, v);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

}