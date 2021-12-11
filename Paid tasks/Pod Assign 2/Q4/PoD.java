import java.util.*;

public class PoD {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        FruitBasket fruitBasket = new FruitBasket();
        
        while(in.hasNextLine()){
            String line = in.nextLine();
            if (line.isEmpty()) {
                break;
            }
            
            String[] fruitDetails = line.split(" ");
            
            Fruit nextFruit = new Fruit(fruitDetails[0], fruitDetails[1]);
            fruitBasket.addFruit(nextFruit);
        }
        
        System.out.println(fruitBasket);
        in.close();
        System.out.println("END OF OUTPUT");
    }
}
