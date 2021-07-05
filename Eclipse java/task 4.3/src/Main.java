import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		GardeBook gardebook = new GardeBook();
		
		String instructorName;
		String courseTitle;

		
		System.out.print("Enter Course title: ");
		courseTitle = input.nextLine();
		System.out.print("Enter Instructor name: ");
		instructorName = input.nextLine();
		
		gardebook.setterCourseTitle(courseTitle);
		gardebook.setterInstructorName(instructorName);
		gardebook.displayGradeBookInfo();
		
		//System.out.println(gardebook.getterInstructorName());		
	}
}