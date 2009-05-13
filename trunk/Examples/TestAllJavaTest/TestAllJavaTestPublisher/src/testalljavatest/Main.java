/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package testalljavatest;

import TestAll.ChildData;
import TestAll.ChildDataPublisher;
import TestAll.TestData;
import java.util.logging.Level;
import java.util.logging.Logger;
import ops.OPSConfig;
import ops.Participant;
import ops.Topic;
import ops.archiver.OPSObjectFactory;

/**
 *
 * @author angr
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {

        Participant participant = Participant.getInstance("TestAllDomain");
        participant.addTypeSupport(new TestAll.TestAllTypeFactory());

        Topic topic = participant.createTopic("ChildTopic");

        ChildDataPublisher pub = new ChildDataPublisher(topic);

        ChildData data = new ChildData();

        data.baseText = "Greetings from Java";
        pub.setName("TestAll Java ChildPublisher");

        data.s = "TestString";
        data.b = 0;
        data.l = 1;
        data.f = 2.0f;
        data.d = 3.0;
        data.bs.add((byte)4);
        data.is.add(5);
        data.ls.add((long)7);

        data.ss.add("TestString in Array.");

        TestData testData = new TestData();
        testData.text = "Text in aggregated test data.";

        TestData testData2 = new TestData();
        testData2.text = "Text in aggregated test data 2.";

        TestData testData3 = new TestData();
        testData3.text = "Text in aggregated test data 3.";

        data.test2 = testData;

        data.test2s.add(testData2);
        data.test2s.add(testData3);



        while (true)
        {
            data.i ++;
            pub.write(data);
            sleep(1000);
        }



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
