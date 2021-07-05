package ServerClient;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.awt.event.ActionEvent;
import java.awt.Font;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;
import java.awt.Color;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.SystemColor;
import javax.swing.border.MatteBorder;
import javax.swing.ImageIcon;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class clientFrame extends JFrame {
	static private Socket socket		 	= null; 
	static private DataInputStream in 		= null; 
	static private DataOutputStream out		= null;
	static private String outgoing 			= ""; 
	static private String incoming 			= "";
	static String myName					= null;
	static private String hisName			= null;

	static private JPanel contentPane;
	static private JTextArea textArea;
	static private JTextField msgText;
	static private JButton send;
	private JLabel close;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {	
		clientWelcome w = new clientWelcome();
		w.setVisible(true);
		client();
	}

	
	public static void client() {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					clientFrame frame = new clientFrame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
		
		try {
			socket = new Socket("localhost",5009);
			JOptionPane.showMessageDialog(null, "connected");
			
			in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
			hisName = in.readUTF();
			
			out = new DataOutputStream(socket.getOutputStream());
			out.writeUTF(myName);
			
		
			while(!outgoing.equals("over")) {
				try {
					incoming = in.readUTF();
					textArea.setText(textArea.getText()+"\n"+hisName+": "+incoming);
				}catch(IOException i) {
					i.printStackTrace();
					break;
				}catch(NullPointerException e2) {
					e2.printStackTrace();
					break;
				}
			}
		}catch(IOException i) {
			i.printStackTrace();
		}
		 catch(NullPointerException e2) {
			e2.printStackTrace();
		}
		
		try {
			textArea.setText(textArea.getText()+" \nDisconnected");
			socket.close();
			in.close();
			out.close();
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	
	public clientFrame() {
		setUndecorated(true);
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 742, 506);
		contentPane = new JPanel();
		contentPane.setBackground(new Color(119, 136, 153));
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		//****************************************
		
		msgText = new JTextField();
		msgText.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				int key = e.getKeyCode();
				if(key == KeyEvent.VK_ENTER) {
					try {
						//System.out.println(myName);
						outgoing = msgText.getText();
						out.writeUTF(outgoing);
						msgText.setText("");
						textArea.setText(textArea.getText()+"\n"+myName+": " +outgoing);
					} catch (IOException e1) {
						e1.printStackTrace();
					} catch(NullPointerException e2) {
						e2.printStackTrace();
					}
				}
			}
		});
		msgText.setBackground(new Color(169, 169, 169));
		msgText.setFont(new Font("Arial", Font.PLAIN, 18));
		msgText.setBounds(10, 444, 614, 52);
		contentPane.add(msgText);
		msgText.setColumns(10);
		
		send = new JButton("");
		send.setOpaque(false);
		send.setIcon(new ImageIcon(clientFrame.class.getResource("/icons/icons8_sent_30px.png")));
		send.setBackground(new Color(119, 136, 153));
		send.setFont(new Font("Tahoma", Font.BOLD, 30));
		send.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					outgoing = msgText.getText();
					out.writeUTF(outgoing);
					msgText.setText("");
					textArea.setText(textArea.getText()+"\n"+myName+": "+outgoing);
				} catch (IOException e1) {
					e1.printStackTrace();
				} catch(NullPointerException e2) {
					e2.printStackTrace();
				}
			}
		});
		send.setBounds(634, 444, 85, 52);
		contentPane.add(send);
		
		JLabel lblNewLabel = new JLabel(myName);
		lblNewLabel.setForeground(SystemColor.info);
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setFont(new Font("Arial", Font.PLAIN, 22));
		lblNewLabel.setBounds(283, 10, 184, 29);
		contentPane.add(lblNewLabel);
		
		close = new JLabel("");
		close.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				System.exit(0);
			}
		});
		close.setIcon(new ImageIcon(clientFrame.class.getResource("/icons/icons8_delete_20px_2.png")));
		close.setBounds(692, 10, 26, 29);
		contentPane.add(close);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setForeground(new Color(255, 255, 255));
		scrollPane.setBackground(new Color(255, 255, 255));
		scrollPane.setBounds(10, 47, 709, 387);
		contentPane.add(scrollPane);
		
		textArea = new JTextArea();
		textArea.setOpaque(false);
		scrollPane.setViewportView(textArea);
		textArea.setBorder(new MatteBorder(1, 1, 1, 1, (Color) Color.WHITE));
		textArea.setBackground(new Color(255, 255, 224));
		textArea.setFont(new Font("Monospaced", Font.PLAIN, 16));
	}
}
