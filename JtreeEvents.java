import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.tree.*;
/* <applet code="JTreeEvents" width=400 height=200>
</applet> */
public class JTreeEvents extends JApplet 
{
JTree tree;
JTextField jtf;
public void init() 
{
Container contentPane = getContentPane();
contentPane.setLayout(new BorderLayout());
DefaultMutableTreeNode top = new DefaultMutableTreeNode("Options");
DefaultMutableTreeNode a = new DefaultMutableTreeNode("A");
top.add(a);
DefaultMutableTreeNode a1 = new DefaultMutableTreeNode("A1");
a.add(a1);
DefaultMutableTreeNode a2 = new DefaultMutableTreeNode("A2");
a.add(a2);
DefaultMutableTreeNode b = new DefaultMutableTreeNode("B");
top.add(b);
DefaultMutableTreeNode b1 = new DefaultMutableTreeNode("B1");
b.add(b1);
DefaultMutableTreeNode b2 = new DefaultMutableTreeNode("B2");
b.add(b2);
DefaultMutableTreeNode b3 = new DefaultMutableTreeNode("B3");
b.add(b3);
tree = new JTree(top);
int v = ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED;
int h = ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED;
JScrollPane jsp = new JScrollPane(tree, v, h);
contentPane.add(jsp, BorderLayout.CENTER);
jtf = new JTextField("", 20);
contentPane.add(jtf, BorderLayout.SOUTH);
tree.addMouseListener(new MouseAdapter() 
{
public void mouseClicked(MouseEvent me) 
{
doMouseClicked(me);
}
});
}
void doMouseClicked(MouseEvent me) 
{
TreePath tp = tree.getPathForLocation(me.getX(), me.getY());
if(tp != null)
jtf.setText(tp.toString());
else
jtf.setText("");
}
}
