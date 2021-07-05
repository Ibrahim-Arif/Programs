import java.io.*;
import java.nio.file.*;
import java.util.*;
import java.util.logging.*;

public class Brain implements SEARCH_PERSON, REMOVE_PERSON{
    private static int choice;
    private static Person p = null;
    private static Scanner Oinput = new Scanner(System.in);
    private static ArrayList<Person> persons = new ArrayList<>();
    
    public static int pattern()throws InputMismatchException{
        Scanner input = new Scanner(System.in);
        System.out.print("\n1: Add a person. \n2: Search a person. \n3: Remove a person. \nEnter your choice: ");
        choice = Oinput.nextInt();
        switch(choice){
            case 1:{
                System.out.print("\n1: New Student. \n2: New Employee. \nEnter your choice: ");
                choice = input.nextInt();
                p = add_person(choice);
                boolean flag=false;
                if(p instanceof Student)
                    flag = write_person(p, "student.ser");
                else if(p instanceof Employee)
                    flag = write_person(p, "employee.ser");
                if(flag)
                    System.out.println("\nData saved!");
                break;
            }
            case 2:{
                System.out.print("\n1: Existing Student. \n2: Existing Employee. \nEnter your choice:  ");
                choice = input.nextInt();
                
                switch(choice){
                    case 1:{
                        System.out.print("\n1: Using registration. \n2: Using Grade level. \nEnter your choice: ");
                        choice = input.nextInt();
                        switch(choice){
                            case 1:{
                                System.out.print("Enter Registration number: ");
                                int id = input.nextInt();
                                p = using_id(id, "student.ser");
                                if(p != null)
                                    System.out.println("\n"+p.toString()+"\n");
                                break;
                            }
                            case 2:{
                                System.out.print("Enter Grade level: ");
                                String grade = input.next();
                                using_grade(grade);
                                break;
                            }
                        }
                        break;
                    }
                    case 2:{
                        System.out.print("Enter ID: ");
                        int id = input.nextInt();
                        p = using_id(id, "employee.ser");
                        if(p != null)
                            System.out.println("\n"+p.toString()+"\n");
                        break;
                    }
                }
                break;
            }
            case 3:{
                System.out.print("\n1: Remove a Student. \n2: Remove an Employee. \nEnter your choice:  ");
                choice = input.nextInt();
                System.out.print("Enter ID to remove: ");
                int id = input.nextInt();
                String filename = "";
                switch(choice){
                    case 1:{
                        filename = "student.ser";
                        break;
                    }
                    case 2:{
                        filename = "employee.ser";
                        break;
                    }
                }
                persons = read_objects_from_file(filename);
                boolean rem = remove_object(persons, id);
                if(write_objects_to_file(filename, persons) && rem){
                    System.out.println("\nSuccessfully removed!");
                    persons.clear();
                } else{
                    System.out.println("\nNOT FOUND!");
                }
                break;
            }
        }        
        return choice;
    }
    
    public static Person add_person(int choice) throws InputMismatchException{
        Scanner input = new Scanner(System.in);
        System.out.println("\nEnter following Data, Please.");
        
        System.out.print("Firse, last name: ");
        String fn = input.next();
        String ln = input.next();
        
        System.out.print("Phone number: ");
        String phone = input.next();
        
        System.out.print("Email: ");
        String email = input.next();
        
        System.out.println("ADDRESS (with single blankspaces).");
        System.out.print("House number, Street number, Town, city: ");
        String add = input.nextLine();
        add = input.nextLine();
        
        System.out.print("Gender: ");
        String g = input.next();
        
        switch(choice){
            case 1:{
                System.out.print("Reg no: ");
                int reg = input.nextInt();
                
                System.out.print("Fee: ");
                int fee = input.nextInt();
                
                System.out.println("--- GRADE DETAIL --- ");
                
                System.out.print("Grade Name: ");
                String gname = input.next();
                
                System.out.print("Instructor: ");
                String ins = input.next();
                
                System.out.print("Batch year: ");
                int bat = input.nextInt();
                
                System.out.print("Number of subjects: ");
                int tsubj = input.nextInt();
                
                try{
                    Grade grade = new Grade(ins, bat, tsubj, gname);
                    p = new Student(fn, ln, add, phone, email, g, reg, fee, grade);
                } catch(Exception e){
                    System.out.println("Data mismatch, input failed!!");
                }
                break;
            }
            case 2:{
                System.out.print("ID: ");
                int id = input.nextInt();
                System.out.print("Pay: ");
                double pay = input.nextDouble();
                try{
                    p = new Employee(fn, ln, add, phone, email, g, id, pay);
                } catch(Exception e){
                    System.out.println("Data mismatch, input failed!!");
                }
                break;
            }
        }
        return p;
    }
    
