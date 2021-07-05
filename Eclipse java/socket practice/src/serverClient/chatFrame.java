package serverClient;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Font;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.Color;

public class chatFrame extends JFrame {

	private JPanel contentPane;
	private JTextField msgText;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					chatFrame frame = new chatFrame();
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
	public chatFrame() {
		Server server = new Server();
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 742, 543);
		contentPane = new JPanel();
		contentPane.setBackground(new Color(128, 0, 128));
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JTextArea textArea = new JTextArea();
		textArea.setBackground(new Color(255, 255, 240));
		textArea.setFont(new Font("Monospaced", Font.PLAIN, 16));
		textArea.setBounds(10, 49, 708, 385);
		contentPane.add(textArea);
		
		msgText = new JTextField();
		msgText.setBackground(new Color(221, 160, 221));
		msgText.setFont(new Font("Tahoma", Font.PLAIN, 18));
		msgText.setBounds(10, 444, 614, 52);
		contentPane.add(msgText);
		msgText.setColumns(10);
		
		JButton send = new JButton(">");
		send.setBackground(new Color(128, 0, 128));
		send.setFont(new Font("Tahoma", Font.BOLD, 30));
		send.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			}
		});
		send.setBounds(634, 444, 85, 52);
		contentPane.add(send);
		
		JLabel lblNewLabel = new JLabel("Server");
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setFont(new Font("Arial", Font.PLAIN, 22));
		lblNewLabel.setBounds(271, 10, 184, 29);
		contentPane.add(lblNewLabel);
	}
}
