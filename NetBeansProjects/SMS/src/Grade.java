import java.io.Serializable;

public class Grade implements Serializable{
    private String instructor;
    private int batch;
    private int number_of_subjects;
    private String grade_name;
    
    public Grade(String i, int b, int nos, String gn){
        this.instructor = i;
        this.batch = b;
        this.number_of_subjects = nos;
        this.grade_name = gn;
    }
    
    public String toString(){
        return String.format("Instructor name: %s \nBatch year: %d \nNumber of Subjects: %d \nGrade name: %s", 
                this.instructor, this.batch , this.getNumber_of_subjects(), this.getGrade_name());
    }

    public String getInstructor() {
        return instructor;
    }
    public void setInstructor(String instructor) {
        this.instructor = instructor;
    }

    public int getBatch() {
        return batch;
    }
    public void setBatch(int batch) {
        this.batch = batch;
    }   

    public int getNumber_of_subjects() {
        return number_of_subjects;
    }
    public void setNumber_of_subjects(int number_of_subjects) {
        this.number_of_subjects = number_of_subjects;
    }

    public String getGrade_name() {
        return grade_name;
    }
    public void setGrade_name(String grade_name) {
        this.grade_name = grade_name;
    }
}