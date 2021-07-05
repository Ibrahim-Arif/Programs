import java.awt.Component;

import javax.swing.JOptionPane;
public class welcome {

	public static void main(String[] args) {
		
		JOptionPane.showMessageDialog(null, "Welcome to JAVA");
		String name = JOptionPane.showInputDialog("What is your name: ");
		/*String message = String.format("Name: %s", name);*/
		String message = String.format("Welcome \'%s\' to JAVA GUI", name);
		JOptionPane.showMessageDialog(null, message);
	}
}