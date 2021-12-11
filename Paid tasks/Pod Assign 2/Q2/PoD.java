import java.util.*;

public class PoD {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Apple> apples = new ArrayList<>();
        ArrayList<Orange> oranges = new ArrayList<>();
        int appleWeightTotal = 0;
        int orangeWeightTotal = 0;
        
        for(int i=0; i<6; i++){
            if(i < 3){
                apples.add(new Apple(input.nextInt(), input.nextInt()));
            }else{
                oranges.add(new Orange(input.nextInt(), input.nextInt()));
            }
        }
        
        for(int i=0; i<apples.size() && i<oranges.size(); i++){
            appleWeightTotal += apples.get(i).getWeight();
            orangeWeightTotal += oranges.get(i).getWeight();
        }
        
        if(appleWeightTotal > orangeWeightTotal){
            System.out.println("The apples are heavier");
        } else if(appleWeightTotal < orangeWeightTotal){
            System.out.println("The oranges are heavier");
        } else{
            System.out.println("The apples and oranges have the same weight");
        }
    }
}
