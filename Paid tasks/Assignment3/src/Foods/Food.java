package Foods;
import Farm.Soil;

public abstract class Food implements Comparable<Food> {
    private String name;
    private double sellPrice;
    private int daysToMature;
    private int requiredArea;
    private int daysSincePotted;
    protected Soil preferredSoil;
    
    
    // constructor. 
    public Food(String n, double sp, int dtm, int ra){
        this.name = n;
        this.sellPrice = sp;
        this.daysToMature = dtm;
        this.requiredArea = ra;
    }
    
    // getters
    public String getName(){
        return this.name;
    }
    public double getSellPrice(){
        return this.sellPrice;
    }
    public Soil getPreferredSoil(){
        return this.preferredSoil;
    }
    public int getDaysToMature(){
        return this.daysToMature;
    }
    public int getDaysSincePotted(){
        return this.daysSincePotted;
    }
    public int getRequiredArea(){
        return this.requiredArea;
    }
    
    // abstract grow function 
    abstract public double grow(Soil s);
    
    // this function will return the growth of food. 
    protected double grow(){
        this.daysSincePotted++;
        
        if(this.daysSincePotted > this.daysToMature){
            return 1.00;
        }
        return (double)Math.round((this.daysSincePotted /this.daysToMature) * 100d) /100d;
    }
    
    // this function will compare the food, with the param with their sell price
    public int compareTo(Food o) {
        if(this.getSellPrice() == o.getSellPrice()){
            return 0;
        } else if( this.getSellPrice() < o.getSellPrice()){
            return 1;
        }
        return -1;
    }
    
    
    // this function will return string representation of food 
    public String toString(){
        return String.format("%s (%s) - %d/%d", this.name, 
                this.preferredSoil, 
                this.daysSincePotted, this.daysToMature);
    }    
}