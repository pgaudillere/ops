/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops;

/**
 *
 * @author staxgr
 */
public interface Sender
{
    boolean sendTo(byte[] bytes, String ip, int port);
    boolean sendTo(byte[] bytes, int offset, int size, String ip, int port);
}
