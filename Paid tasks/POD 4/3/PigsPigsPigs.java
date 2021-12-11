import java.util.ArrayList;
import java.util.Collections;

public class PigsPigsPigs {
    public static void main(String[] args) {
        ArrayList<Pig> fatPigs = new ArrayList<>();
        fatPigs.add(new Pig(4, 300));
        fatPigs.add(new Pig(6, 278));
        fatPigs.add(new Pig(4, 100));
        fatPigs.add(new Pig(3, 500));
        fatPigs.add(new Pig(6, 5000));
        fatPigs.add(new Pig(1, 20));
        fatPigs.add(new Pig(1, 500));
        fatPigs.add(new Pig(8, 500));
        
        Collections.sort(fatPigs);
        
        for(Pig pig: fatPigs){
            System.out.println(pig);
        }
    }
}
