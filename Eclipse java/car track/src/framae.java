import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.Graphics;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.Point;
import java.awt.Color;
import javax.swing.border.MatteBorder;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class framae extends JFrame {
	static int x =337;
	static int y =362;

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					framae frame = new framae();
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
	
	/*public void paint(Graphics g) {
		Color c2 = Color.black;         //black road
        g.setColor( c2 );
        g.fillRect(50, 100, 750, 500);
        
        Color c1 = Color.green;  
        g.setColor( c1 );  
        g.fillRect( 150, 200, 550, 300 ); //grass 
 
        g.setColor( c2 );  
        g.drawRect(50, 100, 750, 500);  // outer edge  
        g.drawRect(150, 200, 550, 300); // inner edge 
 
        Color c3 = Color.yellow;  
        g.setColor( c3 );  
        g.drawRect( 100, 150, 650, 400 ); // mid-lane marker 
        
        Color c4 = Color.white;  
        g.setColor( c4 );  
        g.drawLine( 425, 500, 425, 600 ); // start line
        
        Color c5 = Color.red;
        g.setColor(c5);
        g.fillRect(430, 510, 50, 30);
	}*/
	
	public framae() {
		setUndecorated(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 850, 650);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel panel_1 = new JPanel();
		panel_1.setBackground(Color.BLACK);
		panel_1.setBorder(new MatteBorder(1, 1, 1, 1, (Color) new Color(0, 0, 0)));
		panel_1.setBounds(50, 100, 750, 500);
		contentPane.add(panel_1);
		panel_1.setLayout(null);
		
		JPanel panel_3 = new JPanel();
		panel_3.setBounds(359, 400, 10, 100);
		panel_3.setOpaque(false);
		panel_3.setBorder(new MatteBorder(0, 0, 0, 2, (Color) new Color(255, 255, 255)));
		panel_1.add(panel_3);
		
		JPanel panel_2 = new JPanel();
		panel_2.setBounds(50, 50, 650, 400);
		panel_2.setBackground(Color.BLACK);
		panel_2.setBorder(new MatteBorder(1, 1, 1, 1, (Color) Color.YELLOW));
		panel_1.add(panel_2);
		panel_2.setLayout(null);
		
		JPanel car = new JPanel();
		car.setBackground(Color.RED);
		car.setBounds(337, 362, 30, 28);
		panel_2.add(car);
		
		JPanel panel = new JPanel();
		panel.setBounds(52, 52, 550, 300);
		panel.setBackground(Color.GREEN);
		panel_2.add(panel);
	}
}