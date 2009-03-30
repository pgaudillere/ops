/*
 * NewJavaCompilerTest.java
 * JUnit based test
 *
 * Created on den 24 november 2007, 12:44
 */

package idlcompiler.compilers;

import junit.framework.*;
import parsing.IDLClass;
import parsing.IDLField;

/**
 *
 * @author Anton Gravestam
 */
public class NewJavaCompilerTest extends TestCase
{
    
    public NewJavaCompilerTest(String testName)
    {
        super(testName);
    }

    protected void setUp() throws Exception
    {
    }

    protected void tearDown() throws Exception
    {
    }

    /**
     * Test of compile method, of class idlcompiler.compilers.NewJavaCompiler.
     */
    public void testCompile()
    {
        System.out.println("compile");
        
        IDLClass idlClass = null;
        NewJavaCompiler instance = new NewJavaCompiler();
        
        String expResult = "";
        String result = instance.compile(idlClass);
        assertEquals(expResult, result);
        
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }
    
}
