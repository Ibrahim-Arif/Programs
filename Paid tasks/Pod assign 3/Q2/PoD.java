import java.util.*;

public class PoD {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        while(input.hasNext()){
            boolean ripe = input.nextBoolean();
            boolean rotten = input.nextBoolean();
            Banana b = new Banana(ripe, rotten);
            
            if(checkIfEdible(b)){
                System.out.println("This banana is edible!      " + b);
            }else{
                System.out.println("This banana is NOT edible!  " + b);
            }
        }
    }
    
    public static boolean checkIfEdible(Banana b){
        if(b.getIsRipe() && !b.getIsRotten()){
            return true;
        } else {
            return false;
        }
    }
}
