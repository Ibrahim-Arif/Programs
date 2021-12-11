public class Fruit {
    protected String colour;
    
    public Fruit(String colour){
        this.colour = colour;
    }
    
    public String getColour(){
        return this.colour;
    }
    
    public void setColour(String colour){
        this.colour = colour;
    }
    
    public String toString(){
        return "This is the toString for a fruit object! You need to override this method in any subclasses.";
    }
}
