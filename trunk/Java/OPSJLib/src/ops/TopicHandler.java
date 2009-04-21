/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops;

import java.io.IOException;
import java.util.HashMap;
import java.util.Observable;
import java.util.Observer;
import java.util.Vector;
import ops.archiver.OPSArchiverIn;
import ops.protocol.OPSMessage;

/**
 *
 * @author angr
 */
public class TopicHandler
{

    //private static HashMap<String, TopicHandler> instances = new HashMap<String, TopicHandler>();
    private boolean hasSubscribers;
    private boolean hasPublishers;
    private HashMap<String, MessageBuffer> messageBuffers = new HashMap<String, MessageBuffer>();

//    static TopicHandler getTopicHandler(Topic t)
//    {
//        if (!instances.containsKey(t.getName()))
//        {
//            TopicHandler newTopicHandler = new TopicHandler(t);
//            instances.put(t.getName(), newTopicHandler);
//        }
//        return instances.get(t.getName());
//    }
    private Topic topic;
    private Transport transport;
    private Vector<Subscriber> subscribers = new Vector<Subscriber>();
    private ObserverImpl bytesListener = new ObserverImpl();
    private Participant participant;

    public TopicHandler(Topic t, Participant part)
    {
        participant = part;
        topic = t;
        transport = new MulticastTransport(t.getDomainAddress(), t.getPort());//TransportFactory.getTransport(t);

    }

    public synchronized void addSubscriber(Subscriber sub)
    {
        subscribers.add(sub);

        if (!hasSubscribers)
        {
            addNewBytesEventListener();
            hasSubscribers = true;
            setupTransportThread();
        }
    }

    public synchronized boolean removeSubscriber(Subscriber sub)
    {
        boolean result = subscribers.remove(sub);

        if (subscribers.size() == 0)
        {
            transport.getNewBytesEvent().deleteObserver(bytesListener);
            hasSubscribers = false;
        }

        return result;
    }

    private synchronized void onNewBytes(byte[] bytes)
    {
        try
        {
            ReadByteBuffer readBuf = new ReadByteBuffer(bytes);

            if (readBuf.checkProtocol())
            {
                //String messID = readBuf.readstring();

                int nrOfFragments = readBuf.readint();
                int currentFragment = readBuf.readint();



                if(nrOfFragments == 1 && currentFragment == 0)
                {
                    sendBytesToSubscribers(readBuf);
                }
                else
                {
                    //TODO: make proper error handling.
                    System.out.println("________________Segment Error, Java does not suppport segmented messages:_____________________");
                }
            }



        } catch (IOException ex)
        {
            ex.printStackTrace();
        //TODO: Add error handling here
        }
    }

    private void addNewBytesEventListener()
    {
        transport.getNewBytesEvent().addObserver(bytesListener);
    }

    private void sendBytesToSubscribers(ReadByteBuffer readBuf) throws IOException
    {
        OPSArchiverIn archiverIn = new OPSArchiverIn(readBuf);
        OPSMessage message = null;
        message = (OPSMessage) archiverIn.inout("message", message);
        for (Subscriber subscriber : subscribers)
        {
            subscriber.notifyNewOPSMessage(message);
        }
    }

    private void setupTransportThread()
    {
        final byte[] bytes = new byte[StaticManager.MAX_SIZE];
        Thread thread = new Thread(new Runnable()
        {

            public void run()
            {
                while (hasSubscribers)
                {
                    transport.receive(bytes);
                }
                System.out.println("Leaving transport thread...");

            }
        });
        thread.start();
    }

    private class ObserverImpl implements Observer
    {

        public void update(Observable o, Object arg)
        {
            onNewBytes((byte[]) arg);
        }
    }



    //                if(nrOfFragments == 1)
//                {
//                    sendBytesToSubscribers(readBuf);
//                    return;
//                }
//                else if(messageBuffers.containsKey(messID))
//                {
//                    MessageBuffer messBuf = messageBuffers.get(messID);
//                    messBuf.addFragment(currentFragment, bytes, messID.length() + 8 + 6);
//                    if(messBuf.isComplete())
//                    {
//                        ReadByteBuffer tBuf = new ReadByteBuffer(messBuf.getBytes());
//                        sendBytesToSubscribers(tBuf);
//                        messageBuffers.remove(messID);
//                        return;
//                    }
//                }
//                else
//                {
//                    MessageBuffer tBuf = new MessageBuffer(nrOfFragments);
//                    tBuf.addFragment(currentFragment, bytes, messID.length() + 8 + 6);
//                    messageBuffers.put(messID, tBuf);
//
//                }
}
