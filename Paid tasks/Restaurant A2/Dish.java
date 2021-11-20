public class Dish {
    private String name;
    private double price;
    
    public Dish(String name, double price){
        this.name = name;
        this.price = price;
    }
    
    public String getName(){
        return this.name;
    }
    public double getPrice(){
        return this.price;
    }
    
    public String toString(){
        return String.format("%s - %.2f CAD", this.name, this.price);
    }
}