    public static boolean write_person(Person p, String filename){
        boolean write = false;
        try {
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(filename, true)) {
                protected void writeStreamHeader() throws IOException {
                    reset();
                }
            };
            oos.writeObject(p);
            oos.close();
            write = true;
            
        } catch (FileNotFoundException e){
            System.out.println("File not found !");
        } catch (IOException ex) {
            System.out.println("Unexpected error, Saving failed !!");
        } 
        return write;
    }
    
    public static Person using_id(int id, String filename){
        boolean found = false;
        ObjectInputStream oos = null;
        try {
            oos = new ObjectInputStream(Files.newInputStream(Paths.get(filename)));
            while(true){
                p = (Person) oos.readObject();
                if(p instanceof Student){
                    Student std = (Student) p;
                    if(std.getReg_no() == id){
                        found = true;
                        return std;
                    }
                }else if(p instanceof Employee){
                    Employee emp = (Employee) p;
                    if(emp.getId() == id){
                        found = true;
                        return emp;
                    }
                }
            }            
        } catch (EOFException e){
            if(!found)
                System.out.println("\nNOT FOUND!\n");
        } catch (IOException | ClassNotFoundException ex) {
            Logger.getLogger(Brain.class.getName()).log(Level.SEVERE, null, ex);
        } finally{
            try {
                oos.close();
            } catch (IOException ex) {
                Logger.getLogger(Brain.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        return null;
    }
    
    public static void using_grade(String grade){
        boolean found=false;
        ObjectInputStream oos = null;
        try {
            oos = new ObjectInputStream(Files.newInputStream(Paths.get("student.ser")));
            while(true){
                Student std = (Student) oos.readObject();
                if(std.getGrade().getGrade_name().equalsIgnoreCase(grade)){
                    found=true;
                    System.out.println("\n"+std.toString()+"\n");
                }
            }
        } catch (EOFException ex) {
            if(!found)
                System.out.println("\nNOT FOUND\n");
        }catch (IOException ex) {
            Logger.getLogger(Brain.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(Brain.class.getName()).log(Level.SEVERE, null, ex);
        } finally{
            try {
                oos.close();
            } catch (IOException ex) {
                Logger.getLogger(Brain.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
    public static ArrayList<Person> read_objects_from_file(String filename){
        ObjectInputStream oos = null;
        try {
            oos = new ObjectInputStream(Files.newInputStream(Paths.get(filename)));
            while(true){
                persons.add((Person) oos.readObject());
            }
            
        } catch (EOFException ex) {
            
        } catch (IOException ex) {
            Logger.getLogger(Brain.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(Brain.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                oos.close();
            } catch (IOException ex) {
                Logger.getLogger(Brain.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        return persons;
    }
    
    public static boolean remove_object(ArrayList<Person> per, int id){
        Student std = null;
        Employee emp = null;
        Person p = null;
        boolean removed = false;
        for(int i=0; i<per.size(); i++){
            p = per.get(i);
            if(p instanceof Student){
                std = (Student) p;
                if(std.getReg_no() == id){
                    per.remove(p);
                    removed = true;
                }
            } else if( p instanceof Employee){
                emp = (Employee) p;
                if(emp.getId() == id){
                    per.remove(p);
                    removed = true;
                }
            }
        }
        return removed;
    }
    
    public static boolean write_objects_to_file(String filename, ArrayList<Person> per){
        ObjectOutputStream oos = null;
        boolean removed = false;
        try {
            oos = new ObjectOutputStream(Files.newOutputStream(Paths.get(filename)));
            for(Person p: per){
                oos.writeObject(p);
            }
            oos.close();
            removed = true;
        } catch (IOException ex) {
            Logger.getLogger(Brain.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                oos.close();
            } catch (IOException ex) {
                Logger.getLogger(Brain.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        return removed;
    }
}
