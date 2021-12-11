package calculator;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;
import java.awt.Color;
import javax.swing.SwingConstants;
import java.awt.SystemColor;
import javax.swing.JRadioButton;


public class gui extends JFrame {
	value v = new value();

	private JPanel contentPane;
	private JTextField tf;
	private JButton point;
	private JButton n0;
	private JButton equal;
	private JButton n2;
	private JButton n3;
	private JButton plus;
	private JButton n4;
	private JButton n5;
	private JButton n6;
	private JButton minus;
	private JButton n7;
	private JButton n8;
	private JButton n9;
	private JButton multiply;
	private JButton divide;
	private JButton clear;
	private JButton n1;
	private JButton blackSlash;
	private JRadioButton off;
	private JRadioButton on;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					gui frame = new gui();
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
	public gui() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 437, 518);
		contentPane = new JPanel();
		contentPane.setForeground(new Color(0, 0, 0));
		contentPane.setBackground(new Color(192, 192, 192));
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		tf = new JTextField();
		tf.setFont(new Font("Tahoma", Font.BOLD, 18));
		tf.setHorizontalAlignment(SwingConstants.RIGHT);
		tf.setBounds(42, 34, 347, 58);
		contentPane.add(tf);
		tf.setColumns(10);
		
		point = new JButton(".");
		point.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(tf.getText() + ".");
				v.decimalFlag=1;
				v.StringInput += ".";
			}
		});
		point.setFont(new Font("Tahoma", Font.BOLD, 15));
		point.setBounds(42, 404, 60, 46);
		contentPane.add(point);
		
		n0 = new JButton("0");
		n0.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(tf.getText() + "0");
				v.val(0);
				v.StringInput += "0";
			}
		});
		n0.setFont(new Font("Tahoma", Font.BOLD, 15));
		n0.setBounds(139, 404, 60, 46);
		contentPane.add(n0);
		
		equal = new JButton("=");
		equal.setFont(new Font("Tahoma", Font.BOLD, 15));
		equal.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				v.decide();
				tf.setText("");
				tf.setText(tf.getText() + v.result);
				v.StringInput = String.valueOf(v.result);
			}
		});
		equal.setBounds(235, 404, 154, 46);
		contentPane.add(equal);
		
		plus = new JButton("+");
		plus.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(tf.getText() + "+");
				if(v.flag == 0) {
					v.first = v.value;
				}
				v.value =0;
				v.flag =4;
				v.StringInput += "+";
								
			}
		});
		plus.setFont(new Font("Tahoma", Font.BOLD, 15));
		plus.setBounds(329, 338, 60, 46);
		contentPane.add(plus);
		
		n1 = new JButton("1");
		n1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(tf.getText() + "1");
				v.val(1);
				v.StringInput += "1";
				
			}
		});
		n1.setFont(new Font("Tahoma", Font.BOLD, 15));
		n1.setBounds(42, 338, 60, 46);
		contentPane.add(n1);
		
		n2 = new JButton("2");
		n2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(tf.getText() + "2");
				v.val(2);
				v.StringInput += "2";
			}
		});
		n2.setFont(new Font("Tahoma", Font.BOLD, 15));
		n2.setBounds(139, 338, 60, 46);
		contentPane.add(n2);
		
		n3 = new JButton("3");
		n3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(tf.getText() + "3");
				v.val(3);
				v.StringInput += "3";
			}
		});
		n3.setFont(new Font("Tahoma", Font.BOLD, 15));
		n3.setBounds(235, 338, 60, 46);
		contentPane.add(n3);
		
		minus = new JButton("-");
		minus.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(tf.getText() + "-");
				if(v.flag == 0) {
					v.first = v.value;
				}
				v.value =0;
				v.flag =3;
				v.StringInput += "-";
			}
		});
		minus.setFont(new Font("Tahoma", Font.BOLD, 15));
		minus.setBounds(329, 263, 60, 46);
		contentPane.add(minus);
		
		n4 = new JButton("4");
		n4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(tf.getText() + "4");
				v.val(4);
				v.StringInput += "4";
			}
		});
		n4.setFont(new Font("Tahoma", Font.BOLD, 15));
		n4.setBounds(42, 263, 60, 46);
		contentPane.add(n4);
		
		n5 = new JButton("5");
		n5.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(tf.getText() + "5");
				v.val(5);
				v.StringInput += "5";
			}
		});
		n5.setFont(new Font("Tahoma", Font.BOLD, 15));
		n5.setBounds(139, 263, 60, 46);
		contentPane.add(n5);
		
		n6 = new JButton("6");
		n6.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(tf.getText() + "6");
				v.val(6);
				v.StringInput += "6";
			}
		});
		n6.setFont(new Font("Tahoma", Font.BOLD, 15));
		n6.setBounds(235, 263, 60, 46);
		contentPane.add(n6);
		
		multiply = new JButton("x");
		multiply.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(tf.getText() + "x");
				if(v.flag == 0) {
					v.first = v.value;
				}
				v.value =0;
				v.flag =2;
				v.StringInput += "x";
			}
		});
		multiply.setFont(new Font("Tahoma", Font.BOLD, 15));
		multiply.setBounds(329, 192, 60, 46);
		contentPane.add(multiply);
		
		n7 = new JButton("7");
		n7.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(tf.getText() + "7");
				v.val(7);
				v.StringInput += "7";
				}
		});
		n7.setFont(new Font("Tahoma", Font.BOLD, 15));
		n7.setBounds(42, 192, 60, 46);
		contentPane.add(n7);
		
		n8 = new JButton("8");
		n8.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(tf.getText() + "8");
				v.val(8);
				v.StringInput += "8";
			}
		});
		n8.setFont(new Font("Tahoma", Font.BOLD, 15));
		n8.setBounds(139, 192, 60, 46);
		contentPane.add(n8);
		
		n9 = new JButton("9");
		n9.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(tf.getText() + "9");
				v.val(9);
				v.StringInput += "9";
			}
		});
		n9.setFont(new Font("Tahoma", Font.BOLD, 15));
		n9.setBounds(235, 192, 60, 46);
		contentPane.add(n9);
		
		divide = new JButton("/");
		divide.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(tf.getText() + "/");
				if(v.flag == 0) {
					v.first = v.value;
				}
				v.value =0;
				v.flag =1;
				v.StringInput += "/";
			}
		});
		divide.setFont(new Font("Tahoma", Font.BOLD, 15));
		divide.setBounds(329, 115, 60, 46);
		contentPane.add(divide);
		
		JLabel lblNewLabel = new JLabel("Made by: Ibrahim Arif");
		lblNewLabel.setForeground(Color.DARK_GRAY);
		lblNewLabel.setFont(new Font("Calibri Light", Font.BOLD | Font.ITALIC, 13));
		lblNewLabel.setBounds(10, 10, 117, 27);
		contentPane.add(lblNewLabel);
		
		clear = new JButton("C");
		clear.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				v.value=0;
				v.first=0;
				v.result=0;
				v.firstTimeFlag=0;
				v.decimalFlag=0;
				v.flag=0;
				v.StringInput = "";
				tf.setText("");
			}
		});
		clear.setFont(new Font("Tahoma", Font.BOLD, 15));
		clear.setBounds(235, 115, 60, 46);
		contentPane.add(clear);
		
		blackSlash = new JButton("<-");
		blackSlash.setFont(new Font("Tahoma", Font.BOLD, 15));
		blackSlash.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				v.value = ((int) v.value/10);
				tf.setText(v.remove(v.StringInput));
				v.StringInput = v.remove(v.StringInput);
			}
		});
		blackSlash.setBounds(139, 115, 60, 46);
		contentPane.add(blackSlash);
		
		on = new JRadioButton("ON");
		on.setSelected(true);
		on.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				abled();
			}
		});
		on.setBounds(42, 115, 60, 21);
		contentPane.add(on);
		
		
		off = new JRadioButton("OFF");
		off.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				disabled();
			}
		});
		off.setBounds(42, 140, 60, 21);
		contentPane.add(off);
		
		on.setEnabled(false); // for default on button should be disabled
		ButtonGroup btngrp = new ButtonGroup();
		btngrp.add(on);
		btngrp.add(off);
	}
	
	public void disabled() {
		on.setEnabled(true);
		off.setEnabled(false);
		
		tf.setEnabled(false);
		n0.setEnabled(false);
		n1.setEnabled(false);
		n2.setEnabled(false);
		n3.setEnabled(false);
		n4.setEnabled(false);
		n5.setEnabled(false);
		n6.setEnabled(false);
		n7.setEnabled(false);
		n8.setEnabled(false);
		n9.setEnabled(false);
		point.setEnabled(false);
		divide.setEnabled(false);
		multiply.setEnabled(false);
		minus.setEnabled(false);
		plus.setEnabled(false);
		equal.setEnabled(false);
		clear.setEnabled(false);
		blackSlash.setEnabled(false);
	}
	public void abled() {
		on.setEnabled(false);
		off.setEnabled(true);
		
		tf.setEnabled(true);
		n0.setEnabled(true);
		n1.setEnabled(true);
		n2.setEnabled(true);
		n3.setEnabled(true);
		n4.setEnabled(true);
		n5.setEnabled(true);
		n6.setEnabled(true);
		n7.setEnabled(true);
		n8.setEnabled(true);
		n9.setEnabled(true);
		point.setEnabled(true);
		divide.setEnabled(true);
		multiply.setEnabled(true);
		minus.setEnabled(true);
		plus.setEnabled(true);
		equal.setEnabled(true);
		clear.setEnabled(true);
		blackSlash.setEnabled(true);
	}
}
