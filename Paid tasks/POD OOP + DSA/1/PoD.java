import java.util.*;

public class PoD{
    public static void main( String [] args ){
        Scanner in = new Scanner( System.in );
        Fridge fridge = new Fridge();
        String[] input = new String[6];
        String[] forTopShelf, forMiddleShelf, forBottomShelf;
        String takeFromTop, takeFromMiddle, takeFromBottom;

        for (int i=0; i<6; i++){
            input[i] = in.nextLine();
        }
        
        forTopShelf     = input[0].split(",");
        forMiddleShelf  = input[1].split(",");
        forBottomShelf  = input[2].split(",");
        takeFromTop     = input[3];
        takeFromMiddle  = input[4];
        takeFromBottom  = input[5];


        fridge.addGroceries(forTopShelf, fridge.topShelf);
        fridge.addGroceries(forMiddleShelf, fridge.middleShelf);
        fridge.addGroceries(forBottomShelf, fridge.bottomShelf);

        System.out.println(fridge);

        fridge.getIngredient(takeFromTop, fridge.topShelf);
        fridge.getIngredient(takeFromMiddle, fridge.middleShelf);
        fridge.getIngredient(takeFromBottom, fridge.bottomShelf);

        System.out.println(fridge);

        in.close();
        System.out.print("END OF OUTPUT");
    }
}