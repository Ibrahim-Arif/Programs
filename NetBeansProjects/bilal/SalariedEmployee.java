public class SalariedEmployee extends Employee{
    private double weeklySalary;

    public SalariedEmployee(String fname, String lname, int ssn,double weeklySalary) {
        super(fname, lname, ssn,"SalariedEmployee");
        if(weeklySalary < 0.0){
            System.out.println("Invalid value!");
        }else
            this.weeklySalary = weeklySalary;
    }

    public double getWeeklySalary() {
        return weeklySalary;
    }
    public void setWeeklySalary(double weeklySalary) {
        if(weeklySalary < 0.0){
            System.out.println("Invalid value!");
        }
        this.weeklySalary = weeklySalary;
    }
    
    @Override
    public double earnings() {
        return getWeeklySalary();
    }

    @Override
    public String toString() {
        return super.toString()+"\nWeekly Salary: "+getWeeklySalary();
    }   
}