/**
*
* Copyright (C) 2006-2009 Anton Gravestam.
*
* This file is part of OPS (Open Publish Subscribe).
*
* OPS (Open Publish Subscribe) is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* OPS (Open Publish Subscribe) is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with OPS (Open Publish Subscribe).  If not, see <http://www.gnu.org/licenses/>.
*/
package ops;

import java.io.IOException;
import java.net.DatagramPacket;
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

    private boolean hasSubscribers;
    private boolean hasPublishers;
    private HashMap<String, MessageBuffer> messageBuffers = new HashMap<String, MessageBuffer>();
    private Topic topic;
    private Transport transport;
    private Vector<Subscriber> subscribers = new Vector<Subscriber>();
    private ObserverImpl bytesListener = new ObserverImpl();
    private Participant participant;
    private int expectedFragment = 0;
    private int fragmentSize;
    private final byte[] bytes;
    private byte[] trimmedBytes;
    private int byteOffset = 0;
    private static int FRAGMENT_HEADER_SIZE = 14;

    public TopicHandler(Topic t, Participant part)
    {
        bytes = new byte[t.getSampleMaxSize()];
        trimmedBytes = new byte[t.getSampleMaxSize()];
        participant = part;
        topic = t;
        MulticastDomain domain = (MulticastDomain) participant.getConfig().getDomain(topic.getDomainID());
        fragmentSize = StaticManager.MAX_SIZE;
        transport = new MulticastTransport(t.getDomainAddress(), t.getPort(), domain.getLocalInterface());


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


    private synchronized void onNewBytes(DatagramPacket p)
    {
        try
        {
            
            //System.arraycopy(bytes, expectedFragment*fragmentSize, by, 0, p.getLength());
            ReadByteBuffer readBuf = new ReadByteBuffer(bytes, expectedFragment*fragmentSize, fragmentSize);

            if (readBuf.checkProtocol())
            {
                int nrOfFragments = readBuf.readint();
                int currentFragment = readBuf.readint();

                if(currentFragment == (nrOfFragments - 1) && currentFragment == expectedFragment)
                {
                    //We have received a full message, let's deserialize it and send it to subscribers.
                    //First we trim the bytes to remove all fragment headers. Note, unlike in C++.
                    ReadByteBuffer.trimSegments(bytes, fragmentSize, FRAGMENT_HEADER_SIZE, trimmedBytes);
                    sendBytesToSubscribers(new ReadByteBuffer(trimmedBytes));
                    expectedFragment = 0;

                }
                else if(currentFragment == expectedFragment)
                {
                    expectedFragment++;
                }
                else
                {
                    //Sample will be lost here, add error handling
                    System.out.println("___________________Fragment error, sample lost__________________");
                    expectedFragment = 0;
                }
            }

        } catch (IOException ex)
        {
            expectedFragment = 0;
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

        Thread thread = new Thread(new Runnable()
        {

            public void run()
            {
                while (hasSubscribers)
                {
                    boolean recOK = transport.receive(bytes, expectedFragment*fragmentSize);
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
            onNewBytes((DatagramPacket) arg);
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
