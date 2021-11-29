import java.util.*;

public class Fruit implements Comparable<Fruit> {
    private String name = null;
    private String colour = null;
    private double weight = 0;
    
    public Fruit(String name, String colour, double weight){
        this.name = name;
        this.colour = colour;
        this.weight = weight;
    }

    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getColour() {
        return colour;
    }
    public void setColour(String colour) {
        this.colour = colour;
    }
    public double getWeight() {
        return weight;
    }
    public void setWeight(double weight) {
        this.weight = weight;
    }
    
    public String toString(){
        String fruitDetails = name+" (colour: "+this.colour+", weight: "+this.weight+")";
        return fruitDetails;
    }
    
    public int compareTo(Fruit f){
        if(this.weight == f.getWeight()){
            return 0;
        } else if(this.weight > f.getWeight()){
            return 1;
        }
        return -1;
    }
}
