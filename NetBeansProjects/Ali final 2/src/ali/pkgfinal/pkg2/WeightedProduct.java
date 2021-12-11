package ali.pkgfinal.pkg2;

public class WeightedProduct extends Product{
    private double weight;
    
    public WeightedProduct(int pi, String n, double p){
        super(pi, n, p);
//        this.weight = w;
    }
    
    public String toString(){
        return String.format("PI: %d \nName: %s \nPrice: %.2f \n Weight: %d", this.getPrice(), this.getName(), this.getPrice() ,this.weight);
    }
    
    
    public double getPrice(){
        return this.weight * this.getPrice();
    }
}
