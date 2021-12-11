public class Banana extends Fruit {
    private boolean ripe;
    
    public Banana(String colour, boolean ripe){
        super(colour);
        this.ripe = ripe;
    }
    
    public boolean getRipe(){
        return this.ripe;
    }
    
    public void setRipe(boolean ripe){
        this.ripe = ripe;
    }
    
    public String toString(){
        return "Banana: colour=" + this.colour + " ripe=" + this.ripe;
    }
}
