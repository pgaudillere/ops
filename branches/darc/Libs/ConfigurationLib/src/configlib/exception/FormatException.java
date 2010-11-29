
package configlib.exception;

/**
 *
 * @author Anton Gravestam
 */
public class FormatException extends Exception
{

    public FormatException(String message)
    {
        super(message);
    }

    public FormatException()
    {
        super("FormatException");
    }
    

}
