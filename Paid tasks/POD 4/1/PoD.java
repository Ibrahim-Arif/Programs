import java.util.Scanner;

public class PoD {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        String carType = in.next();
        int carYear = in.nextInt();
        Car newCar;
        
        if(carType.equals("NissanLeaf")){
            newCar = new NissanLeaf(carYear);
        } else {
            String make = carType;
            String model = in.next();
            newCar = new Car(make, model, carYear);
        }
        
        for(int i=0; i<num; i++){ newCar.accelerate(); }
        for(int i=0; i<num/2; i++){ newCar.brake(); }
        
        System.out.println(newCar);
        in.close();
    }
}
