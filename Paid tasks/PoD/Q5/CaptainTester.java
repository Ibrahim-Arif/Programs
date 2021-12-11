import java.util.Scanner;

public class CaptainTester {
    public static void main(String[] args) {
       Scanner kb = new Scanner(System.in);
       
       String name = kb.nextLine();
       int age = kb.nextInt();
       int yearsOffExperience = kb.nextInt();
       int registry = kb.nextInt();
       
       Captain cap = new Captain(age, name, yearsOffExperience, registry);
       System.out.println(cap);
    }
}
