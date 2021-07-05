import java.util.*;
public class editingData {
	private int roll;
	private int index;
	private float gpa;
	
	void editing() {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Roll to find: ");
		roll = input.nextInt();
		
		for(int i=0; i< student.i; i++) {
			if(roll == student.rollno[i])
				index = i;
		}
		System.out.print("New GPA: ");
		gpa = input.nextFloat();
		student.gpa[index] = gpa; 	
		
		System.out.println("Data updated successfully.");
	}
}