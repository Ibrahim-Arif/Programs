import java.util.*;
public class newData {
	private int roll;
	private float gpa;
	private String name;
	
	public void data() {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Name: ");
		name = input.nextLine();
		System.out.print("Roll no: ");
		roll = input.nextInt();
		System.out.print("Gpa: ");
		gpa = input.nextFloat();
		
		student.name[student.i] = name; 
		student.rollno[student.i] = roll; 
		student.gpa[student.i] = gpa; 
		
		student.i++;
	}

}
