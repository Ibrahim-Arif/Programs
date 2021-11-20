import java.util.*;

public class Fruit {
    protected String name = null;
    protected String colour = null;
    
    public Fruit(String name, String colour){
        this.name = name;
        this.colour = colour;
    }
    
    public String getName(){
        return this.name;
    }
    public String getColour(){
        return this.colour;
    }
    
    public void setName(String name){
        this.name = name;
    }
    public void setColour(String colour){
        this.colour = colour;
    }
    
    public String toString(){
        String fruitDetails = name + " (" + this.colour + ")";
        return fruitDetails;
    }
}
