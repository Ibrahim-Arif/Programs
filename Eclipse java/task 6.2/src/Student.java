public class Student {
	private int id;
	private String name;
	private double cgpa;
	private String university;
	
	public Student(int idd, String namee, double c, String uni) {
		id = idd;
		name = namee;
		cgpa = c;
		university = uni;
	}
	
	public void displayInfo() {
		System.out.println("ID: "+id+"\tName: "+name+"\tCGPA: "+cgpa+"\tUniversity: "+university);
	}
}
