/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops;

/**
 *
 * @author Anton Gravestam
 */
class ReceiveTimedOutException extends Exception
{
    public ReceiveTimedOutException(String message)
    {
        super(message);
    }
}
