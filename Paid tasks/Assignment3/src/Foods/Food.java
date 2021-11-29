package Foods;
import Farm.Soil;

public abstract class Food implements Comparable<Food> {
    private String name;
    private double sellPrice;
    private int daysToMature;
    private int requiredArea;
    private int daysSincePotted;
    protected Soil preferredSoil;
    
    public Food(String n, double sp, int dtm, int ra){
        this.name = n;
        this.sellPrice = sp;
        this.daysToMature = dtm;
        this.requiredArea = ra;
    }
    
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
    
    abstract public double grow(Soil s);
    protected double grow(){
        this.daysSincePotted++;
        
        if(this.daysSincePotted > this.daysToMature){
            return 1.00;
        }
        return (double)Math.round((this.daysSincePotted /this.daysToMature) * 100d) /100d;
    }
    
    public int compareTo(Food o) {
        if(this.getSellPrice() == o.getSellPrice()){
            return 0;
        } else if( this.getSellPrice() < o.getSellPrice()){
            return 1;
        }
        return -1;
    }
    
    public String toString(){
        return String.format("%s (%s) - %d/%d", this.name, 
                this.preferredSoil, 
                this.daysSincePotted, this.daysToMature);
    }    
}