import java.io.Serializable;

public class Student implements Serializable{
    private String name;
    private String id;
    private double fee;
    private double cgpa;
    private String degree;
    private int semester;
    
    public Student(String n, String id, double fee, double gpa, String g, int s){
        this.name = n;
        this.id = id;
        this.fee = fee;
        this.cgpa = gpa;
        this.degree = g;
        this.semester = s;
    }
    
    public String toString(){
        return String.format("Name: %s \nID: %s \nFee: %.2f \nCGPA: %.2f \nGrade: %s \nSemester: %d", getName(), getId(), getFee(), getCgpa(), getDegree(), getSemester());
    }

    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }

    public String getId() {
        return id;
    }
    public void setId(String id) {
        this.id = id;
    }
    
    public double getFee() {
        return fee;
    }
    public void setFee(double fee) {
        this.fee = fee;
    }
    
    public double getCgpa() {
        return cgpa;
    }
    public void setCgpa(double cgpa) {
        this.cgpa = cgpa;
    }
    
    public String getDegree() {
        return degree;
    }public void setDegree(String degree) {
        this.degree = degree;
    }
    
    public int getSemester() {
        return semester;
    }
    public void setSemester(int semester) {
        this.semester = semester;
    }    
}