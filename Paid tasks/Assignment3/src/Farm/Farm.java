package Farm;
import Foods.Food;
import java.util.ArrayList;

public class Farm{
    private int totalArea;
    private ArrayList<Food> foods = new ArrayList<>();
    private Soil farmSoil;
    
    public Farm(int ta, Soil fs){
        this.totalArea = ta;
        this.farmSoil = fs;
    }

    public int getTotalArea() {
        return totalArea;
    }
    public Soil getFarmSoil() {
        return farmSoil;
    }
    
    public int getFoodQuantity(){
        return -1;
    }
    public Food getFood(int i){
        if(i >= foods.size()) return null;
        return foods.get(i);
    }
    public double getTotalFarmValue(){
        double total = 0;
        
        for(int i=0; i<foods.size(); i++){
            total += foods.get(i).getSellPrice();
        }
        return total;
    }
    public double getReadyToHarvestValue(){
        double total = 0; 
        
        for(int i=0; i<foods.size(); i++){
            if(foods.get(i).getDaysSincePotted() >= foods.get(i).getDaysToMature()){
                total += foods.get(i).getSellPrice();
            }
        }
        return total;
    }
    public boolean seedFood(Food f){
        if(this.totalArea < f.getRequiredArea()){
            return false;
        }
        
        foods.add(f);
        this.totalArea -= f.getRequiredArea();
        return true;
    }
    public Food harvestFood(int i){
        if(foods.get(i).getDaysSincePotted() >= foods.get(i).getDaysToMature()){
            Food temp = foods.get(i);
            foods.remove(i);
            return temp;
        }
        return null;
    }
    public void overNightGrow(){
        for(int i=0; i<foods.size(); i++){
            foods.get(i).grow(foods.get(i).getPreferredSoil());
        }
    }
    public String toString(){
        String output = String.format("Total farm value: %.2lf \nReady to harvest value: %.2lf \nFood available:", this.getTotalFarmValue(), this.getReadyToHarvestValue()); 

        for(int i=0; i<foods.size(); i++){
            output += String.format("\n%d - %s (%s) - %d/%d days", i, 
                    this.foods.get(i).getName(), 
                    this.foods.get(i).getPreferredSoil(), 
                    this.foods.get(i).getDaysSincePotted(), 
                    this.foods.get(i).getDaysToMature()
            );
        }
        
        return output;
    }
}