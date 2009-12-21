/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ops.netbeansmodules.idlsupport;

import java.awt.event.ActionEvent;
import java.util.Arrays;
import java.util.Vector;
import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JOptionPane;
import ops.Domain;
import ops.Topic;
import org.openide.nodes.AbstractNode;
import org.openide.nodes.Children;
import org.openide.nodes.Node;
import org.openide.util.actions.SystemAction;

/**
 *
 * @author angr
 */
class OPSDomainNode extends AbstractNode
{

    public static OPSDomainNode createDomainNode(Domain domain)
    {

        Vector<Node> nodeVector = new Vector<Node>();
        for (Topic topic : domain.getTopics())
        {
            nodeVector.add(OPSTopicNode.createTopicNode(topic));
        }
        Children children = new Children.Array();
        children.add(nodeVector.toArray(new Node[0]));
        return new OPSDomainNode(children, domain);
    }

    private Domain domain;
    private OPSDomainNode(Children children, Domain domain)
    {
        super(children);
        setName(domain.getDomainID());
        this.domain = domain;
    }

    @Override
    public Action[] getActions(boolean main)
    {
        Vector<Action> actions = new Vector<Action>(Arrays.asList(super.getActions(main)));

        actions.add(new AbstractAction("Add Topic...") {

            public void actionPerformed(ActionEvent e)
            {
                String topicToCreate = JOptionPane.showInputDialog("Enter topic Name:");
                if(topicToCreate != null)
                {
                    if(!topicToCreate.equals(""))
                    {
                        Topic topic = new Topic(topicToCreate, 1000, "Hatt.hatt", "234.4.5.6");
                        domain.getTopics().add(topic);
                        ((OPSConfigNode)getParentNode()).notifyNewTopic();
                    }
                }

            }
        });
        actions.add(new AbstractAction("Open Topic Tool...") {

            public void actionPerformed(ActionEvent e)
            {
                for (Topic topic : domain.getTopics())
                {
                    System.out.println("" + topic);

                }

            }
        });

        return actions.toArray(new Action[0]);


    }



}
