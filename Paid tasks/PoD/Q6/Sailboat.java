public class Sailboat {
    private int size;
    private String name;
    private String model;
    private Captain captain = null;
    
    public Sailboat(int size, String name, String model){
        this.name = name;
        this.size = size;
        this.model = model;
    }
    
    public boolean assignCaptain(Captain c){
        if(this.captain == null){
            this.captain = c;
            return true;
        } else{
            if(this.captain.getYearsOfExperience() < c.getYearsOfExperience()){
                this.captain = c;
                return true;
            }else{
                return false;
            }
        }        
    }
    
    public Captain getCaptain(){
        return this.captain;
    }
    
    public boolean equals(Sailboat sb){
        if(this.name.equals(sb.name) && this.captain.getName().equals(sb.captain.getName())){
            return true;
        }else{
            return false;
        }
    }

    public String toString() {
        if(this.captain == null){
            return this.name + " is a " + this.size + " feet " + this.model + " sailboat with no captain =/";
        }else{
            return this.name + " is a " + this.size + " feet " + this.model + " sailboat; her captain is: " + this.captain.getName();
        }
    }
}
