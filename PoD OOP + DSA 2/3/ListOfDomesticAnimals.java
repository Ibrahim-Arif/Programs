import java.util.*;

public class ListOfDomesticAnimals {
    public static int numberofSameFood(ArrayList<DomesticAnimal> animals, String diet){
        int total=0;
        for(int i=0; i<animals.size(); i++){
            if(animals.get(i).getDiet().equals(diet)){
                total++;
            }
        }
        return total;
    }


    public static void main(String[] args) {
        ArrayList<DomesticAnimal> animals = new ArrayList<DomesticAnimal>();
        Scanner input = new Scanner(System.in);
        String animalType = "";

        while(true){
            animalType = input.nextLine();
            if(animalType.equals("end")){
                break;
            }
            
            String data = input.nextLine();
            String[] splits = data.split(" ");

            String name = splits[0];
            String diet = splits[1];
            String breed = splits[2];
            int age = Integer.parseInt(splits[3]);
    
            if(animalType.equals("Dog")){
                Dog dog = new Dog(name, diet, age, breed);
                animals.add(dog);
            }else if(animalType.equals("Cat")){
                Cat cat = new Cat(name, diet, age, breed);
                animals.add(cat);
            }
        }

        String food = input.nextLine();
        int total=0;
        for(int i=0; i<animals.size(); i++){
            if(animals.get(i).getDiet().equals(food)){
                total++;
            }
        }
        System.out.println(total);
    }
}