package ali.pkgfinal.pkg2;

public class CountedProduct extends Product{
    private int quantity;
    
    public CountedProduct(int pi, String n, double p){
        super(pi, n, p);
//        this.quantity = q;
    }
    
    public String toString(){
        return String.format("PI: %d \nName: %s \nPrice: %.2f \n quantity: %d", this.getPrice(), this.getName(), this.getPrice() ,this.quantity);
    }
    
    public double getPrice(){
        return this.quantity * this.getPrice();
    }
}
