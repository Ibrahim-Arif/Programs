public class GardeBook {
	private String instructorName;
	private String courseTitle;
	
	void setterInstructorName(String IN) {
		instructorName = IN;
	}
	String getterInstructorName() {
		return instructorName;
	}
	
	void setterCourseTitle(String CT) {
		courseTitle = CT;
	}
	String getterCourseTitle() {
		return courseTitle;
	}
	
	void displayGradeBookInfo() {
		System.out.println("Course name is: "+courseTitle);
		System.out.println("Instructor name is: "+instructorName);
	}
}