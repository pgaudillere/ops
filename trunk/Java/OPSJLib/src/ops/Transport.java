/*
 * Transport.java
 *
 * Created on den 11 maj 2007, 19:15
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package ops;

/**
 *
 * @author Anton Gravestam
 */
public interface Transport
{

    public boolean receive(byte[] bytes, int offset);
    void setReceiveTimeout(int millis) throws CommException;
    //void receive(byte[] b) throws ReceiveTimedOutException;
    boolean receive(byte[] b);
    void send(byte[] b);

    Event getNewBytesEvent();
    
}
