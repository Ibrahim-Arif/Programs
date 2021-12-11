public class HourlyEmployee extends Employee{
    private double wage,hour;

    public HourlyEmployee(String fname, String lname, int ssn,double wage, double hour) {
        super(fname, lname, ssn, "HourlyEmployee");
        if(wage < 0.0 || hour < 0.0){
            System.out.println("Invalid Value!");
        }
        this.wage = wage;
        this.hour = hour;
    }

    public double getWage() {
        return wage;
    }
    public double getHour() {
        return hour;
    }

    public void setWage(double wage) {
        this.wage = wage;
    }
    public void setHour(double hour) {
        this.hour = hour;
    }
    
    @Override
    public double earnings() {
        if(getHour() <= 40)
           return getWage()*getHour();
        else
           return 40*getWage()*(getHour()-40)*getWage()*1.5;
    }

    @Override
    public String toString() {
        return super.toString()+"\nHours: "+getHour()+" "+"Wage: "+getWage();
    }   
}