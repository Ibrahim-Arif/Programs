import java.awt.BorderLayout;
import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import java.awt.Color;
import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class frame extends JFrame {
	fact fact = new fact();

	private JPanel contentPane;
	private JTextField tf;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					frame frame = new frame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public frame() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 545, 320);
		contentPane = new JPanel();
		contentPane.setBackground(new Color(102, 205, 170));
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Number:");
		lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 13));
		lblNewLabel.setBounds(73, 52, 101, 26);
		contentPane.add(lblNewLabel);
		
		tf = new JTextField();
		tf.setBounds(184, 57, 178, 19);
		contentPane.add(tf);
		tf.setColumns(10);
		
		JButton btnNewButton = new JButton("Factorial");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//fact.value = Integer.parseInt(tf.getText());
				fact.orig = Integer.parseInt(tf.getText());
				fact.factorial();
				JOptionPane.showMessageDialog(null, "The factorial: "+fact.value);
				fact.value =1;
			}
		});
		btnNewButton.setBounds(182, 135, 85, 21);
		contentPane.add(btnNewButton);
		
		JButton btnNewButton_1 = new JButton("---");
		btnNewButton_1.setBounds(277, 135, 85, 21);
		contentPane.add(btnNewButton_1);
	}
}