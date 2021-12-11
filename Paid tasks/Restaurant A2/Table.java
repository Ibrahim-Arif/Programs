import java.util.ArrayList;

public class Table {
    private ArrayList<Customer> seatedCustomer = new ArrayList<Customer>();
    private int size;
    private int tableNumber;

    public Table(int size, int tableNumber){
        this.size = size;
        this.tableNumber = tableNumber;
    }
    
    public int getTableNumber(){
        return this.tableNumber;
    }
    
    public boolean seatCustomer(Customer newCustomer){
        // if table if full, return false
        if(this.seatedCustomer.size() >= this.size){
            return false;
        }
        
        // if customer already exists, return false
        for(int i=0; i<this.seatedCustomer.size(); i++){
            if(this.seatedCustomer.get(i).equals(newCustomer)){
                return false;
            }
        }
        
        this.seatedCustomer.add(newCustomer);
        return true;
    }
    
    public boolean seatCustomer(ArrayList<Customer> newCustomers){
        boolean found = false;
        
        // if available seats < new customers, return false
        if(this.size - this.seatedCustomer.size() < newCustomers.size()){
            return false;
        }
        
        for(int i=0; i<newCustomers.size(); i++){
            found = false;
            
            // if customer already seated on the table, then found = true
            for(int j=0; j<this.seatedCustomer.size(); j++){
                if(this.seatedCustomer.get(j).equals(newCustomers.get(i))){
                     found = true;
                }
            }
            
            // if found is not true, then add new customer to table. 
            if(!found){
                this.seatedCustomer.add(newCustomers.get(i));
            }
        }
        
        return true;
    }
    
    public Customer findCustomerByName(String findName){
        // find customer by name
        for(int i=0; i<this.seatedCustomer.size(); i++){
            if(this.seatedCustomer.get(i).getName().equals(findName)){
                return this.seatedCustomer.get(i);
            }
        }
        
        // if not found then return null
        return null;
    }
    
    public String generateBill(boolean shouldSplit ){
        String bill =  "";
        double total = 0;
        
        // is split mode is on, then it will split the total bill into all customers
        if(shouldSplit){
            bill += "Table: " + this.tableNumber + "\n";
            for(int i=0; i<this.seatedCustomer.size(); i++){
                bill += this.seatedCustomer.get(i).getOrderDescription();
                total += this.seatedCustomer.get(i).getOrderTotalValue();
            }
            
            bill += "Total: " + total + "\n";
            bill += "Split: " + total/this.seatedCustomer.size() + "\n";
            return bill;
        }
        
        // if split mode is off, then it will create a bill, customer wise. 
        for(int i=0; i<this.seatedCustomer.size(); i++){
            bill += "Table: " + this.tableNumber + "\n";
            bill += "Customer " + this.seatedCustomer.get(i).getName() + "\n";
            bill += this.seatedCustomer.get(i).getOrderDescription();
            bill += "Total: " + this.seatedCustomer.get(i).getOrderTotalValue() + "\n";
        }
        
        return bill;
    }
    
    public double getTotalTableRevenue(){
        // will calculate total revenue of table, and return it. 
        double total = 0;
        for(int i=0; i<this.seatedCustomer.size(); i++){
            total += this.seatedCustomer.get(i).getOrderTotalValue();
        }
        return total;
    }
}

