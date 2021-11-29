import java.util.*;

public class PoD {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        FruitBasket fruitBasket = new FruitBasket();
        
        int i=3;
        while(i-- != 0){
            String line = in.nextLine();
            String[] fruitDetails = line.split(" ");
            
            Fruit nextFruit = new Fruit(fruitDetails[0], fruitDetails[1], Double.parseDouble(fruitDetails[2]));
            fruitBasket.addFruit(nextFruit);
        }
        
        System.out.println("--- BEFORE SORT ---");
        System.out.println(fruitBasket);
        
        Collections.sort(fruitBasket.basket);
        
        System.out.println("--- AFTER SORT ---");
        System.out.println(fruitBasket);
        
        in.close();
        System.out.println("END OF OUTPUT");
    }
}
