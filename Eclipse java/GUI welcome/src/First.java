import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.Color;
import javax.swing.JButton;
import javax.swing.JList;
import javax.swing.JTextField;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import java.awt.GridLayout;
import java.awt.FlowLayout;
import javax.swing.BoxLayout;
import javax.swing.SpringLayout;
import net.miginfocom.swing.MigLayout;
import com.jgoodies.forms.layout.FormLayout;
import com.jgoodies.forms.layout.ColumnSpec;
import com.jgoodies.forms.layout.FormSpecs;
import com.jgoodies.forms.layout.RowSpec;
import java.awt.CardLayout;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;

public class First extends JFrame {

	private JPanel contentPane;
	private JLabel lblWelcome;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					First frame = new First();
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
	public First() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBackground(new Color(144, 238, 144));
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		
		JButton btnClick = new JButton("click");
		btnClick.setBounds(5, 5, 0, 0);
		btnClick.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				lblWelcome.setText("You clicked, bitch");
			}
		});
		
		JLabel label_1 = new JLabel("");
		label_1.setBounds(5, 5, 0, 0);
		
		JLabel label_3 = new JLabel("");
		label_3.setBounds(5, 5, 0, 0);
		
		JLabel label_4 = new JLabel("");
		label_4.setBounds(5, 5, 0, 0);
		
		JLabel lblNewLabel = new JLabel("Welcome");
		lblNewLabel.setBounds(5, 5, 0, 0);
		lblNewLabel.setBackground(Color.RED);
		lblNewLabel.setForeground(new Color(255, 255, 255));
		lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 17));
		
		JLabel label_2 = new JLabel("");
		label_2.setBounds(5, 5, 0, 0);
		
		JLabel label = new JLabel("");
		label.setBounds(5, 5, 0, 0);
		
		JLabel label_5 = new JLabel("");
		label_5.setBounds(5016, 5028, 426, 253);
		contentPane.setLayout(null);
		contentPane.add(label_1);
		contentPane.add(label_3);
		contentPane.add(label_4);
		contentPane.add(lblNewLabel);
		contentPane.add(btnClick);
		contentPane.add(label_2);
		contentPane.add(label);
		contentPane.add(label_5);
		
		lblWelcome = new JLabel("WELCOME");
		lblWelcome.setFont(new Font("Tahoma", Font.PLAIN, 16));
		lblWelcome.setBounds(166, 41, 213, 66);
		contentPane.add(lblWelcome);
		
		JButton btnClick_1 = new JButton("click");
		btnClick_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				lblWelcome.setText("You clicked, bitch.");
			}
		});
		btnClick_1.setFont(new Font("Tahoma", Font.PLAIN, 12));
		btnClick_1.setBounds(166, 173, 85, 21);
		contentPane.add(btnClick_1);
	}
}
