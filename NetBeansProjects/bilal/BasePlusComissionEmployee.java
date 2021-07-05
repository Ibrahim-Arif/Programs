public class BasePlusComissionEmployee extends ComissionEmployee {
    private double baseSalary;

    public BasePlusComissionEmployee( String fname, String lname, int ssn, double grossSales, double comissionRate, double baseSalary) {
        super(fname, lname, ssn, grossSales, comissionRate,"BasePlusComissionEmployee");
        if(baseSalary < 0.0){
            System.out.println("Invalid Value!");
        }
        this.baseSalary = baseSalary;
    }

    public double getBaseSalary() {
        return baseSalary;
    }
    public void setBaseSalary(double baseSalary) {
        this.baseSalary = baseSalary;
    }
    
    @Override
    public double earnings(){
        return getBaseSalary()*super.earnings();
    }

    @Override
    public String toString() {
        return super.toString()+" Base Salary: "+getBaseSalary();
    }   
}