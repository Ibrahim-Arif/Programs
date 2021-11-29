package Farm;
import Foods.Food;

public class AppleFarm extends Farm{
    public AppleFarm(int ta){
        super(ta, Soil.Loam);
    }
    
    public boolean seedFood(Food f){
        if(!f.getClass().getName().equals("Foods.Apple")){
            return false;
        }
        
        return this.seedFood(f);
    }
}
