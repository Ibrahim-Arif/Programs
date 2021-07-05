import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class menu {
    public static Scanner input = new Scanner(System.in);
    public static void pattern() throws Exception {
        System.out.print("\n1: Enter new Employee. \n2: Search an Employee. \n3: Report generator. \n4: Exit. \nEnter your choice: ");
        int choice = input.nextInt();
        
        switch(choice){
            case 1:{
                System.out.print("\n------- NEW EMPLOYEE ------- \n1: Hourly Employee. \n2: Salaried Employee. \n3: Commission Employee. \n4: Base Plus Commission Employee. \n5: Piece Worker. \nEnter your choice: ");
                choice = input.nextInt();
                System.out.println();
                add_new_employee(Employee_creator(choice));
                break;
            }
            case 2:{
                System.out.print("  1: Using name. \n  2: Using employee type. \n  3: All employee.\n  Enter your choice: ");
                choice=input.nextInt();
                switch(choice){
                    case 1:{
                        System.out.print("Enter first, last name: ");
                        search_employee(input.next(), input.next(), "", false);
                        break;
                    }
                    case 2:{
                        System.out.print("Enter employee type(same pattern): ");
                        search_employee("","", input.next(), false);
                        break;
                    }
                    case 3:{
                        search_employee("","","", true);
                        break;
                    }
                }
                break;
            }
            case 3:{
                report_generator();
                break;
            }
            case 4:{
                System.exit(0);
            }
            default:
                System.out.println("Wrong Input");
        }
    }
    
    public static Employee Employee_creator(int choice){
        System.out.print("Enter first name, last name, social security number: ");
        String fn = input.next();
        String ln = input.next();
        int ssn = input.nextInt();
        
        switch (choice) {
            case 1:
                System.out.print("Enter wage, total hours: ");
                return new HourlyEmployee(fn, ln, ssn, input.nextDouble(), input.nextDouble());
            case 2:
                System.out.print("Enter weekly salary: ");
                return new SalariedEmployee(fn, ln, ssn, input.nextDouble());
            case 3:
                System.out.print("Enter Gross sales, Commission rate: ");
                return new ComissionEmployee(fn, ln, ssn, input.nextDouble(), input.nextDouble());
            case 4:
                System.out.print("Enter Gross sales, commission rate, base salary: ");
                return new BasePlusComissionEmployee(fn, ln, ssn, input.nextDouble(), input.nextDouble(), input.nextDouble());
            case 5:
                System.out.print("Enter wage, pieces: ");
                return new PieceWorker(fn, ln, ssn, input.nextDouble(), input.nextInt());
            default:
                break;
        }
        return new HourlyEmployee("","",0,0,0);
    }
    
    public static void add_new_employee(Employee e){
        try {
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("EmployeeData.ser", true)) {
                protected void writeStreamHeader() throws IOException {
                    reset();
                }
            };
            oos.writeObject(e);
            oos.close();

        } catch (Exception ex) {
            Logger.getLogger(menu.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void search_employee(String fn, String ln, String etype, boolean all){
        boolean flag=false;
        try {
            ObjectInputStream ois = new ObjectInputStream(Files.newInputStream(Paths.get("EmployeeData.ser")));
            if(all==true){
                flag=true;
                while(true){
                    Employee emp = (Employee) ois.readObject();
                    System.out.println(emp.toString()+"\n");
                } 
            }else if(!"".equals(fn) && !"".equals(ln) && "".equals(etype)){
                while(true){
                    Employee emp = (Employee) ois.readObject();
                    if(emp.getFname().equalsIgnoreCase(fn) && emp.getLname().equalsIgnoreCase(ln)){
                        flag=true;
                        System.out.println(emp.toString()+"\n");
                    }
                }
            }else if("".equals(fn) && "".equals(ln) && !"".equals(etype)){
                while(true){
                    Employee emp = (Employee) ois.readObject();
                    if(emp.getEtype().equalsIgnoreCase(etype)){
                        System.out.println(emp.toString()+"\n");
                        flag=true;
                    }
                }
            }
        } catch (Exception ex) {
            if(flag)
                System.out.println("EOF");
        }
        if(!flag)
            System.out.println("Employee Not Found!");
    }
    
    public static void report_generator(){
        ArrayList<Employee> em = new ArrayList<Employee>();
        int heCount=0, seCount=0, ceCount=0, bpceCount=0 ,pwCount=0;
        try {
            ObjectInputStream ois = new ObjectInputStream(Files.newInputStream(Paths.get("EmployeeData.ser")));
            while(true){
                em.add((Employee) ois.readObject());
            }
        } catch (Exception ex) {
        }
        
        for(Employee e: em){
            if(e instanceof HourlyEmployee){
                heCount++;
            }else if(e instanceof SalariedEmployee){
                seCount++;
            }else if(e instanceof BasePlusComissionEmployee){
                bpceCount++;
            }else if(e instanceof ComissionEmployee){
                ceCount++;
            }else if(e instanceof PieceWorker){
                pwCount++;
            }
        }
        
        System.out.println("\nEmployee type \t\t\t\t| Number of employees");
        System.out.println("-------------------------------------------------------------");
        System.out.println("1: Hourly Employee \t\t\t|\t "+heCount);
        System.out.println("2: Salaried Employee \t\t\t|\t "+seCount);
        System.out.println("3: Commission Employee \t\t\t|\t "+ceCount);
        System.out.println("4: Base Plus Commission Employee  \t|\t "+bpceCount);
        System.out.println("5: Piece Worker \t\t\t|\t "+pwCount);
        System.out.println("-------------------------------------------------------------");
        System.out.println("Total Employee \t\t\t\t|\t "+em.size());
    }
}