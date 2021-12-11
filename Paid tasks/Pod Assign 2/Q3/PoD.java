import java.util.*;

public class PoD {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String fruitType = in.next();
        boolean peelSkin = in.nextBoolean();
        String skinColour = in.next();
        Fruit newFruit;
        
        if(fruitType.equals("PEAR")){
            newFruit = new Pear();
        }else{
            newFruit = new Lemon();
        }
        
        System.out.println("-------"+fruitType+"-------");
        System.out.println(newFruit);
        
        newFruit.setPeel(peelSkin);
        newFruit.setColour(skinColour);
        
        System.out.println("-------UPDATED-------");
        System.out.println(newFruit);
        System.out.println("END OF OUTPUT");
        
        in.close();
    }
}
