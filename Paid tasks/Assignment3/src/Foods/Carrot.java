package Foods;
import Farm.Soil;


// child class of vegetable. 
public class Carrot extends Vegetable{
    public Carrot(){
        super("Carrot",  750.32, 15, 100);
        this.preferredSoil = Soil.Sand;
    }
}