/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package jarsearch;

import jarsearch.util.FileHelper;
import java.io.File;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.Enumeration;
import java.util.Vector;
import java.util.jar.JarEntry;
import java.util.jar.JarFile;

/**
 *
 * @author angr
 */
public class JarSearcher
{
    URLClassLoader classLoader = null;
    Vector<URL> urls = new Vector();
    Vector<JarFile> jars = new Vector<JarFile>();
    ClassLoader parentClassLoader;

    public JarSearcher(ClassLoader parentClassLoader)
    {
        this.parentClassLoader = parentClassLoader;
        classLoader = new URLClassLoader(new URL[0], parentClassLoader);

    }

    public void addJar(File jarFile) throws MalformedURLException, IOException
    {
        JarFile newJarFile = new JarFile(jarFile);
        jars.add(newJarFile);
        String s1 = "file:///" + FileHelper.unixSlashed(jarFile.getAbsolutePath());
        urls.add(new URL(s1));
        classLoader = new URLClassLoader(urls.toArray(new URL[0]), parentClassLoader);
    }
    public Class loadClass(String className) throws ClassNotFoundException
    {
        return classLoader.loadClass(className);
    }
    public ClassLoader getClassLoader()
    {
        return classLoader;
    }
    public Vector<String> listImplementingClassesOf(String baseClassName) throws ClassNotFoundException
    {
        Vector<String> allClasses = new Vector<String>();
        Vector<String> result = new Vector<String>();
        for (JarFile jar : jars)
        {
            Enumeration<JarEntry> e = jar.entries();

            while(e.hasMoreElements())
            {
                JarEntry entry = e.nextElement();
                String name = entry.getName();
                if(name.endsWith(".class"))
                {
                    name = FileHelper.cropExtension(name).replace("/", ".");
                    allClasses.add(name);
                    //System.out.println("" + name);
                }
            }

        }
        for (String string : allClasses)
        {
            Class clazz = classLoader.loadClass(string);
            if(isChildOf(baseClassName, clazz))
            {
                result.add(string);
            }
            

        }
        return result;



    }
    private boolean isChildOf(String parent, Class clazz)
    {
        try
        {
            String name = clazz.getName();
            if (name.equals(parent))
            {
                return true;
            } else
            {
                for (Class interf : clazz.getInterfaces())
                {
                    if(isChildOf(parent, interf))
                    {
                        return true;
                    }
                }
                return isChildOf(parent, clazz.getSuperclass());
            }
        }
        catch (Exception e)
        {
            return false;
        }

    }
    private String findSuperSuper(Class clazz)
    {
        String name = clazz.getName();
        try
        {
        if(clazz.getSuperclass().getName().equals("java.lang.Object"))
        {
            return name;
        }
        else
        {
            return findSuperSuper(clazz.getSuperclass());
        }
        }
        catch(NullPointerException npe)
        {
            return name;
        }

    }


}
