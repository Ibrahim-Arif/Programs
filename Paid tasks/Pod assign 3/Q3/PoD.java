import java.util.*;

public class PoD {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Car> cars = new ArrayList<>();
        
        while(input.hasNext()){
            String make = input.next();
            int year = input.nextInt();
            String colour = input.next();
            int rpm = input.nextInt();
            
            cars.add(new Car(make, year, colour, rpm));
        }
        
        for(Car c : cars){
            System.out.println(c);
            System.out.println("Engine: " + c.getEngine().getRPM());
        }
        
    }
}
