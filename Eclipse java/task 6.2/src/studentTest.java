import java.util.Scanner;
public class studentTest {
	private int id;
	private String name;
	private float cgpa;
	private String university;
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		Student ali = new Student(001,"Ali",3.2,"COMSATS");
		Student ahmad = new Student(002,"Ahmad",3.6,"COMSATS");
		Student toba = new Student(003,"Toba",3.1,"COMSATS");
		Student fatima = new Student(004,"Fatima",3.7,"COMSATS");
		
		ali.displayInfo();
		ahmad.displayInfo();
		toba.displayInfo();
		fatima.displayInfo();		
	}
}
