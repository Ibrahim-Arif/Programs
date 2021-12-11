import java.io.*;
import java.nio.file.*;
import java.util.*;


public class test {
    public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException { 
        Scanner input = new Scanner(System.in);
//        File f = new File("EmployeeData.ser");
//        FileOutputStream fos  = new FileOutputStream(f,true);
//        ObjectOutputStream oos1 = new ObjectOutputStream(fos);
        ObjectOutputStream oos = new ObjectOutputStream(Files.newOutputStream(Paths.get("EmployeeData.ser")));
        ObjectInputStream ois = new ObjectInputStream(Files.newInputStream(Paths.get("EmployeeData.ser")));
        while(true){
            System.out.print("\n1- Add Employee Data to File \n2- Search Employee \n3- Exit \nEnter your choice: ");
            int choice = input.nextInt();
            if(choice == 1){                
                System.out.print("Enter name, id, hourlyIncome: ");
                employee emp = new employee(input.next(), input.nextInt(), input.nextDouble());
                oos.writeObject(emp);
            }
            else if(choice == 2){
                System.out.print("Enter name, id: ");
                String sname=input.next();
                int sid=input.nextInt();
                boolean found = false;
                try{
                    while(true){   //until EOFException
                        employee emp1 = (employee) ois.readObject();
                        if(emp1.name.equals(sname) && emp1.id==sid)
                            found=true;
                    }                    
                }
                catch(EOFException e){
                }
                if(found)
                    System.out.println("Record successfully found.");
                else
                    System.out.println("Record NOT found.");
            }
            else if(choice ==3 ){
                oos.close();
                ois.close();
                break;
            }
        }
    }
}
