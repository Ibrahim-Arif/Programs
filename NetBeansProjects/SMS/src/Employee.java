import java.util.Date;

public class Employee extends Person{
    private int id;
    private double pay;
    
    public Employee(String fn, String ln, String a, String p, String e, String g, int id, double pay){
        super(fn, ln, a, p, e, g);
        this.id = id;
        this.pay = pay;
    }
    
    public String toString(){
        return String.format(super.toString()+ "\nID: %d \nPay: %.2f ", this.getId(), this.getPay());
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }

    public double getPay() {
        return pay;
    }
    public void setPay(double pay) {
        this.pay = pay;
    }
}