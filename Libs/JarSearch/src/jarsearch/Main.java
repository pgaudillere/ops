/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package jarsearch;

import java.io.File;
import java.io.IOException;
import java.net.MalformedURLException;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author angr
 */
public class Main
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        try
        {
            JarSearcher jarSearcher = new JarSearcher();
            jarSearcher.addJar(new File("OPSJLib.jar"));
            jarSearcher.addJar(new File("ConfigurationLib.jar"));

            Vector<String> opsObjectClasses = jarSearcher.listImplementingClassesOf("ops.Transport");

            for (String string : opsObjectClasses)
            {
                System.out.println("" + string);
            }

        } catch (ClassNotFoundException ex)
        {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        } catch (MalformedURLException ex)
        {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex)
        {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }


    }
}
