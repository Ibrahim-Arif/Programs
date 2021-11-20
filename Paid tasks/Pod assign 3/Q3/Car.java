public class Car {
    private String make;
    private int year;
    private String colour;
    private Engine engine;
    
    public Car(String make, int year, String colour, int engineRPM){
        engine = new Engine(engineRPM);
        this.make = make;
        this.colour = colour;
        this.year = year;
    }
    
    public Engine getEngine(){
        return this.engine;
    }
    
    public String toString(){
        return "Car: make=" + this.make + " year=" + this.year + " colour=" + this.colour;
    }
}
