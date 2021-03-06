import java.util.*;
import java.sql.*;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.Color;
import javax.swing.JLabel;
import javax.swing.ImageIcon;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JTable;
import javax.swing.border.MatteBorder;
import javax.swing.JScrollPane;
import javax.swing.table.DefaultTableModel;

public class GUI extends JFrame {

	private JPanel contentPane;
	private JTextField textfield;
	static private Connection con;
	private JTable table;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					connection();
					GUI frame = new GUI();
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
	public GUI() {		
		setUndecorated(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 642, 537);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel taskbar = new JPanel();
		taskbar.setBounds(0, 0, 642, 32);
		taskbar.setForeground(Color.WHITE);
		taskbar.setBackground(Color.BLACK);
		contentPane.add(taskbar);
		taskbar.setLayout(null);
		
		JLabel exit = new JLabel("");
		exit.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				System.exit(0);
			}
		});
		exit.setBounds(607, 0, 25, 32);
		taskbar.add(exit);
		exit.setOpaque(true);
		exit.setBackground(Color.BLACK);
		exit.setForeground(Color.WHITE);
		exit.setIcon(new ImageIcon("C:\\Users\\BUGS-BUNNY\\Desktop\\Java\\task 20.1\\icons\\icons8_delete_25px.png"));
		
		JPanel workarea = new JPanel();
		workarea.setBounds(0, 33, 642, 494);
		contentPane.add(workarea);
		workarea.setLayout(null);
		
		textfield = new JTextField();
		textfield.setBounds(10, 36, 261, 41);
		textfield.setText("Enter ID to find");
		workarea.add(textfield);
		textfield.setColumns(10);
		
		JButton find = new JButton("Find");
		find.setBounds(285, 36, 85, 41);
		find.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				String search = textfield.getText();
				
			}
		});
		workarea.add(find);
		
		JButton findAll = new JButton("Find All");
		findAll.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				DefaultTableModel tm = (DefaultTableModel)table.getModel();
				try {
					Statement s = con.createStatement();
					ResultSet rs = s.executeQuery("Select * from users");
					while(rs.next()) {
						int id = rs.getInt("id");
						String name = rs.getString("name");
						String gender = rs.getString("gender");
						String phone = rs.getString("phone");
						boolean status = rs.getBoolean("status");
						System.out.println(id);
						//tm.addRow(new object[] {id,name,gender,phone,stutus});
					}
				} catch (SQLException e1) {
					e1.printStackTrace();
				}
				
			}
		});
		findAll.setBounds(380, 36, 85, 41);
		workarea.add(findAll);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(20, 485, 612, -394);
		workarea.add(scrollPane);
		
		table = new JTable();
		table.setModel(new DefaultTableModel(
			new Object[][] {
			},
			new String[] {
				"ID", "name", "gender", "contact", "status"
			}
		) {
			Class[] columnTypes = new Class[] {
				Integer.class, String.class, String.class, String.class, Boolean.class
			};
			public Class getColumnClass(int columnIndex) {
				return columnTypes[columnIndex];
			}
			boolean[] columnEditables = new boolean[] {
				true, true, false, true, false
			};
			public boolean isCellEditable(int row, int column) {
				return columnEditables[column];
			}
		});
		table.setBounds(20, 482, 612, -394);
		workarea.add(table);
	}
	
	static void connection() {
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			con = DriverManager.getConnection("jdbc:mysql://localhost:3306/infosys","root","admin");
			System.out.println("connected");
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
}
