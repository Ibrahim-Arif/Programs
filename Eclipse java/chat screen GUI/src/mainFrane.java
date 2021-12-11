import java.sql.*;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.Color;
import javax.swing.JLabel;
import javax.swing.ImageIcon;
import javax.swing.SwingConstants;
import javax.swing.border.MatteBorder;
import javax.swing.JTextField;
import java.awt.Font;
import java.awt.SystemColor;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JScrollPane;
import java.awt.event.MouseMotionAdapter;
import java.awt.Component;
import javax.swing.ScrollPaneConstants;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import javax.swing.JScrollBar;
import java.awt.Cursor;
import java.awt.event.MouseWheelListener;
import java.awt.event.MouseWheelEvent;

public class mainFrane extends JFrame {
	String a = null;
	static int i =10;
	static int textSize=0;
	static int count;
	private static int msg_no;
	
	JLabel msg;
	private JPanel contentPane;
	private JLabel close;
	private JTextField textField;
	private JTextField searchField;
	private JLabel lblNewLabel;
	private static Connection con;


	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					connection();
					mainFrane frame = new mainFrane();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	public static void connection() {
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			con = DriverManager.getConnection("jdbc:mysql://localhost:3306/chat_screen_GUI","root","admin");
			Statement s = con.createStatement();
			ResultSet rs = s.executeQuery("select *from messages where textNo=1");
			rs.next();
			msg_no = rs.getInt("totalMsg");
			msg_no++;
			s.close();			
			//System.out.println("connected");			
		} catch (Exception e) {
			System.out.println("a");
			e.printStackTrace();
		}
	}
	/*public static void oldChat() {
		int textSize=0;
		
		try {
			Statement s = con.createStatement();
			ResultSet rs = s.executeQuery("select *from messages");
			while(rs.next()) {
				String a = rs.getString("text");
				
				JLabel msg = new JLabel(a);
				msg.setHorizontalAlignment(SwingConstants.CENTER);
				msg.setForeground(new Color(255, 255, 255));
				textSize = 9*(a.length());
				msg.setOpaque(true);
				msg.setBackground(new Color(51, 102, 255));
				msg.setBounds(10, 42, 125, 40);
				msg.setLocation(20,i);
				msg.setSize(textSize,30);
				repaint();
				panel.add(msg);
				i+=45;
				
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}*/

	/**
	 * Create the frame.
	 */
	public mainFrane() {
		
		setUndecorated(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 1061, 744);
		contentPane = new JPanel();
		contentPane.setBackground(new Color(51, 102, 153));
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		setLocation(241,62);
		
		JPanel search = new JPanel();
		search.setBackground(new Color(51, 102, 255));
		search.setBounds(80, 10, 239, 55);
		contentPane.add(search);
		search.setLayout(null);
		
		JLabel SearchPanel = new JLabel("");
		SearchPanel.setHorizontalTextPosition(SwingConstants.CENTER);
		SearchPanel.setHorizontalAlignment(SwingConstants.CENTER);
		SearchPanel.setIcon(new ImageIcon(mainFrane.class.getResource("/icons/icons8_search_30px.png")));
		SearchPanel.setBounds(188, 0, 51, 55);
		search.add(SearchPanel);
		
		searchField = new JTextField();
		searchField.setText("Search");
		searchField.setForeground(Color.WHITE);
		searchField.setFont(new Font("Arial", Font.PLAIN, 18));
		searchField.setColumns(10);
		searchField.setBorder(null);
		searchField.setBackground(new Color(51, 102, 255));
		searchField.setBounds(10, 10, 186, 35);
		search.add(searchField);
		
		JPanel userName = new JPanel();
		userName.setBorder(null);
		userName.setBackground(new Color(51, 102, 255));
		userName.setBounds(329, 0, 732, 75);
		contentPane.add(userName);
		userName.setLayout(null);
		
		close = new JLabel("");
		close.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				System.exit(0);
			}
		});
		close.setIcon(new ImageIcon(mainFrane.class.getResource("/icons/icons8_menu_vertical_30px.png")));
		close.setHorizontalTextPosition(SwingConstants.CENTER);
		close.setHorizontalAlignment(SwingConstants.CENTER);
		close.setBounds(694, 0, 38, 75);
		userName.add(close);
		
		JLabel audioCall = new JLabel("");
		audioCall.setCursor(Cursor.getPredefinedCursor(Cursor.WAIT_CURSOR));
		audioCall.setIcon(new ImageIcon(mainFrane.class.getResource("/icons/icons8_call_30px.png")));
		audioCall.setHorizontalTextPosition(SwingConstants.CENTER);
		audioCall.setHorizontalAlignment(SwingConstants.CENTER);
		audioCall.setBounds(648, 0, 48, 75);
		userName.add(audioCall);
		
		JLabel videoCall = new JLabel("");
		videoCall.setCursor(Cursor.getPredefinedCursor(Cursor.WAIT_CURSOR));
		videoCall.setIcon(new ImageIcon(mainFrane.class.getResource("/icons/icons8_video_call_30px.png")));
		videoCall.setHorizontalTextPosition(SwingConstants.CENTER);
		videoCall.setHorizontalAlignment(SwingConstants.CENTER);
		videoCall.setBounds(595, 0, 48, 75);
		userName.add(videoCall);
		
		JPanel currentUserPanel = new JPanel();
		currentUserPanel.setLayout(null);
		currentUserPanel.setBorder(null);
		currentUserPanel.setBackground(new Color(51, 102, 255));
		currentUserPanel.setBounds(0, 0, 169, 71);
		userName.add(currentUserPanel);
		
		JLabel CurrentUserIcon = new JLabel("");
		CurrentUserIcon.setIcon(new ImageIcon(mainFrane.class.getResource("/icons/icons8_user_30px.png")));
		CurrentUserIcon.setHorizontalAlignment(SwingConstants.CENTER);
		CurrentUserIcon.setBorder(null);
		CurrentUserIcon.setBounds(0, 0, 62, 71);
		currentUserPanel.add(CurrentUserIcon);
		
		JLabel CurrentUserName = new JLabel("User1");
		CurrentUserName.setForeground(Color.WHITE);
		CurrentUserName.setFont(new Font("Arial", Font.PLAIN, 18));
		CurrentUserName.setBounds(57, 10, 89, 30);
		currentUserPanel.add(CurrentUserName);
		
		JLabel typing = new JLabel("");
		typing.setForeground(Color.WHITE);
		typing.setFont(new Font("Arial", Font.PLAIN, 12));
		typing.setBounds(56, 30, 70, 20);
		currentUserPanel.add(typing);
		
		JPanel menu = new JPanel();
		menu.setBackground(new Color(51, 102, 255));
		menu.setBounds(0, 0, 70, 743);
		contentPane.add(menu);
		menu.setLayout(null);
		
		JLabel home = new JLabel("");
		home.setHorizontalAlignment(SwingConstants.CENTER);
		home.setIcon(new ImageIcon(mainFrane.class.getResource("/icons/icons8_home_50px_1.png")));
		home.setBounds(0, 238, 69, 55);
		menu.add(home);
		
		JLabel users = new JLabel("");
		users.setHorizontalAlignment(SwingConstants.CENTER);
		users.setHorizontalTextPosition(SwingConstants.LEADING);
		users.setIcon(new ImageIcon(mainFrane.class.getResource("/icons/icons8_user_50px.png")));
		users.setBounds(0, 154, 69, 55);
		menu.add(users);
		
		JLabel chatArea = new JLabel("");
		chatArea.setOpaque(true);
		chatArea.setBackground(new Color(51, 102, 153));
		chatArea.setBorder(new MatteBorder(0, 4, 0, 0, (Color) new Color(255, 255, 255)));
		chatArea.setHorizontalAlignment(SwingConstants.CENTER);
		chatArea.setIcon(new ImageIcon(mainFrane.class.getResource("/icons/icons8_chat_50px.png")));
		chatArea.setBounds(0, 329, 71, 55);
		menu.add(chatArea);
		
		JLabel star = new JLabel("");
		star.setHorizontalAlignment(SwingConstants.CENTER);
		star.setIcon(new ImageIcon(mainFrane.class.getResource("/icons/icons8_star_50px.png")));
		star.setBounds(0, 413, 69, 55);
		menu.add(star);
		
		JLabel setting = new JLabel("");
		setting.setHorizontalAlignment(SwingConstants.CENTER);
		setting.setIcon(new ImageIcon(mainFrane.class.getResource("/icons/icons8_settings_50px.png")));
		setting.setBounds(0, 501, 69, 55);
		menu.add(setting);
		
		JLabel drag = new JLabel("<-  ->");
		drag.setCursor(Cursor.getPredefinedCursor(Cursor.MOVE_CURSOR));
		drag.setFont(new Font("Tahoma", Font.PLAIN, 14));
		drag.setForeground(Color.WHITE);
		drag.setHorizontalTextPosition(SwingConstants.CENTER);
		drag.setHorizontalAlignment(SwingConstants.CENTER);
		drag.addMouseMotionListener(new MouseMotionAdapter() {
			@Override
			public void mouseDragged(MouseEvent e) {
				int coX = e.getXOnScreen();
				int coY = e.getYOnScreen();
				setLocation(coX, coY);
			}
		});
		drag.setBounds(0, 0, 69, 64);
		menu.add(drag);
		
		JPanel names = new JPanel();
		names.setBackground(new Color(51, 102, 153));
		names.setBounds(0, 0, 328, 743);
		contentPane.add(names);
		names.setLayout(null);
		
		JPanel existUserPanel = new JPanel();
		existUserPanel.setBorder(null);
		existUserPanel.setBackground(new Color(51, 102, 153));
		existUserPanel.setBounds(83, 87, 234, 71);
		names.add(existUserPanel);
		existUserPanel.setLayout(null);
		
		JLabel existUserIcon = new JLabel("");
		existUserIcon.setBorder(new MatteBorder(0, 0, 1, 0, (Color) SystemColor.activeCaptionBorder));
		existUserIcon.setBounds(0, 0, 62, 71);
		existUserPanel.add(existUserIcon);
		existUserIcon.setIcon(new ImageIcon(mainFrane.class.getResource("/icons/icons8_user_30px.png")));
		existUserIcon.setHorizontalAlignment(SwingConstants.CENTER);
		
		JLabel existUserName = new JLabel("User1");
		existUserName.setFont(new Font("Arial", Font.PLAIN, 18));
		existUserName.setForeground(new Color(255, 255, 255));
		existUserName.setBounds(57, 10, 89, 30);
		existUserPanel.add(existUserName);
		
		JLabel lblNewLabel_3 = new JLabel(" typing...");
		lblNewLabel_3.setForeground(new Color(255, 255, 255));
		lblNewLabel_3.setFont(new Font("Arial", Font.PLAIN, 12));
		lblNewLabel_3.setBounds(56, 30, 70, 20);
		existUserPanel.add(lblNewLabel_3);
		
		JPanel sendPanel = new JPanel();
		sendPanel.setBounds(329, 674, 732, 69);
		contentPane.add(sendPanel);
		sendPanel.setLayout(null);
		sendPanel.setBackground(SystemColor.controlHighlight);
		
		JLabel emoji = new JLabel("");
		emoji.setIcon(new ImageIcon(mainFrane.class.getResource("/icons/icons8_neutral_30px_1.png")));
		emoji.setOpaque(true);
		emoji.setHorizontalTextPosition(SwingConstants.CENTER);
		emoji.setHorizontalAlignment(SwingConstants.CENTER);
		emoji.setBackground(SystemColor.controlHighlight);
		emoji.setBounds(10, 10, 38, 57);
		sendPanel.add(emoji);
		
		JLabel attach = new JLabel("");
		attach.setIcon(new ImageIcon(mainFrane.class.getResource("/icons/icons8_attach_30px_2.png")));
		attach.setOpaque(true);
		attach.setHorizontalTextPosition(SwingConstants.CENTER);
		attach.setHorizontalAlignment(SwingConstants.CENTER);
		attach.setBackground(SystemColor.controlHighlight);
		attach.setBounds(51, 10, 38, 57);
		sendPanel.add(attach);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBorder(null);
		scrollPane.setBounds(329, 73, 732, 604);
		contentPane.add(scrollPane);
		
		JPanel panel = new JPanel();
		panel.setBackground(SystemColor.activeCaptionBorder);
		scrollPane.setViewportView(panel);
		
		//------------------------------------------
		try {
			Statement s = con.createStatement();
			ResultSet rs = s.executeQuery("select *from messages");
			while(rs.next()) {
				String a = rs.getString("text");
				textSize = 9*(a.length());
				
				msg = new JLabel(a);				
				msg.setHorizontalAlignment(SwingConstants.CENTER);
				msg.setForeground(new Color(255, 255, 255));
				msg.setOpaque(true);
				msg.setBackground(new Color(51, 102, 255));
				//msg.setBounds(10, 42, 125, 40);
				msg.setLocation(20,i);
				msg.setSize(textSize ,30);
				repaint();
				panel.add(msg);
				i+=45;
			}
			s.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		//------------------------------------------
		
		textField = new JTextField();
		textField.setCursor(Cursor.getPredefinedCursor(Cursor.TEXT_CURSOR));
		textField.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				//typing.setText("typing...");
				if(e.getKeyCode() == e.VK_ENTER) {
					textSize =0;
					a = textField.getText();
					count++;
					
					try {
						Statement s = con.createStatement();
						s.execute("insert into messages values ('"+a+"',"+msg_no+","+0+")");
						s.execute("update messages set totalMsg="+msg_no+" where textNo=1");
						s.close();
					} catch (SQLException e1) {
						e1.printStackTrace();
					}
					
					if(a != null) {
						msg = new JLabel(a);
						msg.setHorizontalAlignment(SwingConstants.CENTER);
						msg.setForeground(new Color(255, 255, 255));
						textSize = 9*(a.length());
						msg.setOpaque(true);
						msg.setBackground(new Color(51, 102, 255));
						//msg.setBounds(10, 42, 125, 40);
						msg.setLocation(20,i);
						msg.setSize(textSize,30);
						repaint();
						panel.add(msg);
						
						msg_no++;
						i+=45;
						textField.setText("");
						//typing.setText(null);
					}
				}
			}
		});
		textField.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				String b = textField.getText();
				if(b.equals("Type your message here"))
					textField.setText("");
			}
		});
		textField.setText("Type your message here");
		textField.setForeground(Color.BLACK);
		textField.setFont(new Font("Arial", Font.PLAIN, 18));
		textField.setColumns(10);
		textField.setBorder(new MatteBorder(0, 0, 1, 0, (Color) new Color(180, 180, 180)));
		textField.setBackground(SystemColor.controlHighlight);
		textField.setBounds(99, 10, 577, 49);
		sendPanel.add(textField);
		
		JLabel send = new JLabel("");
		send.setBounds(674, -2, 58, 69);
		sendPanel.add(send);
		send.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				
				textSize =0;
				a = textField.getText();
				
				if(a != null) {
					msg = new JLabel(a);
					msg.setHorizontalAlignment(SwingConstants.CENTER);
					msg.setForeground(new Color(255, 255, 255));
					textSize = 9*(a.length());
					msg.setOpaque(true);
					msg.setBackground(new Color(51, 102, 255));
					//msg.setBounds(10, 42, 125, 40);
					msg.setLocation(20,i);
					msg.setSize(textSize,30);
					repaint();
					panel.add(msg);
				
					i+=45;
					textField.setText("");
					//typing.setText(null);
				}
			}
		});
		send.setIcon(new ImageIcon(mainFrane.class.getResource("/icons/icons8_sent_30px_2.png")));
		send.setOpaque(true);
		send.setHorizontalTextPosition(SwingConstants.CENTER);
		send.setHorizontalAlignment(SwingConstants.CENTER);
		send.setBackground(SystemColor.controlHighlight);
	}
}
