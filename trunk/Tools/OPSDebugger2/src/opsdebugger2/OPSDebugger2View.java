/*
 * OPSDebugger2View.java
 */
package opsdebugger2;

import configlib.exception.FormatException;
import java.awt.event.WindowEvent;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.jdesktop.application.Action;
import org.jdesktop.application.ResourceMap;
import org.jdesktop.application.SingleFrameApplication;
import org.jdesktop.application.FrameView;
import org.jdesktop.application.TaskMonitor;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import javax.swing.Timer;
import javax.swing.Icon;
import javax.swing.JDialog;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.filechooser.FileNameExtensionFilter;
import opsdebugger2.topicbrowser.TreeView;

/**
 * The application's main frame.
 */
public class OPSDebugger2View extends FrameView
{
    JFileChooser projectFileChooser = new JFileChooser();
    
    private File privateBrowseStartFile;


    public OPSDebugger2View(SingleFrameApplication app)
    {
        super(app);

        initComponents();

        projectFileChooser.setFileFilter(new FileNameExtensionFilter("OPS Debugger Project Files", "xml"));
        
        privateBrowseStartFile = new File("session.private");

        if(!privateBrowseStartFile.exists())
        {
            try
            {
                privateBrowseStartFile.createNewFile();
            } catch (IOException ex)
            {
                //Logger.getLogger(OPSDebugger2View.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        else
        {
            try
            {
                FileInputStream fis = new FileInputStream(privateBrowseStartFile);
                String homeDir = "";
                BufferedReader br = new BufferedReader(new InputStreamReader(fis));
                homeDir = br.readLine();
                projectFileChooser.setCurrentDirectory(new File(homeDir));

            } catch (IOException ex)
            {

            }

        }

        getFrame().addWindowListener(new WindowAdapter()
        {

            @Override
            public void windowClosing(WindowEvent e)
            {
                FileOutputStream fos;
                try
                {
                    fos = new FileOutputStream(privateBrowseStartFile);
                    fos.write(projectFileChooser.getCurrentDirectory().getPath().getBytes());
                } catch (IOException ex)
                {
                    
                }

                super.windowClosing(e);
            }

        });

        // status bar initialization - message timeout, idle icon and busy animation, etc
        ResourceMap resourceMap = getResourceMap();
        int messageTimeout = resourceMap.getInteger("StatusBar.messageTimeout");
        messageTimer = new Timer(messageTimeout, new ActionListener()
        {

            public void actionPerformed(ActionEvent e)
            {
                statusMessageLabel.setText("");
            }
        });
        messageTimer.setRepeats(false);
        int busyAnimationRate = resourceMap.getInteger("StatusBar.busyAnimationRate");
        for (int i = 0; i < busyIcons.length; i++)
        {
            busyIcons[i] = resourceMap.getIcon("StatusBar.busyIcons[" + i + "]");
        }
        busyIconTimer = new Timer(busyAnimationRate, new ActionListener()
        {

            public void actionPerformed(ActionEvent e)
            {
                busyIconIndex = (busyIconIndex + 1) % busyIcons.length;
                statusAnimationLabel.setIcon(busyIcons[busyIconIndex]);
            }
        });
        idleIcon = resourceMap.getIcon("StatusBar.idleIcon");
        statusAnimationLabel.setIcon(idleIcon);
        progressBar.setVisible(false);

        // connecting action tasks to status bar via TaskMonitor
        TaskMonitor taskMonitor = new TaskMonitor(getApplication().getContext());
        taskMonitor.addPropertyChangeListener(new java.beans.PropertyChangeListener()
        {

            public void propertyChange(java.beans.PropertyChangeEvent evt)
            {
                String propertyName = evt.getPropertyName();
                if ("started".equals(propertyName))
                {
                    if (!busyIconTimer.isRunning())
                    {
                        statusAnimationLabel.setIcon(busyIcons[0]);
                        busyIconIndex = 0;
                        busyIconTimer.start();
                    }
                    progressBar.setVisible(true);
                    progressBar.setIndeterminate(true);
                }
                else
                {
                    if ("done".equals(propertyName))
                    {
                        busyIconTimer.stop();
                        statusAnimationLabel.setIcon(idleIcon);
                        progressBar.setVisible(false);
                        progressBar.setValue(0);
                    }
                    else
                    {
                        if ("message".equals(propertyName))
                        {
                            String text = (String) (evt.getNewValue());
                            statusMessageLabel.setText((text == null) ? "" : text);
                            messageTimer.restart();
                        }
                        else
                        {
                            if ("progress".equals(propertyName))
                            {
                                int value = (Integer) (evt.getNewValue());
                                progressBar.setVisible(true);
                                progressBar.setIndeterminate(false);
                                progressBar.setValue(value);
                            }
                        }
                    }
                }
            }
        });
        
        
        
    }

    @Action
    public void showAboutBox()
    {
        if (aboutBox == null)
        {
            JFrame mainFrame = OPSDebugger2App.getApplication().getMainFrame();
            aboutBox = new OPSDebugger2AboutBox(mainFrame);
            aboutBox.setLocationRelativeTo(mainFrame);
        }
        OPSDebugger2App.getApplication().show(aboutBox);
    }

    TreeView getTreeView()
    {
        return treeView1;
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        mainPanel = new javax.swing.JPanel();
        jTabbedPane1 = new javax.swing.JTabbedPane();
        jScrollPane1 = new javax.swing.JScrollPane();
        subscribeTopicDebugger1 = new opsdebugger2.topicdebuggers.SubscribeTopicDebugger();
        jScrollPane2 = new javax.swing.JScrollPane();
        publishTopicDebugger1 = new opsdebugger2.topicdebuggers.PublishTopicDebugger();
        jScrollPane3 = new javax.swing.JScrollPane();
        watchesMainPanel1 = new watches.WatchesMainPanel();
        plotterMainPanel1 = new opsdebugger2.tabpanels.plotter.PlotterMainPanel();
        treeView1 = new opsdebugger2.topicbrowser.TreeView();
        menuBar = new javax.swing.JMenuBar();
        javax.swing.JMenu fileMenu = new javax.swing.JMenu();
        javax.swing.JMenuItem exitMenuItem = new javax.swing.JMenuItem();
        jMenuItem1 = new javax.swing.JMenuItem();
        javax.swing.JMenu helpMenu = new javax.swing.JMenu();
        javax.swing.JMenuItem aboutMenuItem = new javax.swing.JMenuItem();
        statusPanel = new javax.swing.JPanel();
        javax.swing.JSeparator statusPanelSeparator = new javax.swing.JSeparator();
        statusMessageLabel = new javax.swing.JLabel();
        statusAnimationLabel = new javax.swing.JLabel();
        progressBar = new javax.swing.JProgressBar();

        mainPanel.setName("mainPanel"); // NOI18N

        jTabbedPane1.setName("jTabbedPane1"); // NOI18N

        jScrollPane1.setName("jScrollPane1"); // NOI18N

        subscribeTopicDebugger1.setName("subscribeTopicDebugger1"); // NOI18N
        jScrollPane1.setViewportView(subscribeTopicDebugger1);

        org.jdesktop.application.ResourceMap resourceMap = org.jdesktop.application.Application.getInstance(opsdebugger2.OPSDebugger2App.class).getContext().getResourceMap(OPSDebugger2View.class);
        jTabbedPane1.addTab(resourceMap.getString("jScrollPane1.TabConstraints.tabTitle"), jScrollPane1); // NOI18N

        jScrollPane2.setName("jScrollPane2"); // NOI18N

        publishTopicDebugger1.setName("publishTopicDebugger1"); // NOI18N
        publishTopicDebugger1.setLayout(new java.awt.FlowLayout(java.awt.FlowLayout.LEFT));
        jScrollPane2.setViewportView(publishTopicDebugger1);

        jTabbedPane1.addTab(resourceMap.getString("jScrollPane2.TabConstraints.tabTitle"), jScrollPane2); // NOI18N

        jScrollPane3.setName("jScrollPane3"); // NOI18N

        watchesMainPanel1.setName("watchesMainPanel1"); // NOI18N
        jScrollPane3.setViewportView(watchesMainPanel1);

        jTabbedPane1.addTab(resourceMap.getString("jScrollPane3.TabConstraints.tabTitle"), jScrollPane3); // NOI18N

        plotterMainPanel1.setName("plotterMainPanel1"); // NOI18N
        jTabbedPane1.addTab(resourceMap.getString("plotterMainPanel1.TabConstraints.tabTitle"), plotterMainPanel1); // NOI18N

        treeView1.setName("treeView1"); // NOI18N

        javax.swing.GroupLayout mainPanelLayout = new javax.swing.GroupLayout(mainPanel);
        mainPanel.setLayout(mainPanelLayout);
        mainPanelLayout.setHorizontalGroup(
            mainPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, mainPanelLayout.createSequentialGroup()
                .addGap(10, 10, 10)
                .addComponent(jTabbedPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 509, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(treeView1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(14, 14, 14))
        );
        mainPanelLayout.setVerticalGroup(
            mainPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(mainPanelLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(mainPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(treeView1, javax.swing.GroupLayout.DEFAULT_SIZE, 693, Short.MAX_VALUE)
                    .addComponent(jTabbedPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 693, Short.MAX_VALUE))
                .addContainerGap())
        );

        menuBar.setName("menuBar"); // NOI18N

        fileMenu.setText(resourceMap.getString("fileMenu.text")); // NOI18N
        fileMenu.setName("fileMenu"); // NOI18N

        javax.swing.ActionMap actionMap = org.jdesktop.application.Application.getInstance(opsdebugger2.OPSDebugger2App.class).getContext().getActionMap(OPSDebugger2View.class, this);
        exitMenuItem.setAction(actionMap.get("quit")); // NOI18N
        exitMenuItem.setName("exitMenuItem"); // NOI18N
        fileMenu.add(exitMenuItem);

        jMenuItem1.setText(resourceMap.getString("jMenuItem1.text")); // NOI18N
        jMenuItem1.setName("jMenuItem1"); // NOI18N
        jMenuItem1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem1ActionPerformed(evt);
            }
        });
        fileMenu.add(jMenuItem1);

        menuBar.add(fileMenu);

        helpMenu.setText(resourceMap.getString("helpMenu.text")); // NOI18N
        helpMenu.setName("helpMenu"); // NOI18N

        aboutMenuItem.setAction(actionMap.get("showAboutBox")); // NOI18N
        aboutMenuItem.setName("aboutMenuItem"); // NOI18N
        helpMenu.add(aboutMenuItem);

        menuBar.add(helpMenu);

        statusPanel.setName("statusPanel"); // NOI18N

        statusPanelSeparator.setName("statusPanelSeparator"); // NOI18N

        statusMessageLabel.setName("statusMessageLabel"); // NOI18N

        statusAnimationLabel.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);
        statusAnimationLabel.setName("statusAnimationLabel"); // NOI18N

