public class Student implements Comparable<Student>{
    private String name;
    private double gradePointAverage;

    public Student(String name, double gpa){
        this.name = name;
        this.gradePointAverage = gpa;
    }

    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }

    public double getGradePointAverage() {
        return gradePointAverage;
    }
    public void setGradePointAverage(double gradePointAverage) {
        this.gradePointAverage = gradePointAverage;
    }

    public int compareTo(Student st){  
        if(this.gradePointAverage == st.getGradePointAverage()){
            return 0;  
        } else if(this.gradePointAverage > st.getGradePointAverage()){
            return 1;  
        } else{
            return -1;  
        }  
    }
    public String toString() {
        return String.format("%s GPA: %.1f", this.name, this.gradePointAverage);
    }
}