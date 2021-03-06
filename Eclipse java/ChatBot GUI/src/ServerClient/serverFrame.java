package ServerClient;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollBar;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JDialog;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.awt.event.ActionEvent;
import java.awt.Font;
import java.awt.Toolkit;
import java.awt.Window;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;
import java.awt.Color;
import javax.swing.border.MatteBorder;
import javax.swing.text.DefaultCaret;

import java.awt.SystemColor;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import javax.swing.ImageIcon;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JScrollPane;

public class serverFrame extends JFrame {

	static private ServerSocket ss 			= null;
	static private Socket socket		 	= null; 
	static private DataInputStream in 		= null; 
	static private DataOutputStream out		= null;
	static private String outgoing 			= ""; 
	static private String incoming 			= "";
	static		   String myName			= null;
	static private String hisName			= null;

	static private JPanel contentPane;
	static private JTextArea textArea;
	
	static private JTextField msgText;
	static private JButton send;
	private JLabel label;

	public static void main(String[] args) {	
		welcome w = new welcome();
		w.setVisible(true);
		
		server();
	}
	public static void server() {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					serverFrame frame = new serverFrame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
		
		try {
			ss = new ServerSocket(5009);
			try {
				JOptionPane.showMessageDialog(null, "Server Started \nWaiting for client...");
			} catch(NullPointerException n) {
				
			}
			socket = ss.accept();
			out = new DataOutputStream(socket.getOutputStream());
			out.writeUTF(myName);
			
			in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
			hisName = in.readUTF();	
			
			
			while(!incoming.equals("over")) {
				try {
					incoming = in.readUTF();
					//System.out.println(incoming);
					textArea.setText(textArea.getText()+"\n"+hisName+": "+incoming);
					//textArea.setText(textArea.getText()+"\nClient: "+incoming);
				}catch(IOException i) {
					
				} catch(NullPointerException e2) {
					e2.printStackTrace();
				}
			}
		}catch(IOException i) {
			
		}
		 catch(NullPointerException e2) {
				e2.printStackTrace();
		}
		
		try {
			textArea.setText(textArea.getText()+" \nDisconnected");
			ss.close();
			socket.close();
			out.close();
			in.close();
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
	public void close() {
		WindowEvent winClosingEvent = new WindowEvent(this,WindowEvent.WINDOW_CLOSING);
		Toolkit.getDefaultToolkit().getSystemEventQueue().postEvent(winClosingEvent); 
	}

	public serverFrame() {
		setUndecorated(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 731, 509);
		contentPane = new JPanel();
		contentPane.setBackground(new Color(119, 136, 153));
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
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
		send.setIcon(new ImageIcon(serverFrame.class.getResource("/icons/icons8_sent_30px.png")));
		send.setOpaque(false);
		send.setBackground(new Color(255, 255, 255));
		send.setFont(new Font("Tahoma", Font.BOLD, 30));
		send.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
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
		});
		send.setBounds(634, 444, 85, 52);
		contentPane.add(send);
		
		JLabel lblNewLabel = new JLabel(myName);
		lblNewLabel.setForeground(new Color(255, 255, 255));
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setFont(new Font("Arial", Font.PLAIN, 22));
		lblNewLabel.setBounds(271, 10, 184, 29);
		contentPane.add(lblNewLabel);
		
		label = new JLabel("");
		label.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				System.exit(0);
			}
		});
		label.setIcon(new ImageIcon(serverFrame.class.getResource("/icons/icons8_delete_20px_2.png")));
		label.setBounds(695, 10, 26, 29);
		contentPane.add(label);
		
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
}}
