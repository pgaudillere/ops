/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.netbeansmodules.idlsupport;

import java.awt.Image;
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
                    DataFolder.findFolder (source);

            //Get its default node—we'll wrap our node around it to change the
            //display name, icon, etc:
            Node realScenesFolderNode = scenesDataObject.getNodeDelegate();

            //This FilterNode will be our project node:
            return new SourcesNode (realScenesFolderNode, project);

        } catch (DataObjectNotFoundException donfe) {
            Exceptions.printStackTrace(donfe);
            //Fallback—the directory couldn't be created -
            //read-only filesystem or something evil happened:
            return new AbstractNode (Children.LEAF);
        }

    }

    /** This is the node you actually see in the Projects window for the project */
    private static final class SourcesNode extends FilterNode {

        final OPSIDLProject project;

        public SourcesNode (Node node, OPSIDLProject project) throws DataObjectNotFoundException {
            super (node, new FilterNode.Children (node),
                    //The projects system wants the project in the Node's lookup.
                    //NewAction and friends want the original Node's lookup.
                    //Make a merge of both:
                    new ProxyLookup (new Lookup[] { Lookups.singleton(project),
                    node.getLookup() }));
            this.project = project;
        }

        @Override
        public Image getIcon(int type) {
            return ImageUtilities.loadImage (
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



    }

    @Override
    public Node findPath(Node root, Object target) {
        //leave unimplemented for now:
        return null;
    }

}

