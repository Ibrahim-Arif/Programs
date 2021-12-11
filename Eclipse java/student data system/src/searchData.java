import java.util.*;
public class searchData {
	private int roll;
	private int index;
	
	public void search() {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Roll to find: ");
		roll = input.nextInt();
		
		for(int i=0; i< student.i; i++) {
			if(roll == student.rollno[i])
				index = i;
		}
		System.out.printf("Name\t\tRoll no\t\tGPA\n");
		System.out.printf("%s\t\t%d\t\t%.2f",student.name[index],student.rollno[index],student.gpa[index]);
		System.out.println();

		
	}
}
