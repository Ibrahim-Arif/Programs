import java.util.*;

public class SailboatRunner {
    public static void main(String[] args) {
       Scanner kb = new Scanner(System.in);
       
       String name = kb.nextLine();
       String model = kb.nextLine();
       int size = kb.nextInt();
       kb.nextLine();
       
       Sailboat sb = new Sailboat(size, name, model);
       System.out.println(sb);
       
       name = kb.nextLine();
       int age = kb.nextInt();
       int yearsOffExperience = kb.nextInt();
       int registry = kb.nextInt();
       
       Captain cap = new Captain(age, name, yearsOffExperience, registry);
       sb.assignCaptain(cap);
       System.out.println(sb);
       
        System.out.println("More details about the captain:");
        System.out.println(cap);
    }
}
