public class Course {
    private int courseReferenceNumber;
    private int creditHours;
    private String courseName;
    private String instructor;
    
    public Course(int crn, int ch, String cn, String i){
        this.courseReferenceNumber = crn;
        this.creditHours = ch;
        this.courseName = cn;
        this.instructor = i;
    }
    
    public String toString(){
        return "Course: " + courseName
                + "\nInstructor: " + instructor
                + "\nCRN: " + courseReferenceNumber
                + "\nCredit Hours: " + creditHours;
    }
}

