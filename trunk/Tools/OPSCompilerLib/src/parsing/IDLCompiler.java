package parsing;

import java.util.Vector;

/**
 *
 * @author angr
 */
public interface IDLCompiler
{
    //TODO: public void compileProject
    public void compileDataClasses(final Vector<IDLClass> idlClasses, final String projectDirectory);
    public void compileTopicConfig(final Vector<TopicInfo> topics, final String name, final String packageString, final String projectDirectory);
    public String getName();
}
