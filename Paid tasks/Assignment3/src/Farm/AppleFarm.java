package Farm;
import Foods.Food;

// farm child class. 
public class AppleFarm extends Farm{
    // constructor
    public AppleFarm(int ta){
        super(ta, Soil.Loam);
    }
    
    // seed farm with apple
    public boolean seedFood(Food f){
        if(!f.getClass().getName().equals("Foods.Apple")){
            return false;
        }
        
        return this.seedFood(f);
    }
}
