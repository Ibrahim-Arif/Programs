package Farmer;
import Farm.Farm;
import Foods.Food;

public class Farmer{
    private String name;
    private int energy;
    private Farm farm;
    
    // constructor with parameter name
    public Farmer(String n){
        this.name = n;
        this.energy = 100;
        this.farm = null;
    }
    
    // constructor with params name and farm. 
    public Farmer(String n, Farm f){
        this.name = n;
        this.farm = f;
        this.energy = 100;
    }
    
    // getters 
    public Food getFoodFromFarm(int i){
        return this.farm.getFood(i);
    }
    public String getName(){
        return this.name;
    }
    public int getEnergy(){
        return this.energy;
    }
    
    // this method will increase the energy of farmer
    public void sleep(){
        this.energy += 35;
        if(this.energy > 100){
            this.energy = 100;
        }
        
        this.farm.overNightGrow();
    }
    
    // this fucntion will seed the food in the farmer's farm. 
    public boolean seedFood(Food f){
        if(f.getClass().getName().equals("Foods.Vegetable")){
            if(this.farm == null || this.energy < 30 ){
                return false;
            }
            return this.farm.seedFood(f);
        }
        else if(f.getClass().getName().equals("Foods.Fruit")){
            if(this.farm == null || this.energy < 50 ){
                return false;
            }
            return this.farm.seedFood(f);
        }
        
        return false;
    }
    
    // this function will all farmer to buy new farm 
    public boolean buyFarm(Farm f){
        if(this.farm == null){
            this.farm = f;
            return true;
        }
        
        return false;
    }
    
    // this function will return stirng represenation of farmer. 
    public String toString(){
        String output = "";
        
        output += String.format("Farmer: %s \nEnergy left: %d/100", this.name, this.energy);
        if(this.farm == null){
            output += String.format("\n%d owns no farm", this.name);
        }else{
            output += "Farm info:";
            output += this.farm.toString();
        }
        
        return output;
    }
}