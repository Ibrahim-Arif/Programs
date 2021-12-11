public class ComissionEmployee extends Employee{    
    private double grossSales;
    private double comissionRate;

    public ComissionEmployee(String fname, String lname, int ssn, double grossSales, double comissionRate) {
        super(fname, lname, ssn,"ComissionEmployee");
        if(comissionRate < 0.0 || comissionRate > 1.0){
            System.out.println("Invalid Value!");
        }
        if(grossSales < 0.0){
            System.out.println("Invalid Value!");
        }
        this.grossSales = grossSales;
        this.comissionRate = comissionRate;
    }
    public ComissionEmployee(String fname, String lname, int ssn, double grossSales, double comissionRate, String etype) {
        super(fname, lname, ssn, etype);
        if(comissionRate < 0.0 || comissionRate > 1.0){
            System.out.println("Invalid Value!");
        }
        if(grossSales < 0.0){
            System.out.println("Invalid Value!");
        }
        this.grossSales = grossSales;
        this.comissionRate = comissionRate;
    }

    public void setGrossSales(double grossSales) {
        if(grossSales < 0.0){
            System.out.println("Invalid Value!");
        }
        this.grossSales = grossSales;
    }
    public void setComissionRate(double comissionRate) {
        if(comissionRate < 0.0 || comissionRate > 1.0){
            System.out.println("Invalid Value!");
        }
        this.comissionRate = comissionRate;
    }
    
    public double getGrossSales() {
        return grossSales;
    }
    public double getComissionRate() {
        return comissionRate;
    }
    
    @Override
    public double earnings() {
        return getComissionRate()*getGrossSales();
    }

    @Override
    public String toString() {
        return super.toString()+"\nComission Rate: "+getComissionRate()+"\nGross Sales: "+getGrossSales();
    }   
}