        progressBar.setName("progressBar"); // NOI18N

        javax.swing.GroupLayout statusPanelLayout = new javax.swing.GroupLayout(statusPanel);
        statusPanel.setLayout(statusPanelLayout);
        statusPanelLayout.setHorizontalGroup(
            statusPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(statusPanelSeparator, javax.swing.GroupLayout.DEFAULT_SIZE, 897, Short.MAX_VALUE)
            .addGroup(statusPanelLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(statusMessageLabel)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 727, Short.MAX_VALUE)
                .addComponent(progressBar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(statusAnimationLabel)
                .addContainerGap())
        );
        statusPanelLayout.setVerticalGroup(
            statusPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(statusPanelLayout.createSequentialGroup()
                .addComponent(statusPanelSeparator, javax.swing.GroupLayout.PREFERRED_SIZE, 2, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(statusPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(statusMessageLabel)
                    .addComponent(statusAnimationLabel)
                    .addComponent(progressBar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(3, 3, 3))
        );

        setComponent(mainPanel);
        setMenuBar(menuBar);
        setStatusBar(statusPanel);
    }// </editor-fold>//GEN-END:initComponents

    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_jMenuItem1ActionPerformed
    {//GEN-HEADEREND:event_jMenuItem1ActionPerformed
        // TODO add your handling code here:
        if(projectFileChooser.showOpenDialog(mainPanel) == JFileChooser.APPROVE_OPTION)
        {
            File selectedFile = projectFileChooser.getSelectedFile();
            try
            {
                OPSDebugger2App.getApplication().setActiveProject(new DebuggerProject(selectedFile));
            } catch (FileNotFoundException ex)
            {
                JOptionPane.showMessageDialog(mainPanel, "File was not found.");
            } catch (FormatException ex)
            {
                JOptionPane.showMessageDialog(mainPanel, "File could not be loaded.");
            } catch (IOException ex)
            {
                JOptionPane.showMessageDialog(mainPanel, "File could not be read.");
            }
        }
    }//GEN-LAST:event_jMenuItem1ActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JTabbedPane jTabbedPane1;
    private javax.swing.JPanel mainPanel;
    private javax.swing.JMenuBar menuBar;
    private opsdebugger2.tabpanels.plotter.PlotterMainPanel plotterMainPanel1;
    private javax.swing.JProgressBar progressBar;
    private opsdebugger2.topicdebuggers.PublishTopicDebugger publishTopicDebugger1;
    private javax.swing.JLabel statusAnimationLabel;
    private javax.swing.JLabel statusMessageLabel;
    private javax.swing.JPanel statusPanel;
    private opsdebugger2.topicdebuggers.SubscribeTopicDebugger subscribeTopicDebugger1;
    private opsdebugger2.topicbrowser.TreeView treeView1;
    private watches.WatchesMainPanel watchesMainPanel1;
    // End of variables declaration//GEN-END:variables
    private final Timer messageTimer;
    private final Timer busyIconTimer;
    private final Icon idleIcon;
    private final Icon[] busyIcons = new Icon[15];
    private int busyIconIndex = 0;
    private JDialog aboutBox;

    
}
