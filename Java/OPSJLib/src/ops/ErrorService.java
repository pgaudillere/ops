/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

/**
 *
 * @author Anton Gravestam
 */
class ErrorService extends Notifier<Error>
{
    public void report(Error error)
    {
        notifyListeners(error);
    }
    public void report(String className, String methodName, String errorMessage)
    {
        report(new BasicError(className, methodName, errorMessage));

    }
}
