package Foods;
import Farm.Soil;

public class Fruit extends Food{
    private int skipDayNum;
    
    public Fruit(String n, double sp, int dtm, int ra){
        super(n, sp, dtm, ra);
        this.preferredSoil = Soil.Silt;
        this.skipDayNum = 0;
    }

    @Override
    public double grow(Soil s) {
        if(this.preferredSoil == s.Silt){
            this.grow();
        }else{
            this.skipDayNum += this.skipDayNum;
        }
        
        if(this.skipDayNum != 3){
            return 0;
        }
        
        this.skipDayNum = 0;
        return this.grow();
    }
}
