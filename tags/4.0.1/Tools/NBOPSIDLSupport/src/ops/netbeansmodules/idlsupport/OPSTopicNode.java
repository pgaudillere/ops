/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.netbeansmodules.idlsupport;

import java.awt.Component;
import ops.Topic;
import org.openide.nodes.AbstractNode;
import org.openide.nodes.Children;

/**
 *
 * @author angr
 */
class OPSTopicNode extends AbstractNode
{
    public static OPSTopicNode createTopicNode(Topic topic)
    {
       
        return new OPSTopicNode(Children.LEAF, topic);
    }

    public OPSTopicNode(Children children, Topic topic)
    {
        super(children);
        setName(topic.getName());

    }





}
