import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.*;

public class WriteStudent {    
    static Student std = null;
    
    public static void add_student(){
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter name: ");
        String name = input.nextLine();
        
        System.out.print("Enter ID: ");
        String id = input.next();
        
        System.out.print("Enter fee: ");
        Double fee = input.nextDouble();
        
        System.out.print("Enter CGPA: ");
        double cgpa = input.nextDouble();
        
        System.out.print("Enter degree (graduate/undergraduate): ");
        String degree = input.next();
        
        System.out.print("Enter Semester: ");
        int sem = input.nextInt();
        
        std = new Student(name, id, fee, cgpa, degree, sem);
        write_student(std);
    }
    
    public static void write_student(Student std){
        if(std.getDegree().equalsIgnoreCase("undergraduate")){
            try {
                ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("Undergraduate.txt", true)) {
                    protected void writeStreamHeader() throws IOException {
                        reset();
                    }
                };
                oos.writeObject(std);
                oos.close();
                System.out.println("Data Saved.");
                
            } catch (Exception ex) {
                System.out.println("undergraduate student data writing, Failed!");
            }
        }
        else if(std.getDegree().equalsIgnoreCase("graduate")){
            try {
                ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("Graduate.txt", true)) {
                    protected void writeStreamHeader() throws IOException {
                        reset();
                    }
                };
                oos.writeObject(std);
                oos.close();
                System.out.println("Data Saved.");
                
            } catch (Exception ex) {
                System.out.println("Graduate student data writing, Failed!");
            }
        }
    }
}