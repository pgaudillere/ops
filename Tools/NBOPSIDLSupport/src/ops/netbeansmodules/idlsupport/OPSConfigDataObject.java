/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.netbeansmodules.idlsupport;

import configlib.exception.FormatException;
import java.awt.event.ActionEvent;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Arrays;
import java.util.Vector;
import javax.swing.AbstractAction;
import javax.swing.Action;
import ops.OPSConfig;
import org.openide.filesystems.FileObject;
import org.openide.filesystems.FileUtil;
import org.openide.loaders.DataNode;
import org.openide.loaders.DataObjectExistsException;
import org.openide.loaders.MultiDataObject;
import org.openide.loaders.MultiFileLoader;
import org.openide.nodes.CookieSet;
import org.openide.nodes.Node;
import org.openide.nodes.Children;
import org.openide.util.Exceptions;
import org.openide.util.Lookup;
import org.openide.text.DataEditorSupport;

public class OPSConfigDataObject extends MultiDataObject
{
    private FileObject file;
    private OPSConfig opsConfig;

    public OPSConfigDataObject(FileObject pf, MultiFileLoader loader) throws DataObjectExistsException, IOException
    {
        super(pf, loader);

        this.file = pf;
        CookieSet cookies = getCookieSet();
        cookies.add((Node.Cookie) DataEditorSupport.create(this, getPrimaryEntry(), cookies));
    }

    @Override
    public void setModified(boolean arg0)
    {
        super.setModified(arg0);
        System.out.println("Set modiefied called on OPSConfigDataObject " + arg0);
    }

    public void onConfigChange()
    {
        try
        {
            OPSConfig.saveConfig(opsConfig, FileUtil.toFile(file));
        } catch (FileNotFoundException ex)
        {
            Exceptions.printStackTrace(ex);
        } catch (IOException ex)
        {
            Exceptions.printStackTrace(ex);
        }

    }

    @Override
    protected Node createNodeDelegate()
    {
        try
        {
            opsConfig = OPSConfig.getConfig(FileUtil.toFile(file));
            Children.Array children = new Children.Array();
            children.add(new Node[]{OPSConfigNode.createOPSConfigNode(opsConfig, this)});
            DataNode dNode = new OPSConfigDataNode(this, children, getLookup());

            return dNode;
        }
        catch (FormatException ex)
        {
            Exceptions.printStackTrace(ex);
            return new OPSConfigDataNode(this, Children.LEAF, getLookup());
        }
        catch (IOException ex)
        {
            Exceptions.printStackTrace(ex);
            return new OPSConfigDataNode(this, Children.LEAF, getLookup());
        }
        catch(NullPointerException e)
        {
            return new OPSConfigDataNode(this, Children.LEAF, getLookup());
        }
    }

    @Override
    public Lookup getLookup()
    {
        return getCookieSet().getLookup();
    }
}
class OPSConfigDataNode extends DataNode
{
    MultiDataObject multiDataObject;
    OPSConfigDataNode(MultiDataObject dObject, Children children, Lookup lookup)
    {
        super(dObject, children, lookup);
        multiDataObject = dObject;

    }



    @Override
    public Action[] getActions(boolean arg0)
    {

        Vector<Action> actions = new Vector(Arrays.asList(super.getActions(arg0)));//new Vector<Action>();
        
        actions.add(new AbstractAction("Add topic...") {

            public void actionPerformed(ActionEvent e)
            {
                System.out.println("Add topic pressed");
            }
        });

        return actions.toArray(new Action[0]);

    }


}
