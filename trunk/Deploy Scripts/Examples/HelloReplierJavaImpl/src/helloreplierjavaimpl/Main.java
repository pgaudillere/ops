package helloreplierjavaimpl;

import HelloRequestReply.HelloRequestReplyTypeFactory;
import hello.HelloData;
import hello.HelloDataPublisher;
import hello.HelloDataSubscriber;
import hello.RequestHelloData;
import hello.RequestHelloDataSubscriber;
import java.util.Observable;
import java.util.Observer;
import java.util.logging.Level;
import java.util.logging.Logger;
import ops.CommException;
import ops.KeyFilterQoSPolicy;
import ops.Participant;

public class Main
{

    public static void main(String[] args)
    {
        try
        {
            Participant participant = Participant.getInstance("HelloDomain");
            participant.addTypeSupport(new HelloRequestReplyTypeFactory());
            final RequestHelloDataSubscriber subscriber = new hello.RequestHelloDataSubscriber(participant.createTopic("RequestHelloTopic"));
            final HelloDataPublisher helloDataPublisher = new HelloDataPublisher(participant.createTopic("HelloTopic"));
            subscriber.addObserver(new Observer()
            {

                public void update(Observable sub, Object o)
                {
                    RequestHelloData request = subscriber.getData();
                    System.out.println("Request received.");
                    //Create a reply
                    HelloData helloData = new HelloData();
                    helloData.requestId = request.requestId;
                    helloData.requestAccepted = true;
                    helloData.helloString = "Hello " + request.requestersName + "!!";
                    helloData.setKey("req_rep_instance1");

                    helloDataPublisher.setKey("req_rep_instance1");
                    helloDataPublisher.write(helloData);
                }
            });
            subscriber.addFilterQoSPolicy(new KeyFilterQoSPolicy("req_rep_instance1"));
            subscriber.start();

            
            //Just keep program alive, action takes place in update above...
            while (true)
            {
                try
                {
                    Thread.sleep(100000);
                } catch (InterruptedException ex)
                {
                    Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        } catch (CommException ex)
        {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
