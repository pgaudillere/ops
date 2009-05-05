/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package opsdebugger2.tabpanels.plotter;

import java.awt.Color;
import java.awt.Stroke;
import java.util.Vector;

/**
 *
 * @author angr
 */
public class PlotSettings
{
    public final static double RAD_TO_DEG = 180.0 / Math.PI ;
    public final static double DEG_TO_RAD = Math.PI / 180.0 ;
    public final static double KNOTS_TO_MS = 1 ;
    public final static double MS_TO_KNOTS = 1 ;
    public final static double KPH_TO_MS = 1 ;
    public final static double MS_TO_KPH = 1 ;
    
    public Stroke stroke;
    public Color color;
    public String nickname;
    public double scaleFactor;
    public double transform;
    public double translatation;
    Vector<String> keyVec = new Vector<String>();
   
}
