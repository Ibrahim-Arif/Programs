public class Car {
    private String make;
    private String model;
    private int year;
    protected int speed;
    
    public Car(String make, String model, int year){
        this.make = make;
        this.model = model;
        this.year = year;
        this.speed = 0;
    }
    
    public String getMake(){
        return this.make;
    }
    public String getModel(){
        return this.model;
    }
    public int getSpeed(){
        return this.speed;
    }
    public int getYear(){
        return this.year;
    }
    
    public void setMake(String make){
        this.make = make;
    }
    public void setModel(String model){
        this.model = model;
    }
    public void setSpeed(int speed){
        this.speed = speed;
    }
    public void setYear(int year){
        this.year = year;
    }
    
    public void accelerate(){
        this.speed++;
    }
    public void brake(){
        this.speed--;
        if(this.speed < 0){
            this.speed = 0;
        }
    }
    
    public String toString(){
        String carDetails = "Make: " + this.make
                + "\nModel: " + this.model
                + "\nYear: " + this.year
                + "\nSpeed: " + this.speed;
        
        return carDetails;
    }
}
