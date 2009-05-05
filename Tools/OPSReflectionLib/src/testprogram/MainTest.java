/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package testprogram;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Observable;
import java.util.Observer;
import java.util.logging.Level;
import java.util.logging.Logger;
import ops.OPSObject;
import ops.Publisher;
import ops.Subscriber;
import opsreflection.OPSFactory;

/**
 *
 * @author angr
 */
public class MainTest
{

    public static void main(String[] args)
    {

        OPSFactory factory = new OPSFactory("TestAllDomain");

        for (String string : factory.listTopicNames())
        {
            System.out.println("" + string);
        }
        try
        {

            factory.addJar(new File("TestAll.jar"));
            factory.save(new File("TestFactoryConfig.xml"));

            OPSObject oo = factory.createOPSObject("TestAll.ChildData");
            System.out.println("" + oo);
            Subscriber sub = factory.createSubscriber("ChildTopic");
            sub.addObserver(new Observer()
            {
                public void update(Observable o, Object arg)
                {
                    onNewData();
                }
            });
            sub.start();
            System.out.println("" + sub);
            Publisher pub = factory.createPublisher("ChildTopic");
            pub.writeAsOPSObject(oo);
            System.out.println("" + pub);

        } catch (FileNotFoundException ex)
        {
            Logger.getLogger(MainTest.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex)
        {
            Logger.getLogger(MainTest.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static void onNewData()
    {
        System.out.println("Data received, Wohoooo!");
    }
}

