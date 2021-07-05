package ServerClient;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import java.awt.GridLayout;
import com.jgoodies.forms.layout.FormLayout;
import com.jgoodies.forms.layout.ColumnSpec;
import com.jgoodies.forms.layout.RowSpec;
import net.miginfocom.swing.MigLayout;
import java.awt.Color;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JDialog;

import java.awt.SystemColor;
import java.awt.Toolkit;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.ActionEvent;
import javax.swing.JScrollPane;
import javax.swing.JPopupMenu;
import java.awt.Component;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JPasswordField;
import java.awt.Cursor;
import javax.swing.UIManager;
import javax.swing.border.LineBorder;
import javax.swing.DebugGraphics;
import javax.swing.border.MatteBorder;
import java.awt.Rectangle;
import javax.swing.ImageIcon;

public class welcome extends JDialog {

	private JPanel contentPane;
	private static String name =null;
	private static String pass =null;
	private JLabel nothing;
	private JPasswordField password;
	private JLabel Wuser;


	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					welcome frame = new welcome();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	public void close() {
		WindowEvent winClosingEvent = new WindowEvent(this,WindowEvent.WINDOW_CLOSING);
		Toolkit.getDefaultToolkit().getSystemEventQueue().postEvent(winClosingEvent); 
	}

	/**
	 * Create the frame.
	 */
	public welcome() {
		super();
		setUndecorated(true);
		setModal(true);
		
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 381, 300);
		contentPane = new JPanel();
		contentPane.setBackground(new Color(30, 144, 255));
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Welcome to Message Man");
		lblNewLabel.setBounds(97, 10, 170, 25);
		lblNewLabel.setBackground(Color.WHITE);
		lblNewLabel.setForeground(Color.WHITE);
		lblNewLabel.setFont(new Font("Californian FB", Font.ITALIC, 20));
		contentPane.add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("Username:");
		lblNewLabel_1.setBounds(74, 87, 77, 32);
		lblNewLabel_1.setForeground(Color.LIGHT_GRAY);
		lblNewLabel_1.setFont(new Font("Calibri", Font.PLAIN, 14));
		contentPane.add(lblNewLabel_1);
		
		JTextField username = new JTextField();
		username.setBounds(74, 104, 232, 34);
		username.setForeground(Color.WHITE);
		username.setBorder(new MatteBorder(0, 0, 1, 0, (Color) new Color(255, 255, 255)));
		username.setOpaque(false);
		username.setFont(new Font("Calibri", Font.PLAIN, 15));
		contentPane.add(username);
		username.setColumns(10);
		
		JLabel lblNewLabel_2 = new JLabel("Password:");
		lblNewLabel_2.setBounds(74, 158, 77, 32);
		lblNewLabel_2.setForeground(Color.LIGHT_GRAY);
		lblNewLabel_2.setFont(new Font("Calibri", Font.PLAIN, 14));
		contentPane.add(lblNewLabel_2);
		
		JButton submit = new JButton("Sign In");
		submit.setForeground(new Color(255, 255, 224));
		submit.setBounds(137, 236, 93, 25);
		submit.setBorder(new MatteBorder(1, 1, 1, 1, (Color) new Color(255, 255, 255)));
		submit.setDebugGraphicsOptions(DebugGraphics.NONE_OPTION);
		submit.setAlignmentX(Component.RIGHT_ALIGNMENT);
		submit.setCursor(Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR));
		submit.setContentAreaFilled(false);
		submit.setFont(new Font("Arial", Font.PLAIN, 14));
		submit.setBackground(new Color(230, 230, 250));
		submit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				name = username.getText();
				pass = password.getText();
				
				if(name.equals("ibrahim")) {
					Wuser.setText("");
					
					if(pass.equals("1122")) {
						serverFrame.myName = name;
						close();
					}
					else
						nothing.setText("wrong password");
				}
				else {
					Wuser.setText("wrong username");
				}
			}
		});
		contentPane.add(submit);
		
		JLabel lblNewLabel_3 = new JLabel("");
		lblNewLabel_3.setIcon(new ImageIcon(welcome.class.getResource("/icons/icons8_male_user_30px_3.png")));
		lblNewLabel_3.setBounds(171, 36, 40, 40);
		lblNewLabel_3.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 16));
		contentPane.add(lblNewLabel_3);
		
		nothing = new JLabel("");
		nothing.setFont(new Font("Tahoma", Font.PLAIN, 10));
		nothing.setForeground(new Color(220, 20, 60));
		nothing.setBounds(221, 166, 85, 13);
		contentPane.add(nothing);
		
		Wuser = new JLabel("");
		Wuser.setForeground(new Color(220, 20, 60));
		Wuser.setFont(new Font("Tahoma", Font.PLAIN, 10));
		Wuser.setBounds(221, 95, 85, 13);
		contentPane.add(Wuser);
		
		password = new JPasswordField();
		password.setBounds(74, 172, 232, 32);
		password.setBorder(new MatteBorder(0, 0, 1, 0, (Color) Color.WHITE));
		password.setFont(new Font("Tahoma", Font.PLAIN, 13));
		password.setForeground(Color.WHITE);
		password.setOpaque(false);
		contentPane.add(password);
		
		JLabel lblX = new JLabel("");
		lblX.setIcon(new ImageIcon(welcome.class.getResource("/icons/icons8_delete_20px_2.png")));
		lblX.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				System.exit(0);
			}
		});
		lblX.setForeground(new Color(255, 255, 224));
		lblX.setFont(new Font("Segoe UI", Font.BOLD, 6));
		lblX.setBounds(351, 3, 30, 32);
		contentPane.add(lblX);
	}
	public String getName() {
		return name;
	}
	private static void addPopup(Component component, final JPopupMenu popup) {
		component.addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent e) {
				if (e.isPopupTrigger()) {
					showMenu(e);
				}
			}
			public void mouseReleased(MouseEvent e) {
				if (e.isPopupTrigger()) {
					showMenu(e);
				}
			}
			private void showMenu(MouseEvent e) {
				popup.show(e.getComponent(), e.getX(), e.getY());
			}
		});
	}
}
