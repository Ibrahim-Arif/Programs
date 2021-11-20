import java.util.ArrayList;

public class Customer {
    private ArrayList<Dish> order = new ArrayList<Dish>();
    private String name;
    
    public Customer(String name){
        this.name = name;
    }
    
    public String getName(){
        return this.name;
    }
    
    public void addToOrder(Dish newDish){
        // add new order 
        order.add(newDish);
    }
    
    public String getOrderDescription(){
        // return orders description
        String desc = "";
        for(int i=0; i<order.size(); i++){
            desc += order.get(i).toString()+" \n";
        }
        return desc;
    }
    
    public double getOrderTotalValue(){
        // will calculate total price of all orders and return it.
        double total = 0;
        for(int i=0; i<order.size(); i++){
            total += order.get(i).getPrice();
        }
        return total;
    }
    
    public boolean equals(Customer c){
        // if names of both customers are same then return true, else return false.
        return this.name.equals(c.getName());
    }
}
