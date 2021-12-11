import java.io.IOException;
import java.util.*;

public class test {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        

        System.out.println("----------------------------");
        System.out.println("| SCHOOL MANAGEMANT SYSTEM |");
        System.out.println("----------------------------\n");
        System.out.print("Enter username: ");      //username: admin
        String username = input.next();
        System.out.print("Enter password: ");       //password: admin
        String password = input.next();
        
        if(username.equalsIgnoreCase("admin") && password.equalsIgnoreCase("admin")){
            try{
                while(true){
                    Brain.pattern();
                }
            } catch(InputMismatchException e){
                System.out.println("Wrong input, input failed");
                Brain.pattern();
            }
        } else{
            System.out.println("\nWrong username or password! ");
        }
    }
}