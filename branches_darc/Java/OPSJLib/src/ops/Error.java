/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

/**
 *
 * @author Anton Gravestam
 */
public interface Error
{
    public static int BASIC_ERROR_CODE = 0;
    int getErrorCode();
    String getErrorMessage();
    String getSource();
    
}
