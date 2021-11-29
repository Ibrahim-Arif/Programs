import java.util.*;

class Car {
    // car plate number
    private String plateNumber;
    // car maker companey
    private String make;
    // car model name
    private String model;
    // car year
    private int year;
    
    // constructor to define Car object with all the required fields. 
    public Car(String make, String model, String plateNumber, int year){
        this.plateNumber = plateNumber;
        this.make = make;
        this.model = model;
        this.year = year;
    }

    // getters
    public String getPlateNumber() {
        return plateNumber;
    }
    public String getMake() {
        return make;
    }
    public String getModel() {
        return model;
    }
    public int getYear() {
        return year;
    }
    
    // setters
    public void setPlateNumber(String plateNumber) {
        this.plateNumber = plateNumber;
    }
    public void setMake(String make) {
        this.make = make;
    }
    public void setModel(String model) {
        this.model = model;
    }
    public void setYear(int year) {
        this.year = year;
    }
    
    // this is a toString method, which will return complete information about the car. 
    public String toString(){
        return String.format("Car: (Make: %s, Model: %s, Year: %d, Plates Number: %s)", this.make, this.model, this.year, this.plateNumber);
    }   
}

class ParkingSlot {
    // assigned car to this slot
    private Car car;
    // parking slot number
    private int slotNumber;
    // is slot available?
    private boolean isAvailable;
    // number of active parking hours 
    private int activeHours;
    // charges per hours
    private int chargesPerHour;
    // parking level
    private String level;
    
    public ParkingSlot(String level, int slotNumber){
        // slot number will increase eash time a new object create
        this.slotNumber = slotNumber;
        // initially a new slot wiil be available
        this.isAvailable = true;
        // it's available, so active hours will be initially 0
        this.activeHours = 0;
        this.level = level;
        
        // level of parking slot will decide the charges per hours. 
        // high = 15$
        // normal = 10$
        // low = 5$
        switch(level){
            case "high" : {
                this.chargesPerHour = 15;
                break;
            }
            case "normal" : {
                this.chargesPerHour = 10;
                break;
            }
            case "low" : {
                this.chargesPerHour = 5;
                break;
            }
        }
    }
    
    // add car to this parking slot
    public void addCar(Car car, int activeHours){
        this.car = car;
        this.isAvailable = false;
        this.activeHours = activeHours;
    }
    // remove car from this parking slot
    public Car removeCar(){
        System.out.println("--- Removed Car ---");
        System.out.println(this.car.toString());
        System.out.println("\n");
        
        Car temp = this.car;
        this.car = null;
        this.isAvailable = true;
        this.activeHours = 0;
        
        return temp;
    }

    // getters
    public Car getCar() {
        return car;
    }
    public int getSlotNumber() {
        return slotNumber;
    }
    public int getChargesPerHour() {
        return chargesPerHour;
    }
    public int getActiveHours() {
        return activeHours;
    }
    public boolean getIsAvailable(String level) {
        return isAvailable && this.level.equals(level);
    }

    // setters
    public void setIsAvailable(boolean isAvailable) {
        this.isAvailable = isAvailable;
    }
    public void setCar(Car car) {
        this.car = car;
    }
    public void setSlotNumber(int aSlotNumber) {
        slotNumber = aSlotNumber;
    }
    public void setActiveHours(int activeHours) {
        this.activeHours = activeHours;
    }
    public void setChargesPerHour(int chargesPerHour) {
        this.chargesPerHour = chargesPerHour;
    }

    // toString method to return parking slot complete info. 
    public String toString(){
        String slot = "Parking slot: (";
        slot += "\n  Slot Number: " + this.slotNumber;
        
        if(!this.isAvailable){
            // if slot is not available
            slot += "\n  " + this.car.toString();
            slot += "\n  Active hours: " + this.activeHours;
            slot += "\n  Charges Per hour: " + this.chargesPerHour;
            slot += "\n  Total Charges: " + this.activeHours * this.chargesPerHour;
        }
        else{
            // if slot is available. 
            slot += "\n  Is Available: Yes";
            slot += "\n  Charges Per hour: " + this.chargesPerHour;
        }
        
        slot += "\n)\n";
        return slot;
    }
}

