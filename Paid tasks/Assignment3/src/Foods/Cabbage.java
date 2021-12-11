package Foods;
import Farm.Soil;

// child class of vegetable
public class Cabbage extends Vegetable{
    
    // constructor 
    public Cabbage(){
        super("Cabbage", 239.75, 10, 50);
        this.preferredSoil = Soil.Clay;
    }
}