public class Fruit {
    protected boolean peel;
    protected String colour;
    
    public Fruit(){
        this.peel = true;
        this.colour = null;
    }
    
    public boolean getPeel(){
        return this.peel;
    }
    public String getColour(){
        return this.colour;
    }
    
    public void setPeel(boolean peel){
        this.peel = peel;
    }
    public void setColour(String colour){
        this.colour = colour;
    }
    
    public String toString(){
        String fruitDetails = "";
        
        if(peel){
            fruitDetails += "Peel: yes, you must peel\n";
        }else{
            fruitDetails += "Peel: no, skin is edible\n";
        }
        
        fruitDetails += "Colour: " + this.colour;
        return fruitDetails;
    }
}
