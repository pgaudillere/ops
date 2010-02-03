/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

/**
 *
 * @author Anton Gravestam
 */
class BasicError implements Error
{
    private final String className;
    private final String methodName;
    private final String errorMessage;

    BasicError(String className, String methodName, String errorMessage)
    {
        this.className = className;
        this.methodName = methodName;
        this.errorMessage = errorMessage;

    }

    public int getErrorCode()
    {
        return Error.BASIC_ERROR_CODE;
    }

    public String getErrorMessage()
    {
        return errorMessage;
    }

    public String getSource()
    {
        return className + "." + methodName + "()";
    }

}
