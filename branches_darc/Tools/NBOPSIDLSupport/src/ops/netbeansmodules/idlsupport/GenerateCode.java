/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ops.netbeansmodules.idlsupport;

import org.netbeans.api.project.Project;
import org.openide.nodes.Node;
import org.openide.util.HelpCtx;
import org.openide.util.NbBundle;
import org.openide.util.actions.CookieAction;

public final class GenerateCode extends CookieAction
{

    protected void performAction(Node[] activatedNodes)
    {
        Project project = activatedNodes[0].getLookup().lookup(Project.class);
    // TODO use project
    }

    protected int mode()
    {
        return CookieAction.MODE_EXACTLY_ONE;
    }

    public String getName()
    {
        return NbBundle.getMessage(GenerateCode.class, "CTL_GenerateCode");
    }

    protected Class[] cookieClasses()
    {
        return new Class[]
                {
                    Project.class
                };
    }

    @Override
    protected String iconResource()
    {
        return "ops/netbeansmodules/idlsupport/opsgenerate.GIF";
    }

    public HelpCtx getHelpCtx()
    {
        return HelpCtx.DEFAULT_HELP;
    }

    @Override
    protected boolean asynchronous()
    {
        return false;
    }
}

