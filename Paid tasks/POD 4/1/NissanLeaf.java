public class NissanLeaf extends Car {
    
    public NissanLeaf(int year){
        super("Nissan", "Leaf", year);
    }
    
    public void accelerate(){
        this.setSpeed(this.getSpeed() + 5);
    }
    public void brake(){
        this.setSpeed(this.getSpeed() - 2);
        
        if(this.getSpeed() < 0){
            this.setSpeed(0);
        }
    }
}
