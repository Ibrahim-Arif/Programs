package Foods;
import Farm.Soil;

public class Vegetable extends Food{    
    private boolean shouldIncrease;
    
    public Vegetable(String n, double sp, int dtm, int ra){
        super(n, sp, dtm, ra);
        this.preferredSoil = Soil.Loam;
        this.shouldIncrease = true;
    }

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

