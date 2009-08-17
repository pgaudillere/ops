/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.netbeansmodules.idlsupport;

import java.awt.Image;
import java.awt.event.ActionEvent;
import java.beans.PropertyChangeListener;
import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JOptionPane;
import ops.netbeansmodules.idlsupport.projectproperties.PropertiesDialog;
import org.netbeans.spi.project.ui.LogicalViewProvider;
import org.openide.filesystems.FileObject;
import org.openide.loaders.DataFolder;
import org.openide.loaders.DataObjectNotFoundException;
import org.openide.nodes.AbstractNode;
import org.openide.nodes.Children;
import org.openide.nodes.FilterNode;
import org.openide.nodes.Node;
import org.openide.util.Exceptions;
import org.openide.util.ImageUtilities;
import org.openide.util.Lookup;
import org.openide.util.actions.SystemAction;
import org.openide.util.lookup.Lookups;
import org.openide.util.lookup.ProxyLookup;

/**
 *
 * @author angr
 */
class OPSIDLProjectLogicalView implements LogicalViewProvider {

    private final OPSIDLProject project;

    public OPSIDLProjectLogicalView(OPSIDLProject project) {
        this.project = project;
    }

    public org.openide.nodes.Node createLogicalView() {

        try {

            //Get the scenes directory, creating it if deleted:
            FileObject source = project.getSourceFolder(true);

            //Get the DataObject that represents it:
            DataFolder scenesDataObject =
                    DataFolder.findFolder(source);

            //Get its default node—we'll wrap our node around it to change the
            //display name, icon, etc:
            Node realScenesFolderNode = scenesDataObject.getNodeDelegate();

            //This FilterNode will be our project node:
            return new SourcesNode(realScenesFolderNode, project);

        } catch (DataObjectNotFoundException donfe) {
            Exceptions.printStackTrace(donfe);
            //Fallback—the directory couldn't be created -
            //read-only filesystem or something evil happened:
            return new AbstractNode(Children.LEAF);
        }

    }

    /** This is the node you actually see in the Projects window for the project */
    private final class SourcesNode extends FilterNode {

        final OPSIDLProject project;

        public SourcesNode(Node node, OPSIDLProject project) throws DataObjectNotFoundException {
            super(node, new FilterNode.Children(node),
                    //The projects system wants the project in the Node's lookup.
                    //NewAction and friends want the original Node's lookup.
                    //Make a merge of both:
                    new ProxyLookup(new Lookup[]{Lookups.singleton(project),
                        node.getLookup()}));
            this.project = project;
        }

        @Override
        public Image getIcon(int type) {
            return ImageUtilities.loadImage(
                    "ops/netbeansmodules/idlsupport/opsprojecticon.GIF");
        }

        @Override
        public Image getOpenedIcon(int type) {
            return getIcon(type);
        }

        @Override
        public String getDisplayName() {
            return project.getProjectDirectory().getName();
        }

        @Override
        public Action[] getActions(boolean selected)
        {
            Action[] actions = new Action[super.getActions(selected).length + 1];

            for (int i = 0; i < super.getActions(selected).length; i++)
            {
//                if(super.getActions(selected)[i].getValue("props").equals("Properties"))
//                {
//                    super.getActions(selected)[i] = new AbstractAction("Properties") {
//
//                        public void actionPerformed(ActionEvent e) {
//                            System.out.println("Properties action...");
//                        }
//                    };
//                }
//                System.out.println("" + super.getActions(selected)[i]);
                actions[i] = super.getActions(selected)[i];
            }
            actions[super.getActions(selected).length] = new AbstractAction("Build") {

                public void actionPerformed(ActionEvent e) {
                    project.build();
                }
            };
            actions[super.getActions(selected).length] = new AbstractAction("Properties") {

                public void actionPerformed(ActionEvent e) {
                    showProjectPropertiesDialog();
                }


            };

            return actions;



        }
    }
    private void showProjectPropertiesDialog()
    {
        PropertiesDialog propDialog = new PropertiesDialog(null, true, project.getProperties(), project.getProjectDirectory().getPath());
        propDialog.setVisible(true);
    }

    @Override
    public Node findPath(Node root, Object target) {
        //leave unimplemented for now:
        return null;
    }
}

