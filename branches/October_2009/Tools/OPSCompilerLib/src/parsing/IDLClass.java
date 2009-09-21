/*
 * IDLClass.java
 *
 * Created on den 12 november 2007, 08:18
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package parsing;

import java.util.ArrayList;

/**
 *
 * @author angr
 */
public class IDLClass
{
    private String packageName;
    private String className;
    private String baseClassName;
    private ArrayList<IDLField> fields;
    /** Creates a new instance of IDLClass */
    public IDLClass(String className, String packageName, ArrayList<IDLField> fields)
    {
        this.className = className;
        this.packageName = packageName;
        this.fields = fields;
    }
    
    public IDLClass(String className, String packageName)
    {
        this(className, packageName, new ArrayList<IDLField>());
    }
    public IDLClass()
    {
        this(null, null, new ArrayList<IDLField>());
    }

    public void addIDLField(IDLField f)
    {
        fields.add(f);
    }
    public String getPackageName()
    {
        return packageName;
    }

    public void setPackageName(String packageName)
    {
        this.packageName = packageName;
    }

    public String getClassName()
    {
        return className;
    }

    public void setClassName(String className)
    {
        this.className = className;
    }

    public ArrayList<IDLField> getFields()
    {
        return fields;
    }

    public void setFields(ArrayList<IDLField> fields)
    {
        this.fields = fields;
    }

    public void setBaseClassName(String bcName)
    {
        baseClassName = bcName;
    }
    public String getBaseClassName()
    {
        return baseClassName;
    }
    
}
