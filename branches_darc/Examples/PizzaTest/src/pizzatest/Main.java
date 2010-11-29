/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pizzatest;

import java.util.Observable;
import java.util.Observer;
import java.util.logging.Level;
import java.util.logging.Logger;
import ops.Topic;
import ops.archiver.OPSObjectFactory;
import pizza.CapricosaData;
import pizza.PizzaData;
import pizza.PizzaDataPublisher;
import pizza.PizzaDataSubscriber;
import pizza.VessuvioData;
import pizza.special.ExtraAllt;
import pizza.special.LHCData;

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
        // TODO code application logic here
        //Register typesupport for our project.

        OPSObjectFactory.getInstance().add(new PizzaProject.PizzaProjectTypeFactory());

        ops.Topic<PizzaData> topic = new Topic<PizzaData>();
        topic.setDomainAddress("236.7.8.44");
        topic.setName("PizzaTopic");
        topic.setPort(6777);
        topic.setTypeID("pizza.PizzaData");


        PizzaDataSubscriber sub = new PizzaDataSubscriber(topic);
        sub.addObserver(new Observer() { public void update(Observable o, Object arg){onNewPizza((PizzaData) arg);}});
        sub.start();

        PizzaDataSubscriber sub2 = new PizzaDataSubscriber(topic);
        sub2.addObserver(new Observer() { public void update(Observable o, Object arg){onNewPizza((PizzaData) arg);}});
        sub2.start();
        
        PizzaDataPublisher pub = new PizzaDataPublisher(topic);
        pub.setName("Skeppet");


        for (int i = 0; i < 10; i++)
        {
            double rand = Math.random();
            if(rand < 0.1)
            {
                ExtraAllt ea = new ExtraAllt();

                ea.description = "Skeppets bästa!";
                ea.bearnaise = "Svettigast i stan!";
                ea.ham = "Italiensk kvalitet...";
                ea.meetQuality = 10;
                ea.nrOfMushRooms = 30;
                ea.extraCheese = true;

                ea.bools.add(true);
                ea.bools.add(true);
                ea.bools.add(true);
                ea.bools.add(true);
                ea.bools.add(false);
                ea.bools.add(false);
                ea.bools.add(false);

                ea.doubles.add(2.1);
                ea.doubles.add(3.1);
                ea.doubles.add(4.1);
                ea.doubles.add(5.1);
                ea.doubles.add(6.1);

                ea.strings.add("12");
                ea.strings.add("123");
                ea.strings.add("1234");
                ea.strings.add("12345");

                ea.mushrooms = "Forest style!";



                pub.write(ea);
            }
            else if(rand < 0.5)
            {
                pub.write(new CapricosaData());
            }
            else
            {
                pub.write(new VessuvioData());
            }
            sleep(50000);
            
        }
        //if(!sub.stop()) System.out.println("Error stopping...");
        //if(!sub2.stop()) System.out.println("Error stopping...");


    }

    private static void onNewPizza(PizzaData pizzaData)
    {
        if(pizzaData instanceof ExtraAllt)
        {
            System.out.println("WooHoo!");
        }
        System.out.println("" + pizzaData.getClass().getName());
    }


    private static void sleep(int i)
    {
        try
        {
            Thread.sleep(i);
        } catch (InterruptedException ex)
        {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
