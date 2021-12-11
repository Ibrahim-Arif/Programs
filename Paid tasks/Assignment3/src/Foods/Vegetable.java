package Foods;
import Farm.Soil;


// child class of Food.
public class Vegetable extends Food{    
    private boolean shouldIncrease;
    
    // constructor. 
    public Vegetable(String n, double sp, int dtm, int ra){
        super(n, sp, dtm, ra);
        this.preferredSoil = Soil.Loam;
        this.shouldIncrease = true;
    }
    
    // defination of abstract function 
    // this function will increase age of food, if it is in Loam soil, 
    // otherwise it will allow grow after one day. 
    @Override
    public double grow(Soil s) {
        if(this.preferredSoil == Soil.Loam){
            return this.grow();
        }else{
            this.shouldIncrease = false ;
        }
        
        if(!this.shouldIncrease){
            return 0;
        }
        
        return this.grow();
    }
}

