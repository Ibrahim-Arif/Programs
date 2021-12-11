import java.util.*;

public class PoD {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Fruit> fruitBasket = new ArrayList<Fruit>();
        
        while(input.hasNext()){
            String fruitType = input.next();
            String fruitColour = input.next();
            
            if(fruitType.equals("apple")){
                int appleAge = input.nextInt();
                fruitBasket.add(new Apple(fruitColour, appleAge));
            }
            else if(fruitType.equals("banana")){
                boolean bananaRipness = input.nextBoolean();
                fruitBasket.add(new Banana(fruitColour, bananaRipness));
            }
            
            for(Fruit f : fruitBasket){
                System.out.println(f);
            }
        }
    }
}
