import java.util.ArrayList;

public class Restaurant {
   private ArrayList<Dish> menu = new ArrayList<Dish>();
   private ArrayList<Table> tables = new ArrayList<Table>();
   private double totalSalesVolume;
   private String RESTAURANT_NAME;
   private int newTableNumber;
   
   public Restaurant(String name){
       this.RESTAURANT_NAME = name;
       this.totalSalesVolume = 0;
       this.newTableNumber = 1;
   }
   
   public Table getTableByNumber(int number){
       for(int i=0; i<this.tables.size(); i++){
           if(this.tables.get(i).getTableNumber() == number){
               // if table found then return that table
               return this.tables.get(i);
           }
       }

       // if table not found then return null
       return null;
   }
   
   public void addDishToMenu(String name, double price){
       // add new dish to menu
       this.menu.add(new Dish(name, price));
   }
   
   public void createTable(int size){
       // create new table
       this.tables.add(new Table(size, this.newTableNumber));
       // increate table number so that next table will get incremented number
       this.newTableNumber++;
   }
   
   public void printMenu(){
       // print menu
       for(int i=0; i<this.menu.size(); i++){
           System.out.println((i+1) + " - " + this.menu.get(i).toString());
       }
   }
   
   public void closeTable(int tableNumber){
       // closee table by number and add its revenue to restaurant total sales volume. 
       for(int i=0; i<this.tables.size(); i++){
           if(this.tables.get(i).getTableNumber() == tableNumber){
               this.totalSalesVolume += this.tables.get(i).getTotalTableRevenue();
               this.tables.remove(i);
           }
       }
   }
   
   public String toString(){
       return String.format("Restaurant %s,  night revenue so far %.2f CAD", this.RESTAURANT_NAME, this.totalSalesVolume);
   }  
}
