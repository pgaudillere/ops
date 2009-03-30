/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops;

/**
 *
 * @author angr
 */
public class MessageBuffer
{
    private byte[] messageBytes;
    private boolean[] fragmentComplete;

    static int fragmentSize = StaticManager.MAX_SIZE;

    public MessageBuffer(int nrFragments)
    {
        messageBytes = new byte[nrFragments * fragmentSize];
        fragmentComplete = new boolean[nrFragments];
    }

    public void addFragment(int fragmentNr, byte[] fragBytes, int dataStart)
    {
        if(!fragmentComplete[fragmentNr])
        {
            int index = fragmentSize * fragmentNr;
            System.arraycopy(fragBytes, dataStart, messageBytes, index, fragBytes.length - dataStart);
            fragmentComplete[fragmentNr] = true;
        }
    }
    public boolean isComplete()
    {
        for (boolean b : fragmentComplete)
        {
            if(!b)
            {
                return false;
            }
        }
        return true;
    }

    public byte[] getBytes()
    {
        return messageBytes;

    }



}
