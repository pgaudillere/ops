
package watches;

import java.awt.Color;
import java.awt.Component;
import javax.swing.JList;
import javax.swing.ListCellRenderer;

/**
 *
 * @author Anton Gravestam
 */
public class ValueWatchListRenderer implements ListCellRenderer 
{

    public Component getListCellRendererComponent(JList list, Object value, int index, boolean isSelected, boolean cellHasFocus)
    {
        if(isSelected)
            ((Component)value).setBackground(Color.lightGray);
        else
           ((Component)value).setBackground(Color.white); 
        return (Component) value;
    }

}
