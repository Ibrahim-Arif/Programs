public class Banana {
    private boolean isRipe;
    private boolean isRotten;
    
    public Banana(boolean isRipe, boolean isRotten){
        this.isRipe = isRipe;
        this.isRotten = isRotten;
    }
    
    public boolean getIsRipe(){
        return this.isRipe;
    }
    
    public boolean getIsRotten(){
        return this.isRotten;
    }
    
    public void setIsRipe(boolean isRipe){
        this.isRipe = isRipe;
    }
    public void setIsRotten(boolean isRotten){
        this.isRotten = isRotten;
    }
    
    public String toString(){
        return "Banana: ripe=" + this.isRipe + " rotten=" + this.isRotten;
    }
}
