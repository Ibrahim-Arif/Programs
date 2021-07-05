import java.io.Serializable;

public abstract class Employee implements Serializable{
       private String fname,lname;
       private int ssn;
       private String etype;
       
    public Employee(String fname, String lname, int ssn, String e){
        this.fname = fname;
        this.lname = lname;
        this.ssn = ssn;
        this.etype = e;
    }
    
    @Override
    public String toString() {
        return "Employee name: " + getFname() + " " + getLname() + "\nSocial security number: " + getSsn();
    }
        
    public abstract double earnings();

    public String getFname() {
        return fname;
    }
    public void setFname(String fname) {
        this.fname = fname;
    }

    public String getLname() {
        return lname;
    }
    public void setLname(String lname) {
        this.lname = lname;
    }

    public int getSsn() {
        return ssn;
    }
    public void setSsn(int ssn) {
        this.ssn = ssn;
    }

    public String getEtype() {
        return etype;
    }
    public void setEtype(String etype) {
        this.etype = etype;
    }
}