public class Main {
    // array list to store all the parking slots
    private static ArrayList<ParkingSlot> parkingSlots = new ArrayList<>();
    // array list to store the recently parked cars
    private static ArrayList<Car> history = new ArrayList<>();
    // scanner object
    private static Scanner in = new Scanner(System.in);
    
    static void initializeParkingSlots(){
        for(int i=0; i<60; i++){
            if(i < 10){
                parkingSlots.add(new ParkingSlot("high", i+1));
            }else if(i < 20){
                parkingSlots.add(new ParkingSlot("normal", i+1));
            }else{
                parkingSlots.add(new ParkingSlot("low", i+1));
            }
        }
    }
    
    static void addNewCar(){
        // get new car data
        System.out.println("Enter Car Details: ");
        System.out.print("Company: ");
        String make = in.next();
        System.out.print("Model : ");
        String model = in.next();
        System.out.print("Plates number: ");
        String platesNumber = in.next();
        System.out.print("Year: ");
        int year = in.nextInt();
        
        // get reservation related data
        System.out.println("Further information: ");
        System.out.print("Parking level (high=15$ / normal=10$ / low=5$): ");
        String level = in.next();
        System.out.print("Reservation hours: ");
        int hours = in.nextInt();
        
        boolean availableFound = false;
        // finding available slot to add new car
        for(int i=0; i<parkingSlots.size(); i++){
            if(parkingSlots.get(i).getIsAvailable(level)){
                parkingSlots.get(i).addCar(new Car(make, model, platesNumber, year), hours);
                System.out.println("\n--- Car Parked at slot number: " + parkingSlots.get(i).getSlotNumber() + " --- \n");
                availableFound = true;
                break;
            }
        }
        
        // in case no slot is empty
        if(!availableFound){
            System.out.println("--- No Available Slot Found :( ---" );
        }
    }
    
    static void removeCar(){
        System.out.print("Enter car plates number: ");
        String platesNumber = in.next();
        
        boolean found = false;
        // finding available slot to add new car
        for(int i=0; i<parkingSlots.size(); i++){
            if(parkingSlots.get(i).getCar() != null && parkingSlots.get(i).getCar().getPlateNumber().equals(platesNumber)){
                history.add(parkingSlots.get(i).getCar());
                parkingSlots.get(i).removeCar();
                found = true;
                break;
            }
        }
        
        // in case car not found
        if(!found){
            System.out.println("--- Car with plates: " + platesNumber + " does not found! ---");
        }
    }
    
    public static void main(String[] args) {
        System.out.println("\t<=== Welcome to Parking Management System ===>\n");
        int choice;
        initializeParkingSlots();
        
        do{
            System.out.println("1: Add a car. ");
            System.out.println("2: Remove a car. ");
            System.out.println("3: Parking History. ");
            System.out.println("4: Display all parked cars. ");
            System.out.println("0: Exit.");
            System.out.print("=> Enter your choice: ");
            choice = in.nextInt();
            System.out.println("");
            
            if(choice == 0){
                System.out.println("=== Exiting ===");
                break;
            }
            
            switch(choice){
                case 1:{
                    addNewCar();
                    break;
                }
                case 2:{
                    removeCar();
                    break;
                }
                case 3:{
                    // history of all past cars
                    System.out.println("--- History ---");
                    for(int i=0; i<history.size(); i++){
                        System.out.println(history.get(i).toString());
                    }
                    System.out.println("");
                    break;
                }
                case 4:{
                    // current parking
                    System.out.println("--- Current Parking ---");
                    for(int i=0; i<parkingSlots.size(); i++){
                        if(parkingSlots.get(i).getCar() != null){
                            System.out.println(parkingSlots.get(i).toString());
                        }
                    }
                    break;
                }
            }
            
        }while(choice != 0);
    }
}
