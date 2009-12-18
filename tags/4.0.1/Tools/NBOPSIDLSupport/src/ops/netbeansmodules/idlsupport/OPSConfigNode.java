/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.netbeansmodules.idlsupport;

import java.io.File;
import java.util.Vector;
import ops.Domain;
import ops.OPSConfig;
import ops.Topic;
import org.openide.nodes.AbstractNode;
import org.openide.nodes.Children;
import org.openide.nodes.Node;
import org.openide.util.actions.SystemAction;

/**
 *
 * @author angr
 */
class OPSConfigNode extends AbstractNode
{
    public static OPSConfigNode createOPSConfigNode(OPSConfig opsConfig)
    {
        Vector<Node> nodeVector = new Vector<Node>();
        for (Domain domain : opsConfig.getDomains())
        {
            nodeVector.add(OPSDomainNode.createDomainNode(domain));
        }
        Children children = new Children.Array();
        children.add(nodeVector.toArray(new Node[0]));
        return new OPSConfigNode(children);

    }

    private OPSConfigNode(Children children)
    {
        super(children);
    }

    
}
