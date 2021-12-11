package Foods;
import Farm.Soil;

//  child class of fruit. 
public class Apple extends Fruit{
    public Apple(){
        super("Apple", 1250.00, 15, 275);
        this.preferredSoil = Soil.Loam;
    }
}