/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.netbeansmodules.idlsupport;

import java.io.File;
import java.util.Observable;
import java.util.Observer;
import java.util.Vector;
import ops.Domain;
import ops.OPSConfig;
import ops.Topic;
import org.openide.loaders.MultiDataObject;
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
    public static OPSConfigNode createOPSConfigNode(OPSConfig opsConfig, OPSConfigDataObject multiDataObject)
    {
        Vector<Node> nodeVector = new Vector<Node>();
        for (Domain domain : opsConfig.getDomains())
        {
            nodeVector.add(OPSDomainNode.createDomainNode(domain));
        }
        Children children = new Children.Array();
        children.add(nodeVector.toArray(new Node[0]));
        return new OPSConfigNode(children, multiDataObject);

    }
    private final OPSConfigDataObject multiDataObject;

    public void notifyNewTopic()
    {
        multiDataObject.onConfigChange();

    }

    private OPSConfigNode(Children children, OPSConfigDataObject multiDataObject)
    {
        super(children);
        this.multiDataObject = multiDataObject;
    }



    
}
