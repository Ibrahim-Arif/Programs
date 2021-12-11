
public class viewData {
	public void view() {
		System.out.printf("Name\t\tRoll no\t\tGPA\n");
		
		for(int i=0; i<student.i; i++) {
			//System.out.println(student.name[i]+ "      "+student.rollno[i]+"      "+student.gpa[i]);
			System.out.printf("%s\t\t%d\t\t%.2f",student.name[i],student.rollno[i],student.gpa[i]);
			System.out.println();

		}
	}

}
