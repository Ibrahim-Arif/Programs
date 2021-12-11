import java.io.EOFException;
import java.util.*;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.logging.Level;
import java.util.logging.Logger;


public class TerminalTest {
    private static int choice=0;
    
    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(System.in);
        while(true){
            System.out.print("\n1: Add new student. \n2: Search. \n3: Exit \nYour choice: ");
            choice = input.nextInt();
            switch(choice){
                case 1:{
                    WriteStudent.add_student();
                    break;
                }
                case 2:{
                    Pattern();
                    break;
                }
                case 3:{
                    System.exit(0);
                }
            }
        }
//         ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("Graduate.txt"));
//         ObjectOutputStream oos2 = new ObjectOutputStream(new FileOutputStream("Undergraduate.txt"));
    }
    
    public static void Pattern(){
        Scanner input = new Scanner(System.in);
        
        System.out.println("\nEnter 1 to display data of all student. "
                + "\nEnter 2 to display data of graduate students. "
                + "\nEnter 3 to display data of undergraduate students. "
                + "\nEnter 4 to display fee and stipend (if any) of graduate students. "
                + "\nEnter 5 to display fee and stipend (if any) of undergraduate students.");
        System.out.print("Enter your choice: ");
        choice = input.nextInt();
        switch(choice){
            case 1:{
                display_file("Undergraduate.txt");
                display_file("Graduate.txt");
                break;
            }
            case 2:{
                display_file("Graduate.txt");
                break;
            }
            case 3:{
                display_file("Undergraduate.txt");
                break;
            }
            case 4:{
                display_fee_structure("Graduate.txt");
                break;
            }
            case 5:{
                display_fee_structure("Undergraduate.txt");
                break;
            }
        }
    }
    
    
    public static void display_file(String filename){
        try {
            ObjectInputStream ois = new ObjectInputStream(Files.newInputStream(Paths.get(filename)));
            while(true){
                Student std = (Student) ois.readObject();
                System.out.println(std.toString());
                System.out.println("");
            }
            
        } catch (EOFException ex) {
            System.out.println("End of file.");
        } catch (IOException ex) {
            Logger.getLogger(TerminalTest.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(TerminalTest.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void display_fee_structure(String filename){
        boolean flag;
        try {
            ObjectInputStream ois = new ObjectInputStream(Files.newInputStream(Paths.get(filename)));
            while(true){
                flag=false;
                Student std = (Student) ois.readObject();
                if(std.getSemester() > 1){
                    if(PEEF.check_for_PEEF(std)){
                        PEEF.calculate_fee(std, true);
                        System.out.println("");
                        flag=true;
                        
                    }else if(flag==false && RFS.check_for_RFS(std)){
                        RFS.calculate_fee(std, true);
                        System.out.println("");
                        flag = true;
                        
                    }else if(flag==false && PWWB.check_for_PWWB(std)){
                        PWWB.calculate_fee(std, true);
                        System.out.println("");
                    }
                }
            }
            
        } catch (EOFException ex) {
            System.out.println("End of file.");
        } catch (IOException ex) {
            Logger.getLogger(TerminalTest.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(TerminalTest.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}