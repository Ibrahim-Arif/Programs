package ali.pkgfinal.pkg2;

public class Product {
    private int productId;
    private String name;
    private double price;
    
    public Product(int pi, String n, double p){
        this.productId = pi;
        this.name = n;
        this.price = p;
    }
    
    public String toString(){
        return String.format("product id: %d \nName: %s \nprice: %.2f", this.getProductId(), this.getName(), this.getPrice());
    }

    public int getProductId() {
        return productId;
    }
    public void setProductId(int productId) {
        this.productId = productId;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public double getPrice() {
        return price;
    }
    public void setPrice(double price) {
        this.price = price;
    }
}
