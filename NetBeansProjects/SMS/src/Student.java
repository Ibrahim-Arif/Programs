import java.util.Date;

public class Student extends Person{
    private int reg_no;
    private int fee;
    private Grade grade;  
    
    public Student(String fn, String ln, String a, String p, String e, String gen, int reg, int fee, Grade g){
        super(fn, ln, a, p, e, gen);
        this.reg_no = reg;
        this.fee = fee;
        this.grade = g;
    }
    
    public String toString(){
        return String.format(super.toString()+ "\nReg no: %d \nFee: %d \n--- Grade Detail---\n%s",this.getReg_no(), this.getFee(), this.getGrade().toString());
    }

    public int getReg_no() {
        return reg_no;
    }
    public void setReg_no(int reg_no) {
        this.reg_no = reg_no;
    }
    
    public int getFee() {
        return fee;
    }
    public void setFee(int fee) {
        this.fee = fee;
    }

    public Grade getGrade() {
        return grade;
    }
    public void setGrade(Grade grade) {
        this.grade = grade;
    } 
}